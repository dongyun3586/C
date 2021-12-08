#include <stdio.h>
#include <string.h>

#define MAX_COUNT 200 // 저장할 수 있는 연락처의 최대 개수

typedef struct {
	char name[30];
	char number[30];
}Person; // 연락처 구조체

int saveFile(Person* ptr, int* num); // 파일 저장
int openFile(Person* ptr, int* num); // 파일 불러옴
void addNewNumber(Person* ptr, int* num); // 새 연락처 추가
int deleteNumber(Person* ptr, int* num); // 기존 연락처 삭제
int search(Person* ptr, int* num); // 연락처 검색
void printAllNumber(Person* ptr, int* num); // 모든 연락처 출력

int main()
{
	int input; // 사용자의 메뉴 선택
	Person person[MAX_COUNT]; // 연락처 구조체
	int count = 0; // 저장되어 있는 연락처 개수 변수

	openFile(person, &count); // 파일 열기

	while (1)
	{
		printf("****** Menu ******\n");
		printf("1. Add New Number\n");
		printf("2. Delete Number\n");
		printf("3. Search Number\n");
		printf("4. Print All Number\n");
		printf("5. Save and Exit\n");
		printf("Choose the item: ");
		scanf("%d", &input);

		if (input == 1)
		{
			printf("[Add New Number]\n");
			addNewNumber(person, &count);
		}
		else if (input == 2)
		{
			printf("[Delete Number]\n");
			deleteNumber(person, &count);
		}
		else if (input == 3)
		{
			printf("[Search Number]\n");
			search(person, &count);
		}
		else if (input == 4)
		{
			printf("[Print All Number]\n");
			printAllNumber(person, &count);
		}
		else if (input == 5)
		{
			saveFile(person, &count);
			return 0;
		}
		else
			printf("Try Again!\n");
	}
	return 0;
}

int saveFile(Person* ptr, int* num)
{
	if (*num > 0)
	{
		FILE* fp = fopen("Contacts.txt", "w"); // 파일 열기, 쓰기 모드

		if (fp == NULL) // 오류 발생
		{
			printf("File Open Error!\n");
			return 1;
		}

		for (int i = 0; i < *num; i++)
		{
			fprintf(fp, "%s %s", ptr[i].name, ptr[i].number);
			fputc('\n', fp);
		} // 연락처를 파일에 입력

		if (fclose(fp) != 0) // 오류 발생
		{
			printf("File Close Error!\n");
			return 1;
		}
		printf("Data Saved.\n");
		return 0;
	}
	else
	{
		printf("Exit.\n");
		return 0;
	}
}

int openFile(Person* ptr, int* num)
{
	FILE* fp = fopen("Contacts.txt", "r"); // 파일 열기, 읽기 모드

	if (fp == NULL)
	{
		printf("File Open Error! (If you're running a program for the first time, you can ignore it.)\n");
		/* 프로그램을 처음으로 실행할 경우 처음에는 파일이 없기 때문에 fp가 NULL을 반환하여 경고 메세지가 뜬다.*/
		return 1;
	}

	while (1)
	{
		fscanf(fp, "%s %s", ptr[*num].name, ptr[*num].number);
		if (feof(fp) != 0)
			break;
		(*num)++;
	}

	if (fclose(fp) != 0) // 오류 발생
	{
		printf("File Close Error!\n");
		return 1;
	}
	return 0;
}

void addNewNumber(Person* ptr, int* num)
{
	if (*num < MAX_COUNT) // 저장되어 있는 연락처 개수가 MAX_COUNT 이하인 경우
	{
		printf("Write the Name: "); // 이름 입력
		scanf("%s", ptr[*num].name);
		printf("Write the Number: "); // 전화번호 입력
		scanf("%s", ptr[*num].number);
		(*num)++;
		printf("Data Inserted.\n\n");
	}
	else // 연락처 저장소가 다 찬 경우
		printf("Data Full.\n\n");
}

int deleteNumber(Person* ptr, int* num)
{
	char name[30];

	if (*num > 0)
	{
		printf("Write the Name: "); // 지울 연락처 이름 입력
		scanf("%s", name);

		for (int i = 0; i < MAX_COUNT; i++)
		{
			if (strcmp(name, ptr[i].name) == 0)
			{
				(*num)--; // 연락처를 지웠으므로 개수 1개 줄이기
				printf("Data Deleted.\n\n");

				if (i != MAX_COUNT - 1) // 지울 연락처가 저장소의 마지막 연락처가 아닌 경우
				{
					for (int j = i; j < MAX_COUNT - 1; j++)
					{
						strcpy(ptr[j].name, ptr[j + 1].name);
						strcpy(ptr[j].number, ptr[j + 1].number);
					} // 연락처 지운 후 한 칸씩 앞으로 땡기기
					*ptr[MAX_COUNT - 1].name = NULL;
					*ptr[MAX_COUNT - 1].number = NULL;
				}

				else // 지울 연락처가 저장소의 마지막 연락처인 경우
				{
					*ptr[MAX_COUNT - 1].name = NULL;
					*ptr[MAX_COUNT - 1].number = NULL;
				}
				return 0;
			}
		}
		printf("Not Found.\n\n"); // 데이터가 검색되지 않음
		return 0;
	}
	else
	{
		printf("No Data.\n\n"); // 저장된 데이터가 없다
		return 0;
	}
}

int search(Person* ptr, int* num)
{
	char name[30];

	if (*num > 0)
	{
		printf("Write the Name: "); // 검색할 연락처 이름 입력
		scanf("%s", name);

		for (int i = 0; i < MAX_COUNT; i++)
		{
			if (!strcmp(name, ptr[i].name))
			{
				printf("Name: %s ", ptr[i].name);
				printf("Number: %s\n", ptr[i].number);
				printf("Data Printed.\n\n");
				return 0;
			}
		}
		printf("Not found.\n\n"); // 입력한 이름과 일치하는 연락처가 없음
		return 0;
	}
	else
	{
		printf("No Data.\n\n"); // 저장된 데이터가 없음
		return 0;
	}
}

void printAllNumber(Person* ptr, int* num)
{
	if (*num > 0)
	{
		for (int i = 0; i < *num; i++)
		{
			printf("Name: %s ", ptr[i].name);
			printf("Number: %s\n", ptr[i].number);
		}
		printf("Data printed.\n\n");
	}
	else
		printf("No Data.\n\n"); // 저장된 데이터가 없음
}