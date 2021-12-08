#include <stdio.h>
#include <string.h>

#define MAX_COUNT 200 // ������ �� �ִ� ����ó�� �ִ� ����

typedef struct {
	char name[30];
	char number[30];
}Person; // ����ó ����ü

int saveFile(Person* ptr, int* num); // ���� ����
int openFile(Person* ptr, int* num); // ���� �ҷ���
void addNewNumber(Person* ptr, int* num); // �� ����ó �߰�
int deleteNumber(Person* ptr, int* num); // ���� ����ó ����
int search(Person* ptr, int* num); // ����ó �˻�
void printAllNumber(Person* ptr, int* num); // ��� ����ó ���

int main()
{
	int input; // ������� �޴� ����
	Person person[MAX_COUNT]; // ����ó ����ü
	int count = 0; // ����Ǿ� �ִ� ����ó ���� ����

	openFile(person, &count); // ���� ����

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
		FILE* fp = fopen("Contacts.txt", "w"); // ���� ����, ���� ���

		if (fp == NULL) // ���� �߻�
		{
			printf("File Open Error!\n");
			return 1;
		}

		for (int i = 0; i < *num; i++)
		{
			fprintf(fp, "%s %s", ptr[i].name, ptr[i].number);
			fputc('\n', fp);
		} // ����ó�� ���Ͽ� �Է�

		if (fclose(fp) != 0) // ���� �߻�
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
	FILE* fp = fopen("Contacts.txt", "r"); // ���� ����, �б� ���

	if (fp == NULL)
	{
		printf("File Open Error! (If you're running a program for the first time, you can ignore it.)\n");
		/* ���α׷��� ó������ ������ ��� ó������ ������ ���� ������ fp�� NULL�� ��ȯ�Ͽ� ��� �޼����� ���.*/
		return 1;
	}

	while (1)
	{
		fscanf(fp, "%s %s", ptr[*num].name, ptr[*num].number);
		if (feof(fp) != 0)
			break;
		(*num)++;
	}

	if (fclose(fp) != 0) // ���� �߻�
	{
		printf("File Close Error!\n");
		return 1;
	}
	return 0;
}

void addNewNumber(Person* ptr, int* num)
{
	if (*num < MAX_COUNT) // ����Ǿ� �ִ� ����ó ������ MAX_COUNT ������ ���
	{
		printf("Write the Name: "); // �̸� �Է�
		scanf("%s", ptr[*num].name);
		printf("Write the Number: "); // ��ȭ��ȣ �Է�
		scanf("%s", ptr[*num].number);
		(*num)++;
		printf("Data Inserted.\n\n");
	}
	else // ����ó ����Ұ� �� �� ���
		printf("Data Full.\n\n");
}

int deleteNumber(Person* ptr, int* num)
{
	char name[30];

	if (*num > 0)
	{
		printf("Write the Name: "); // ���� ����ó �̸� �Է�
		scanf("%s", name);

		for (int i = 0; i < MAX_COUNT; i++)
		{
			if (strcmp(name, ptr[i].name) == 0)
			{
				(*num)--; // ����ó�� �������Ƿ� ���� 1�� ���̱�
				printf("Data Deleted.\n\n");

				if (i != MAX_COUNT - 1) // ���� ����ó�� ������� ������ ����ó�� �ƴ� ���
				{
					for (int j = i; j < MAX_COUNT - 1; j++)
					{
						strcpy(ptr[j].name, ptr[j + 1].name);
						strcpy(ptr[j].number, ptr[j + 1].number);
					} // ����ó ���� �� �� ĭ�� ������ �����
					*ptr[MAX_COUNT - 1].name = NULL;
					*ptr[MAX_COUNT - 1].number = NULL;
				}

				else // ���� ����ó�� ������� ������ ����ó�� ���
				{
					*ptr[MAX_COUNT - 1].name = NULL;
					*ptr[MAX_COUNT - 1].number = NULL;
				}
				return 0;
			}
		}
		printf("Not Found.\n\n"); // �����Ͱ� �˻����� ����
		return 0;
	}
	else
	{
		printf("No Data.\n\n"); // ����� �����Ͱ� ����
		return 0;
	}
}

int search(Person* ptr, int* num)
{
	char name[30];

	if (*num > 0)
	{
		printf("Write the Name: "); // �˻��� ����ó �̸� �Է�
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
		printf("Not found.\n\n"); // �Է��� �̸��� ��ġ�ϴ� ����ó�� ����
		return 0;
	}
	else
	{
		printf("No Data.\n\n"); // ����� �����Ͱ� ����
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
		printf("No Data.\n\n"); // ����� �����Ͱ� ����
}