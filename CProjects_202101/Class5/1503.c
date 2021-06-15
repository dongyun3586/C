#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

int wordTotal = 0;  //단어 총개수

void printWord(char word[][50], char han[][50], int length);  //단어목록 출력
void wordTest1(char word2[][50], char han2[][50], int Wcount[], int size);  //단어시험 일반모드
void wordTest2(char word2[][50], char han2[][50], int Wcount[], int size);  //단어시험 확장모드
void cut(char word[][50], char han[][50], int Wcount[], int posi, int length);  //모든 배열에서 posi번째 요소 제거
void numCut(int num[], int posi, int length); //숫자 배열에서 posi번째 요소 제거
void sortWcount(int sortWcount[][2], int Wcount[], int length);  //틀린 횟수 많은 순서대로 정렬하는 함수


int main() {
	int modeCh; //모드 선택
	char word[50][50];  //영어단어
	char han[50][50];   //한글 뜻
	int Wcount[50] = { 0, }; //틀린횟수
	int	sWcount[50][2] = { 0, };  //틀린횟수 정렬용
	int i = 0, j = 0;
	int size;  //문제수
	char userword[50];  //사용자 입력 영단어
	char userhan[50];   //사용자 입력 한글뜻
	int usernum;  //사용자 입력 번호

	srand(time(NULL));

	//word파일에 저장된 영어단어 가져오기
	FILE* file_word;
	file_word = fopen("word.txt", "a+");
	if (NULL != file_word) {
		//word파일에서 줄단위로 문자열을 가져와 word[i]에 저장
		while (fgets(word[i], sizeof(word[0]), file_word) != NULL) {
			//printf("%s", word[i]);
			i++;
		}
		wordTotal = i;  //전체단어개수 저장
		//printf("\n단어 개수 : %d\n\n\n", wordTotal);
	}
	else {
		printf("word파일 열기에 실패했습니다.");
		return 0;
	}

	//han파일에 저장된 한글 뜻 가져오기
	FILE* file_han;
	file_han = fopen("han.txt", "a+");
	if (NULL != file_han) {
		while (fgets(han[j], sizeof(han[0]), file_han) != NULL) {
			//printf("%s", han[j]);
			j++;
		}
	}
	else {
		printf("han파일 열기에 실패했습니다.");
		return 0;
	}

	//Wcount파일에서 틀린 횟수 가져오기
	FILE* file_Wcount;
	file_Wcount = fopen("Wcount.txt", "a+");
	if (NULL != file_Wcount) {
		for (int k = 0; k < wordTotal; k++) {
			fscanf(file_Wcount, "%d", &Wcount[k]);
			//printf("%d회\n", Wcount[k]);
		}
	}
	else {
		printf("Wcount파일 열기에 실패했습니다.");
		return 0;
	}

	//Sleep(500);
	while (1) {
		system("cls");
		printf("\n\n┌──────── 영단어 테스트────────┐\n");
		printf("│                              │\n");
		printf("│        * 모드 선택 *         │\n");
		printf("│                              │\n");
		printf("│        1.단어장 편집         │\n");
		printf("│        2.단어시험            │\n");
		printf("│        3.단어목록 보기       │\n");
		printf("│                              │\n");
		printf("│                              │\n");
		printf("│        종료하려면 0입력      │\n");
		printf("│                              │\n");
		printf("└──────────────────────────────┘\n\n ");

		scanf("%d", &modeCh);

		//1.단어장편집
		if (modeCh == 1) {
			while (1) {
				system("cls");
				printf("\n-------단어장편집-------\n\n");
				printWord(word, han, wordTotal);
				printf("\n\n모드를 선택하세요\n\n");
				printf("1. 단어추가\n2. 단어삭제\n종료하려면 0 입력\n\n");
				scanf("%d", &modeCh);

				//1-1. 단어추가
				if (modeCh == 1) {
					if (wordTotal == 50) {
						printf("최대 단어 개수 50개를 초과했습니다.\n");
						Sleep(1000);
					}
					else {
						printf("영단어를 입력하세요 : ");
						scanf("%s", userword);
						fputs(userword, file_word); //word파일 끝에 사용자가 입력한 단어 추가
						fputs("\n", file_word);     //다음 추가를 위한 줄바꿈
						strcpy(word[wordTotal], strcat(userword, "\n")); // word배열에 사용자가 입력한 단어 추가 
																		 // 파일에서 가져온 단어와 형태를 똑같이
						printf("한글뜻을 입력하세요 : ");                // 해주기 위해 문자열 끝에 \n 추가
						fgets(userhan, sizeof(userhan), stdin);
						fgets(userhan, sizeof(userhan), stdin);
						fputs(userhan, file_han);
						strcpy(han[wordTotal++], userhan);

						if (wordTotal == 1) fprintf(file_Wcount, "0");
						else fprintf(file_Wcount, "\n0");  //틀린 횟수 추가
						printf("\n단어추가가 완료되었습니다.");
						Sleep(700);
					}
				}
				//1-2. 단어삭제
				else if (modeCh == 2) {
					printf("삭제할 번호를 입력하세요 : ");
					scanf("%d", &usernum);
					cut(word, han, Wcount, usernum - 1, wordTotal--); //모든배열에서 그 단어 삭제
					//파일닫기
					fclose(file_word);
					fclose(file_han);
					fclose(file_Wcount);
					//파일 다시 열어줌. w+모드이기 때문에 기존 내용 삭제, 새로 입력
					file_word = fopen("word.txt", "w+");
					file_han = fopen("han.txt", "w+");
					file_Wcount = fopen("Wcount.txt", "w+");
					for (int i = 0; i < wordTotal; i++) {
						fputs(word[i], file_word);        //파일에 사용자가 선택한 단어만 삭제한 배열 입력
						fputs(han[i], file_han);
						if (i == wordTotal - 1) {
							fprintf(file_Wcount, "%d", Wcount[i]);
							break;
						}
						fprintf(file_Wcount, "%d\n", Wcount[i]);
					}
					printf("\n단어 삭제가 완료되었습니다.");
					Sleep(1000);
				}
				//0입력 -> 단어장 편집 종료
				else if (modeCh == 0) {
					printf("단어장 편집을 종료합니다.");
					Sleep(700);
					break;
				}
				//잘못 입력
				else {
					printf("다시 입력해주세요");
					Sleep(900);
				}
			}
		}
		//2. 단어시험
		else if (modeCh == 2) {
			system("cls");
			printf("\n-------단어시험-------\n\n");
			printf("모드를 선택하세요\n\n");
			printf("1. 일반모드(영어단어 쓰기)\n2. 확장모드\n");
			scanf("%d", &modeCh);

			//2-1.일반모드
			if (modeCh == 1) {
				system("cls");
				printf("\n-----일반모드-----\n\n");
				while (1) {
					printf("문제 개수를 입력하세요 : ");
					scanf("%d", &size);
					//size범위 제한하기
					if (size > 0 && size <= wordTotal) break;
					printf("문제 개수는 %d 이하의 양수여야 합니다.\n\n", wordTotal);
				}
				Sleep(500);
				system("cls");
				wordTest1(word, han, Wcount, size);  //함수로 단어시험 실행
				//틀린횟수 업데이트
				fclose(file_Wcount);
				file_Wcount = fopen("Wcount.txt", "w+");
				for (int i = 0; i < wordTotal; i++) {
					fprintf(file_Wcount, "%d\n", Wcount[i]);
				}
				printf("\n\n처음화면으로 돌아가려면 1, 종료하려면 아무 숫자나 입력하세요\n");
				scanf("%d", &modeCh);
				if (modeCh == 1) {
					Sleep(500);
				}
				else break;
			}
			//2-2.확장모드
			else if (modeCh == 2) {
				system("cls");
				printf("\n-----확장모드-----\n\n");
				while (1) {
					printf("문제 개수를 입력하세요 : ");
					scanf("%d", &size);
					//size범위 제한하기
					if (size > 0 && size <= wordTotal) break;
					printf("문제 개수는 %d 이하의 양수여야 합니다.\n\n", wordTotal);
				}
				Sleep(500);
				system("cls");
				wordTest2(word, han, Wcount, size);  //함수로 단어시험 실행
				//틀린횟수 업데이트
				fclose(file_Wcount);
				file_Wcount = fopen("Wcount.txt", "w+");
				for (int i = 0; i < wordTotal; i++) {
					fprintf(file_Wcount, "%d\n", Wcount[i]);
				}
				printf("\n\n처음화면으로 돌아가려면 1, 종료하려면 아무 숫자나 입력하세요\n");
				scanf("%d", &modeCh);
				if (modeCh == 1) {
					Sleep(500);
				}
				else break;
			}
			//종료
			else if (modeCh == 0) break;
			//잘못 입력
			else {
				printf("잘못된 입력입니다.\n");
				Sleep(500);
			}
		}
		//3. 단어목록 보기
		else if (modeCh == 3) {
			system("cls");
			printf("\n-------단어목록-------\n\n");
			printWord(word, han, wordTotal);
			printf("\n\n처음화면으로 돌아가려면 1\n틀린단어 목록을 보려면 2, 종료하려면 아무 숫자나 입력하세요\n");
			scanf("%d", &modeCh);
			//처음화면으로 돌아가기
			if (modeCh == 1) {
				Sleep(500);
			}
			//틀린단어목록
			else if (modeCh == 2) {
				system("cls");
				printf("\n-------틀린단어목록-------\n\n");
				//for (int i = 0; i < wordTotal; i++)
					//printf("%d. %s  %s---> %d회 틀림\n\n", i + 1, word[i], han[i], Wcount[i]);
				sortWcount(sWcount, Wcount, wordTotal); //많이 틀린순으로 정렬
				for (int i = 0; i < wordTotal; i++) {
					if (sWcount[i][1] == 0) break; //틀린 횟수가 0이 되면 for문 종료
					printf("%s%s", word[sWcount[i][0]], han[sWcount[i][0]]); //sWcount[i][0]에 고유번호(위치)가 저장돼있음
					printf("--> %d회 틀림\n\n", sWcount[i][1]);  //sWcount[i][1]에 틀린 횟수가 저장돼있음
				}
				printf("\n\n처음화면으로 돌아가려면 1, 종료하려면 아무 숫자나 입력하세요\n");
				scanf("%d", &modeCh);
				if (modeCh == 1) {
					Sleep(500);
				}
				else break;
			}
			else break;
		}
		//0입력 -> 종료
		else if (modeCh == 0) {
			break;
		}
		//잘못 입력
		else {
			printf("다시 입력해주세요");
			Sleep(700);
		}
	}

	//텍스트파일 닫기
	fclose(file_word);
	fclose(file_han);
	fclose(file_Wcount);

	printf("\n프로그램을 종료합니다.");
	Sleep(500);
	return 0;
}

void printWord(char word[][50], char han[][50], int length)
{
	for (int i = 0; i < length; i++) {
		printf("%d. %s  %s", i + 1, word[i], han[i]);
	}
}

void wordTest1(char word[][50], char han[][50], int Wcount[], int size)
{
	int num[50] = { 0, };  //중복안되게 번호 뽑기 위해 사용
	int length = wordTotal;
	int a = 0, count = 0;
	char user[50];

	for (int i = 0; i < length; i++) {
		num[i] = i;  //num의 초기값은 자기 자신의 위치
	}

	for (int i = 0; i < size; i++) {
		a = rand() % length;                    // num배열에서 위치 선정 -> num[a]가 한글, 영어 배열 위치
		printf("\n%d. %s", i + 1, han[num[a]]); // 한글 뜻 배열의 num[a]번째 요소 출력
		scanf("%s", user);
		if (strcmp(word[num[a]], strcat(user, "\n")) == 0) {  //word[num[a]]와 사용자가 입력한 값 비교, 이때 word[num[a]]는 
			printf("\n정답입니다.\n");                        //끝에 "\n"이 추가되어 있어서, user에 "\n"을 결합하여 비교해야함
			Sleep(500);
			count++;
		}
		else {
			printf("\n오답입니다.\n정답: %s", word[num[a]]);
			Wcount[num[a]]++;  //틀린횟수 증가
			Sleep(1000);
		}
		numCut(num, a, length--);  //num배열에서 a번째 요소 제거 -> 중복 안되게 하기 위해
		system("cls");
	}
	printf("\n전체문제 : %2d개\n", size);
	printf("맞은개수 : %2d개\n", count);
	printf("정답률 : %0.2f%%\n", (float)count / size * 100.0);
}

void wordTest2(char word[][50], char han[][50], int Wcount[], int size)
{
	char user[50];
	int user_ans;
	int type, a = 0, abcd, count = 0, t = 1;
	int b[4] = { -1,-1,-1,-1 };
	int length = wordTotal; //배열 길이
	int num[50];
	for (int i = 0; i < length; i++) {
		num[i] = i;
	}

	for (int i = 0; i < size; i++) {
		type = rand() % 3; //3가지 유형 랜덤으로 선택

		if (type == 0) //주관식 -> 일반 모드와 똑같음
		{
			a = rand() % length;  // num배열에서 위치 선정 -> num[a]가 한글, 영어 배열 위치
			printf("\n%d. %s", i + 1, han[num[a]]); // 한글 뜻 배열의 num[a]번째 요소 출력
			scanf("%s", user);
			if (strcmp(word[num[a]], strcat(user, "\n")) == 0) {  //word[num[a]]와 사용자가 입력한 값 비교, 이때 word[num[a]]는
				printf("\n정답입니다.\n");                        //끝에 "\n"이 추가되어 있어서, user에 "\n"을 결합하여 비교해야함
				Sleep(500);
				count++;
			}
			else {
				printf("\n오답입니다.\n정답: %s", word[num[a]]);
				Wcount[num[a]]++;
				Sleep(1000);
			}
		}
		else if (type == 1) //객관식1(한글 뜻 보여주고 영단어 찾기)
		{
			a = rand() % length; //num배열에서 위치 선정 -> num[a]가 정답단어 위치
			abcd = rand() % 4;   //출력할 보기(1.2.3.4)에서 정답단어 위치 선정
			printf("\n%d.%s\n", i + 1, han[num[a]]);  //num[a]번째 한글 뜻 출력

			for (int j = 0; j < 4; j++) {
				if (j == abcd) {                            //정답단어 위치일떄
					printf("   %d.%s", j + 1, word[num[a]]);  //num[a]번째 영단어 출력
				}
				else {
					while (1) {
						t = 1; //t=1로 초기화
						b[j] = rand() % wordTotal;    //전체 단어 중 보기 단어 선정
						for (int k = 0; k < j; k++) {
							if (b[j] == b[k]) t = 0;  //먼저 출력한 보기 단어와 다른지 비교, 같은게 있으면 t=0
						}
						if (t && num[a] != b[j]) {  //t=1(다른 보기단어와 다름)이고, 정답 단어와 다르면
							printf("   %d.%s", j + 1, word[b[j]]);      //보기 단어 출력
							break;
						}
					}
				}
			}
			printf("\n");
			//사용자가 정답 입력
			scanf("%d", &user_ans);
			if (user_ans == abcd + 1) {  //사용자가 입력한 번호와 정답 위치가 같을때
				printf("\n정답입니다.");
				count++;
				Sleep(500);
			}
			else {
				printf("\n오답입니다.\n");
				printf("정답 : %d.%s", abcd + 1, word[num[a]]);
				Wcount[num[a]]++;
				Sleep(1500);
			}
		}
		else if (type == 2) //객관식2(영어 보여주고 한글뜻 찾기) -> 객관식 1에서 영어, 한글만 서로 바꾸면 됨
		{
			a = rand() % length; //num배열에서 위치 선정 -> num[a]가 정답단어 위치
			abcd = rand() % 4;   //출력할 보기(1.2.3.4)에서 정답단어 위치 선정
			printf("\n%d.%s\n", i + 1, word[num[a]]);
			for (int j = 0; j < 4; j++) {
				if (j == abcd) {      //정답단어 위치일때
					printf("   %d.%s", j + 1, han[num[a]]);
				}
				else {
					while (1) {
						t = 1;
						b[j] = rand() % wordTotal;    //전체 단어 중 보기 단어 선정
						for (int k = 0; k < j; k++) {
							if (b[j] == b[k]) t = 0;  //먼저 출력한 보기 단어와 다른지 비교, 같은게 있으면 t=0
						}
						if (t && num[a] != b[j]) {    //t=1(다른 보기단어와 다름)이고, 정답 단어와 다르면
							printf("   %d.%s", j + 1, han[b[j]]);  //보기 단어 출력
							break;
						}
					}
				}
			}
			printf("\n");
			scanf("%d", &user_ans);
			if (user_ans == abcd + 1) {  //사용자가 입력한 번호와 정답 위치가 같을때
				printf("\n정답입니다.");
				count++;
				Sleep(500);
			}
			else {
				printf("\n오답입니다.\n");
				printf("정답 : %d.%s", abcd + 1, han[num[a]]);
				Wcount[num[a]]++;
				Sleep(1500);
			}
		}
		numCut(num, a, length--);
		system("cls");
	}
	printf("\n전체문제 : %2d개\n", size);
	printf("맞은개수 : %2d개\n", count);
	printf("정답률 : %0.2f%%\n", (float)count / size * 100.0);
}

void cut(char word[][50], char han[][50], int Wcount[], int posi, int length)
{
	for (int i = posi; i < length - 1; i++) {
		strcpy(word[i], word[i + 1]);  //strcpy를 이용하여 word[i+1]의 문자열을 word[i]에 복사
		strcpy(han[i], han[i + 1]);
		Wcount[i] = Wcount[i + 1];
	}
}

void numCut(int num[], int posi, int length)
{
	for (int i = posi; i < length - 1; i++) {
		num[i] = num[i + 1];
	}
}

void sortWcount(int sWcount[][2], int Wcount[], int length)
{
	int temp;
	for (int i = 0; i < length; i++) {
		sWcount[i][0] = i;          //고유번호(처음위치)
		sWcount[i][1] = Wcount[i];  //틀린횟수
	}

	//정렬
	for (int i = 0; i < length - 1; i++) {
		for (int j = i; j < length; j++) {
			//sWcount[][1](틀린횟수)이 큰 순서대로 정렬 
			if (sWcount[i][1] < sWcount[j][1]) {
				//[][0](고유번호), [][1](틀린횟수)모두 옮기기
				temp = sWcount[i][0];
				sWcount[i][0] = sWcount[j][0];
				sWcount[j][0] = temp;
				temp = sWcount[i][1];
				sWcount[i][1] = sWcount[j][1];
				sWcount[j][1] = temp;
			}
		}
	}
}