#include<stdio.h>
#include<locale.h>
#include<windows.h>

void test(int* p1, int* p2);
int eachvalue(int a);
//글자의 획순
//'ㄱ': 2, 'ㄲ': 4, 'ㄴ': 2, 'ㄷ': 3, 'ㄸ': 6, 'ㄹ': 5, 'ㅁ': 4, 'ㅂ': 4, 'ㅃ': 8, 'ㅅ': 2, 'ㅆ': 4, 'ㅇ': 1, 'ㅈ': 3, 'ㅉ': 6, 'ㅊ': 4, 'ㅋ': 3, 'ㅌ': 4, 'ㅍ': 4, 'ㅎ': 3, 'ㄳ': 4, 'ㄵ': 5, 'ㄶ': 5, 'ㄺ': 7, 'ㄻ': 9, 'ㄼ': 9, 'ㄽ': 7, 'ㄾ': 9, 'ㄿ': 9, 'ㅀ': 8, 'ㅄ': 6, 
//'ㅏ': 2, 'ㅐ': 3, 'ㅑ': 3, 'ㅒ': 4, 'ㅓ': 2, 'ㅔ': 3, 'ㅕ': 3, 'ㅖ': 4, 'ㅗ': 2, 'ㅘ': 4, 'ㅙ': 5, 'ㅚ': 3, 'ㅛ': 3, 'ㅜ': 2, 'ㅝ': 4, 'ㅞ': 5, 'ㅟ': 3, 'ㅠ': 3, 'ㅡ': 1, 'ㅢ': 2, 'ㅣ': 1
int main() {
	int p1 = 0, p2 = 0;
	printf("****************************************이름궁합테스트****************************************");
	printf("\n\n두 사람의 이름을 자음과 모음 단위로 입력하면 두 사람의 궁합이 몇 %%인지 알 수 있습니다.\n");
	printf("만약 받침이 없으면 00을 입력하시면 됩니다.");
	Sleep(3000);
	printf("\n그러면 시작하겠습니다.");
	Sleep(2000);
	system("cls");
	test(&p1, &p2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("\n\n두 사람의 궁합은 %d", p1);
	printf("%d", p2);
	printf("%% 입니다!!");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
int eachvalue(int a) {
	int x = 0;

	if (a == 0)
		x = 0;

	switch (a) {
	case 161:
		x = 2;   //ㄱ
		break;
	case 162:    //ㄲ
		x = 4;
		break;
	case 163:    //ㄳ
		x = 4;
		break;
	case 164:    //ㄴ
		x = 2;
		break;
	case 165:    //ㄵ
		x = 5;
		break;
	case 166:    //ㄶ
		x = 5;
		break;
	case 167:    //ㄷ
		x = 3;
		break;
	case 168:     //ㄸ
		x = 6;
		break;
	case 169:     //ㄹ
		x = 5;
		break;
	case 170:
		x = 7;  //    ㄺ
		break;
	case 171:   //ㄻ
		x = 9;
		break;
	case 172:    //ㄼ
		x = 9;
		break;
	case 173:    //ㄽ
		x = 7;
		break;
	case 174:    //ㄾ
		x = 9;
		break;
	case 175:     //ㄿ
		x = 9;
		break;
	case 176:    //ㅀ
		x = 8;
		break;
	case 177:    //ㅁ
		x = 4;
		break;
	case 178:     //ㅂ
		x = 4;
		break;
	case 179:    //ㅃ
		x = 8;
		break;
	case 180:
		x = 6;   //ㅄ
		break;
	case 181:    //ㅅ
		x = 2;
		break;
	case 182:     //ㅆ
		x = 4;
		break;
	case 183:     //ㅇ
		x = 1;
		break;
	case 184:     //ㅈ
		x = 3;
		break;
	case 185:     //ㅉ
		x = 6;
		break;
	case 186:     //ㅊ
		x = 4;
		break;
	case 187:     //ㅋ
		x = 3;
		break;
	case 188:     //ㅌ
		x = 4;
		break;
	case 189:     //ㅍ
		x = 4;
		break;
	case 190:
		x = 3;     //ㅎ
		break;
	case 191:
		x = 2;    //ㅏ
		break;
	case 192:     //ㅐ
		x = 3;
		break;
	case 193:     //ㅑ
		x = 3;
		break;
	case 194:     //ㅒ
		x = 4;
		break;
	case 195:     //ㅓ
		x = 2;
		break;
	case 196:     //ㅔ
		x = 3;
		break;
	case 197:     //ㅕ
		x = 3;
		break;
	case 198:     //ㅖ
		x = 4;
		break;
	case 199:     //ㅗ
		x = 2;
		break;
	case 200:
		x = 4;    //ㅘ
		break;
	case 201:     //ㅙ
		x = 5;
		break;
	case 202:     //ㅚ
		x = 3;
		break;
	case 203:     //ㅛ
		x = 3;
		break;
	case 204:     //ㅜ
		x = 2;
		break;
	case 205:     //ㅝ
		x = 4;
		break;
	case 206:     //ㅞ
		x = 5;
		break;
	case 207:     //ㅟ
		x = 3;
		break;
	case 208:     //ㅠ
		x = 3;
		break;
	case 209:     //ㅡ
		x = 1;
		break;
	case 210:     //ㅢ
		x = 2;
		break;
	case 211:
		x = 1;    //ㅣ
		break;
	}
	return x;

	//'ㄱ': 2, 'ㄲ': 4, 'ㄴ': 2, 'ㄷ': 3, 'ㄸ': 6, 'ㄹ': 5, 'ㅁ': 4, 'ㅂ': 4, 'ㅃ': 8, 'ㅅ': 2, 'ㅆ': 4, 'ㅇ': 1, 'ㅈ': 3, 'ㅉ': 6, 'ㅊ': 4, 'ㅋ': 3, 'ㅌ': 4, 'ㅍ': 4, 'ㅎ': 3, 'ㄳ': 4, 'ㄵ': 5, 'ㄶ': 5, 'ㄺ': 7, 'ㄻ': 9, 'ㄼ': 9, 'ㄽ': 7, 'ㄾ': 9, 'ㄿ': 9, 'ㅀ': 8, 'ㅄ': 6, 
	//'ㅏ': 2, 'ㅐ': 3, 'ㅑ': 3, 'ㅒ': 4, 'ㅓ': 2, 'ㅔ': 3, 'ㅕ': 3, 'ㅖ': 4, 'ㅗ': 2, 'ㅘ': 4, 'ㅙ': 5, 'ㅚ': 3, 'ㅛ': 3, 'ㅜ': 2, 'ㅝ': 4, 'ㅞ': 5, 'ㅟ': 3, 'ㅠ': 3, 'ㅡ': 1, 'ㅢ': 2, 'ㅣ': 1
}
void test(int* p1, int* p2) {
	wchar_t s[1000];
	int arr[100] = { 0 };
	int arr1[100] = { 0 };
	int arr2[100] = { 0 };
	int arr3[100] = { 0 };
	int arr4[100] = { 0 };
	int arr5[100] = { 0 };

	printf("두 사람의 이름을 입력하세요(한 번에 말고 각 글자별로,만약 받침이 없으면 00입력)\n");
	wscanf(L"%s", s);

	for (int i = 0; i < 18; i++) {
		arr[i] = (int)s[2 * i + 1];
	}

	arr1[0] = eachvalue(arr[0]) + eachvalue(arr[1]) + eachvalue(arr[2]);          //초성, 중성, 종성 한 단어로 획순 합치기
	arr1[1] = eachvalue(arr[9]) + eachvalue(arr[10]) + eachvalue(arr[11]);
	arr1[2] = eachvalue(arr[3]) + eachvalue(arr[4]) + eachvalue(arr[5]);
	arr1[3] = eachvalue(arr[12]) + eachvalue(arr[13]) + eachvalue(arr[14]);
	arr1[4] = eachvalue(arr[6]) + eachvalue(arr[7]) + eachvalue(arr[8]);
	arr1[5] = eachvalue(arr[15]) + eachvalue(arr[16]) + eachvalue(arr[17]);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("\n%d\t%d\t%d\t%d\t%d\t%d", arr1[0], arr1[1], arr1[2], arr1[3], arr1[4], arr1[5]);      //첫 번째 단계 출력

	for (int i = 0; i < 5; i++) {
		arr2[i] = (arr1[i] + arr1[i + 1]) % 10;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("\n\n    %d       %d       %d       %d       %d", arr2[0], arr2[1], arr2[2], arr2[3], arr2[4]);    //두 번째 단계 출력

	for (int i = 0; i < 4; i++) {
		arr3[i] = (arr2[i] + arr2[i + 1]) % 10;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);      //세 번째 단계 출력
	printf("\n\n\t%d\t%d\t%d\t%d", arr3[0], arr3[1], arr3[2], arr3[3]);

	for (int i = 0; i < 3; i++) {
		arr4[i] = (arr3[i] + arr3[i + 1]) % 10;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("\n\n\t    %d       %d       %d", arr4[0], arr4[1], arr4[2]);        //네 번째 단계 출력

	for (int i = 0; i < 2; i++) {
		arr5[i] = (arr4[i] + arr4[i + 1]) % 10;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("\n\n\t\t%d\t%d\n", arr5[0], arr5[1]);         //다섯 번째 단계 출력
	*p1 = arr5[0];
	*p2 = arr5[1];
}
