#include<stdio.h>
#include<locale.h>
#include<windows.h>

void test(int* p1, int* p2);
int eachvalue(int a);
//������ ȹ��
//'��': 2, '��': 4, '��': 2, '��': 3, '��': 6, '��': 5, '��': 4, '��': 4, '��': 8, '��': 2, '��': 4, '��': 1, '��': 3, '��': 6, '��': 4, '��': 3, '��': 4, '��': 4, '��': 3, '��': 4, '��': 5, '��': 5, '��': 7, '��': 9, '��': 9, '��': 7, '��': 9, '��': 9, '��': 8, '��': 6, 
//'��': 2, '��': 3, '��': 3, '��': 4, '��': 2, '��': 3, '��': 3, '��': 4, '��': 2, '��': 4, '��': 5, '��': 3, '��': 3, '��': 2, '��': 4, '��': 5, '��': 3, '��': 3, '��': 1, '��': 2, '��': 1
int main() {
	int p1 = 0, p2 = 0;
	printf("****************************************�̸������׽�Ʈ****************************************");
	printf("\n\n�� ����� �̸��� ������ ���� ������ �Է��ϸ� �� ����� ������ �� %%���� �� �� �ֽ��ϴ�.\n");
	printf("���� ��ħ�� ������ 00�� �Է��Ͻø� �˴ϴ�.");
	Sleep(3000);
	printf("\n�׷��� �����ϰڽ��ϴ�.");
	Sleep(2000);
	system("cls");
	test(&p1, &p2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("\n\n�� ����� ������ %d", p1);
	printf("%d", p2);
	printf("%% �Դϴ�!!");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
int eachvalue(int a) {
	int x = 0;

	if (a == 0)
		x = 0;

	switch (a) {
	case 161:
		x = 2;   //��
		break;
	case 162:    //��
		x = 4;
		break;
	case 163:    //��
		x = 4;
		break;
	case 164:    //��
		x = 2;
		break;
	case 165:    //��
		x = 5;
		break;
	case 166:    //��
		x = 5;
		break;
	case 167:    //��
		x = 3;
		break;
	case 168:     //��
		x = 6;
		break;
	case 169:     //��
		x = 5;
		break;
	case 170:
		x = 7;  //    ��
		break;
	case 171:   //��
		x = 9;
		break;
	case 172:    //��
		x = 9;
		break;
	case 173:    //��
		x = 7;
		break;
	case 174:    //��
		x = 9;
		break;
	case 175:     //��
		x = 9;
		break;
	case 176:    //��
		x = 8;
		break;
	case 177:    //��
		x = 4;
		break;
	case 178:     //��
		x = 4;
		break;
	case 179:    //��
		x = 8;
		break;
	case 180:
		x = 6;   //��
		break;
	case 181:    //��
		x = 2;
		break;
	case 182:     //��
		x = 4;
		break;
	case 183:     //��
		x = 1;
		break;
	case 184:     //��
		x = 3;
		break;
	case 185:     //��
		x = 6;
		break;
	case 186:     //��
		x = 4;
		break;
	case 187:     //��
		x = 3;
		break;
	case 188:     //��
		x = 4;
		break;
	case 189:     //��
		x = 4;
		break;
	case 190:
		x = 3;     //��
		break;
	case 191:
		x = 2;    //��
		break;
	case 192:     //��
		x = 3;
		break;
	case 193:     //��
		x = 3;
		break;
	case 194:     //��
		x = 4;
		break;
	case 195:     //��
		x = 2;
		break;
	case 196:     //��
		x = 3;
		break;
	case 197:     //��
		x = 3;
		break;
	case 198:     //��
		x = 4;
		break;
	case 199:     //��
		x = 2;
		break;
	case 200:
		x = 4;    //��
		break;
	case 201:     //��
		x = 5;
		break;
	case 202:     //��
		x = 3;
		break;
	case 203:     //��
		x = 3;
		break;
	case 204:     //��
		x = 2;
		break;
	case 205:     //��
		x = 4;
		break;
	case 206:     //��
		x = 5;
		break;
	case 207:     //��
		x = 3;
		break;
	case 208:     //��
		x = 3;
		break;
	case 209:     //��
		x = 1;
		break;
	case 210:     //��
		x = 2;
		break;
	case 211:
		x = 1;    //��
		break;
	}
	return x;

	//'��': 2, '��': 4, '��': 2, '��': 3, '��': 6, '��': 5, '��': 4, '��': 4, '��': 8, '��': 2, '��': 4, '��': 1, '��': 3, '��': 6, '��': 4, '��': 3, '��': 4, '��': 4, '��': 3, '��': 4, '��': 5, '��': 5, '��': 7, '��': 9, '��': 9, '��': 7, '��': 9, '��': 9, '��': 8, '��': 6, 
	//'��': 2, '��': 3, '��': 3, '��': 4, '��': 2, '��': 3, '��': 3, '��': 4, '��': 2, '��': 4, '��': 5, '��': 3, '��': 3, '��': 2, '��': 4, '��': 5, '��': 3, '��': 3, '��': 1, '��': 2, '��': 1
}
void test(int* p1, int* p2) {
	wchar_t s[1000];
	int arr[100] = { 0 };
	int arr1[100] = { 0 };
	int arr2[100] = { 0 };
	int arr3[100] = { 0 };
	int arr4[100] = { 0 };
	int arr5[100] = { 0 };

	printf("�� ����� �̸��� �Է��ϼ���(�� ���� ���� �� ���ں���,���� ��ħ�� ������ 00�Է�)\n");
	wscanf(L"%s", s);

	for (int i = 0; i < 18; i++) {
		arr[i] = (int)s[2 * i + 1];
	}

	arr1[0] = eachvalue(arr[0]) + eachvalue(arr[1]) + eachvalue(arr[2]);          //�ʼ�, �߼�, ���� �� �ܾ�� ȹ�� ��ġ��
	arr1[1] = eachvalue(arr[9]) + eachvalue(arr[10]) + eachvalue(arr[11]);
	arr1[2] = eachvalue(arr[3]) + eachvalue(arr[4]) + eachvalue(arr[5]);
	arr1[3] = eachvalue(arr[12]) + eachvalue(arr[13]) + eachvalue(arr[14]);
	arr1[4] = eachvalue(arr[6]) + eachvalue(arr[7]) + eachvalue(arr[8]);
	arr1[5] = eachvalue(arr[15]) + eachvalue(arr[16]) + eachvalue(arr[17]);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("\n%d\t%d\t%d\t%d\t%d\t%d", arr1[0], arr1[1], arr1[2], arr1[3], arr1[4], arr1[5]);      //ù ��° �ܰ� ���

	for (int i = 0; i < 5; i++) {
		arr2[i] = (arr1[i] + arr1[i + 1]) % 10;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("\n\n    %d       %d       %d       %d       %d", arr2[0], arr2[1], arr2[2], arr2[3], arr2[4]);    //�� ��° �ܰ� ���

	for (int i = 0; i < 4; i++) {
		arr3[i] = (arr2[i] + arr2[i + 1]) % 10;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);      //�� ��° �ܰ� ���
	printf("\n\n\t%d\t%d\t%d\t%d", arr3[0], arr3[1], arr3[2], arr3[3]);

	for (int i = 0; i < 3; i++) {
		arr4[i] = (arr3[i] + arr3[i + 1]) % 10;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("\n\n\t    %d       %d       %d", arr4[0], arr4[1], arr4[2]);        //�� ��° �ܰ� ���

	for (int i = 0; i < 2; i++) {
		arr5[i] = (arr4[i] + arr4[i + 1]) % 10;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("\n\n\t\t%d\t%d\n", arr5[0], arr5[1]);         //�ټ� ��° �ܰ� ���
	*p1 = arr5[0];
	*p2 = arr5[1];
}
