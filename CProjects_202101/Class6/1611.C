#include<stdio.h>
#include<limits.h>// INT_,MAX�� ����ϱ� ���Ѥ� ���̺귯�� ����.
typedef struct CompressionBits// ������ �޸𸮸� ��Ʈ���� ������ ����ü��. ���� ����Ʈ�� C ��� �ڵ� ������ �����ߴ�.
{
    struct CompressionBits* next; //���� ����Ʈ�� ������ �� ���� ���ͳ��� ����߽��ϴ�.
    short num1;
}compressionbits;
// ������ ���� ����
int RecentBit = 0; // 2�� ���� �������� �����ϴ� ��.
int NumberOfStruct = 0;// ����ü�� ����
int SaveCount = 0;/* FileCompresison���� ReverseNumber�� ����ؼ� Count�� �������Ƿ�, ������ �� Count�� ������ ������ �����ߴ�.*/
int Count = 0;//���ӵ� ��Ʈ ������ �����ϴ� ����.
int BitOfEscapeCharacter = 0; // EXCAPE ������ ������ ��Ÿ���� �Լ�.
//������ �Լ� ����
char ASCIIReverse(char ch);
int ReverseNumber(int num); // 10���� ���� ������ �Լ�.
void FileCompression(int num, compressionbits* head); // file������ �ؼ� ���� ����ü�� �����ϴ� �Լ�.
void addNode(struct NODE* target, int data); // NODE�� �����ϴ� �Լ�.
int main()
{
    int length; // �Է��� ���ڿ��� ����
    printf("���ڿ� ���� ���α׷��� ���� �� ȯ���մϴ�.\n");
    printf("�Է��� ������ ������ �Է��ϼ���:\n");
    scanf("%d", &length);
    if (length <1 || length > INT_MAX)
    {
        printf("�� �Ǽ��� �̰� ����ȵǿ�. byebye~");
    }
    char arr[length];
    int i = 0;
    printf("*�� ������ ���ڸ� �Է��ϼ���.");
    int BitsOfInput = 8 * length; /* 1����Ʈ ũ��� �Է��� ���ڿ��� ��Ʈ ũ��� �ٲ� ��. */
    while (i < length)
    {
        scanf("%c", &arr[i]);
        if (arr[i] == '*')
        {
            printf("�� ����  �� ������ ����! ");// Run Length Algorithm�� ���ڿ� ���� ����� ���� escape���ڷ� '*'�� ����ߴ�. '*'�� �Է��ϸ� ���α׷��� ����ȴ�.
            printf("�ʰ� �߸� �ļ� ������ �ȵ��ݾ�.");
            return 0;
        }
        ++i;
    }
    int a = 0;
    while (a < length)
    {
        arr[a] = ASCIIReverse(arr[a]);
        a++;
    }
    printf("\n");
    compressionbits* head = (compressionbits*)malloc(sizeof(compressionbits));// ���� ����Ʈ�� ����� �����ߴ�.
    int k = 0;
    while (k < length)// file �����ϴ� �κ�.
    {
        FileCompression(arr[k], head);
        k++;
    }
    printf("�����: %f\n", (float)(NumberOfStruct - BitOfEscapeCharacter) / BitsOfInput);/* ����Ǳ� �� �迭�� ����� ��Ʈ ����,
    ����� �� �������� ����� ��Ʈ ���� �� ����ϴ� ��8���̴�. */
    printf("�ۼ�Ʈ�� �ٲ��ڸ� %f%%�̴�.", 100 * (float)(NumberOfStruct - BitOfEscapeCharacter) / BitsOfInput);

    struct compressionbits* curr = head->next;
    free(head);//
    return 0;// ������� �ؼ� main�Լ��� ����ȴ�.4

}
int ReverseNumber(int num) // ���� �� �������� ������ ����� �Լ��̴�.
{
    int j = 0;
    while (num != 0)
    {
        j = j * 10 + (num % 10);
        num = num / 10;
    }
    return j;
}
char ASCIIReverse(char ch)
{
    int j = 0;
    char ch1 = 0;
    while (j < 8)
    {
        ch1 = ch1 * 2 + ch % 2;
        ch = ch / 2;
        j++;
    }
    return ch1;
}
void addFirst(compressionbits* target, short num1)    /*���� ��� �ڿ� ��带 �߰��ϴ� �Լ�.
�� �Լ��� �ڵ����� ��� �����ϱ��� �����ؼ� �ۼ��߽��ϴ�.*/
{
    compressionbits* NewCompressionBits = (compressionbits*)malloc(sizeof(compressionbits));    // �� ��� ����
    NewCompressionBits->next = target->next;    // �� ����� ���� ��忡 ���� ����� ���� ��带 ����
    NewCompressionBits->num1 = num1;            // ������ ����
    target->next = NewCompressionBits;    // ���� ����� ���� ��忡 �� ��带 ����
}
void FileCompression(int num, compressionbits* head) /* ���Ͼ����� �ϴ� �Լ� */
{
    int i = 0;

    char ch = '*';
    while (i < sizeof(char))
    {
        if (RecentBit != num % 2)// ����  ����Ǿ��� ��Ʈ�� ���� ������ ������ ����  ��Ʈ�� �ٸ� �� Ȯ���ϴ� �Լ�.
        {
            RecentBit = num % 2;// RecentBit�� �ֱ� ��Ʈ�� �����Ѵ�.
            SaveCount = Count;
            Count = ReverseNumber(Count); // COUNT�� ���� �����´�.
            while (SaveCount != 0)
            {
                addFirst(head, Count % 2);// ���� ����Ʈ�� �߰��ϴ� �Լ��̴�.
                NumberOfStruct++;// ��Ʈ ����  �ø��� �Ŵ�.
                SaveCount = SaveCount / 2;
                Count = Count / 2;
                NumberOfStruct++;
            }
            Count = 0;
            int j = 0;
            while (j < sizeof(char))
            {
                addFirst(head, ch % 2);
                ch = ch / 2;
                NumberOfStruct++;// ��Ʈ �� ����.
                BitOfEscapeCharacter++; // escape ��answk
                j++;
            }
        }
        else
        {
            ++Count; // ������  ��Ʈ  �� ����.
        }
        num = num / 2;
        i++;
    }
}