#include<stdio.h>
#include<limits.h>// INT_,MAX를 사용하기 위한ㅇ 라이브러리 선언.
typedef struct CompressionBits// 압축한 메모리를 비트별로 저장할 구조체다. 연결 리스트는 C 언어 코딩 도장을 암조했다.
{
    struct CompressionBits* next; //연결 리스트의 개념을 잘 몰라 인터넷을 사용했습니다.
    short num1;
}compressionbits;
// 선언한 변수 설명
int RecentBit = 0; // 2로 나눈 나머지를 저장하는 값.
int NumberOfStruct = 0;// 구조체의 개수
int SaveCount = 0;/* FileCompresison에서 ReverseNumber를 사용해서 Count를 뒤집으므로, 뒤집기 전 Count를 저장할 공간을 선언했다.*/
int Count = 0;//연속된 비트 개수를 저장하는 변수.
int BitOfEscapeCharacter = 0; // EXCAPE 문자의 개수를 나타내는 함수.
//선언한 함수 설명
char ASCIIReverse(char ch);
int ReverseNumber(int num); // 10진수 값을 뒤집는 함수.
void FileCompression(int num, compressionbits* head); // file압축을 해서 값을 구조체에 저장하는 함수.
void addNode(struct NODE* target, int data); // NODE를 선언하는 함수.
int main()
{
    int length; // 입력할 문자열의 개수
    printf("문자열 압축 프로그램에 오신 걸 환영합니다.\n");
    printf("입력할 문자의 개수를 입력하세요:\n");
    scanf("%d", &length);
    if (length <1 || length > INT_MAX)
    {
        printf("님 실수로 이건 실행안되요. byebye~");
    }
    char arr[length];
    int i = 0;
    printf("*을 제외한 문자를 입력하세요.");
    int BitsOfInput = 8 * length; /* 1바이트 크기로 입력한 문자열을 비트 크기로 바꾼 값. */
    while (i < length)
    {
        scanf("%c", &arr[i]);
        if (arr[i] == '*')
        {
            printf("내 말좀  잘 들으라 했지! ");// Run Length Algorithm의 문자열 구분 기능을 위한 escape문자로 '*'을 사용했다. '*'을 입력하면 프로그램이 종료된다.
            printf("너가 잘못 쳐서 압축이 안됐잖아.");
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
    compressionbits* head = (compressionbits*)malloc(sizeof(compressionbits));// 연결 리스트의 헤더를 선언했다.
    int k = 0;
    while (k < length)// file 압축하는 부분.
    {
        FileCompression(arr[k], head);
        k++;
    }
    printf("압축률: %f\n", (float)(NumberOfStruct - BitOfEscapeCharacter) / BitsOfInput);/* 압축되기 전 배열에 저장된 비트 수와,
    압축된 후 구초제에 저장뒨 비트 수의 비를 출력하는 함8수이다. */
    printf("퍼센트로 바꾸자면 %f%%이다.", 100 * (float)(NumberOfStruct - BitOfEscapeCharacter) / BitsOfInput);

    struct compressionbits* curr = head->next;
    free(head);//
    return 0;// 여기까지 해서 main함수가 종료된다.4

}
int ReverseNumber(int num) // 변수 안 십진수를 뒤집는 기능의 함수이다.
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
void addFirst(compressionbits* target, short num1)    /*기준 노드 뒤에 노드를 추가하는 함수.
이 함수는 코딩도장 노드 삽입하기을 참고해서 작성했습니다.*/
{
    compressionbits* NewCompressionBits = (compressionbits*)malloc(sizeof(compressionbits));    // 새 노드 생성
    NewCompressionBits->next = target->next;    // 새 노드의 다음 노드에 기준 노드의 다음 노드를 지정
    NewCompressionBits->num1 = num1;            // 데이터 저장
    target->next = NewCompressionBits;    // 기준 노드의 다음 노드에 새 노드를 지정
}
void FileCompression(int num, compressionbits* head) /* 파일압축을 하는 함수 */
{
    int i = 0;

    char ch = '*';
    while (i < sizeof(char))
    {
        if (RecentBit != num % 2)// 전의  저장되었던 비트와 현재 나머지 연산을 취한  비트가 다른 지 확인하는 함수.
        {
            RecentBit = num % 2;// RecentBit로 최근 비트를 저장한다.
            SaveCount = Count;
            Count = ReverseNumber(Count); // COUNT의 값을 뒤집는다.
            while (SaveCount != 0)
            {
                addFirst(head, Count % 2);// 연결 리스트를 추가하는 함수이다.
                NumberOfStruct++;// 비트 수를  늘리는 거다.
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
                NumberOfStruct++;// 비트 수 증가.
                BitOfEscapeCharacter++; // escape ㅁanswk
                j++;
            }
        }
        else
        {
            ++Count; // 연속한  비트  수 증가.
        }
        num = num / 2;
        i++;
    }
}
