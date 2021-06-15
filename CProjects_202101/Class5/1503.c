#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

int wordTotal = 0;  //�ܾ� �Ѱ���

void printWord(char word[][50], char han[][50], int length);  //�ܾ��� ���
void wordTest1(char word2[][50], char han2[][50], int Wcount[], int size);  //�ܾ���� �Ϲݸ��
void wordTest2(char word2[][50], char han2[][50], int Wcount[], int size);  //�ܾ���� Ȯ����
void cut(char word[][50], char han[][50], int Wcount[], int posi, int length);  //��� �迭���� posi��° ��� ����
void numCut(int num[], int posi, int length); //���� �迭���� posi��° ��� ����
void sortWcount(int sortWcount[][2], int Wcount[], int length);  //Ʋ�� Ƚ�� ���� ������� �����ϴ� �Լ�


int main() {
	int modeCh; //��� ����
	char word[50][50];  //����ܾ�
	char han[50][50];   //�ѱ� ��
	int Wcount[50] = { 0, }; //Ʋ��Ƚ��
	int	sWcount[50][2] = { 0, };  //Ʋ��Ƚ�� ���Ŀ�
	int i = 0, j = 0;
	int size;  //������
	char userword[50];  //����� �Է� ���ܾ�
	char userhan[50];   //����� �Է� �ѱ۶�
	int usernum;  //����� �Է� ��ȣ

	srand(time(NULL));

	//word���Ͽ� ����� ����ܾ� ��������
	FILE* file_word;
	file_word = fopen("word.txt", "a+");
	if (NULL != file_word) {
		//word���Ͽ��� �ٴ����� ���ڿ��� ������ word[i]�� ����
		while (fgets(word[i], sizeof(word[0]), file_word) != NULL) {
			//printf("%s", word[i]);
			i++;
		}
		wordTotal = i;  //��ü�ܾ�� ����
		//printf("\n�ܾ� ���� : %d\n\n\n", wordTotal);
	}
	else {
		printf("word���� ���⿡ �����߽��ϴ�.");
		return 0;
	}

	//han���Ͽ� ����� �ѱ� �� ��������
	FILE* file_han;
	file_han = fopen("han.txt", "a+");
	if (NULL != file_han) {
		while (fgets(han[j], sizeof(han[0]), file_han) != NULL) {
			//printf("%s", han[j]);
			j++;
		}
	}
	else {
		printf("han���� ���⿡ �����߽��ϴ�.");
		return 0;
	}

	//Wcount���Ͽ��� Ʋ�� Ƚ�� ��������
	FILE* file_Wcount;
	file_Wcount = fopen("Wcount.txt", "a+");
	if (NULL != file_Wcount) {
		for (int k = 0; k < wordTotal; k++) {
			fscanf(file_Wcount, "%d", &Wcount[k]);
			//printf("%dȸ\n", Wcount[k]);
		}
	}
	else {
		printf("Wcount���� ���⿡ �����߽��ϴ�.");
		return 0;
	}

	//Sleep(500);
	while (1) {
		system("cls");
		printf("\n\n������������������ ���ܾ� �׽�Ʈ������������������\n");
		printf("��                              ��\n");
		printf("��        * ��� ���� *         ��\n");
		printf("��                              ��\n");
		printf("��        1.�ܾ��� ����         ��\n");
		printf("��        2.�ܾ����            ��\n");
		printf("��        3.�ܾ��� ����       ��\n");
		printf("��                              ��\n");
		printf("��                              ��\n");
		printf("��        �����Ϸ��� 0�Է�      ��\n");
		printf("��                              ��\n");
		printf("����������������������������������������������������������������\n\n ");

		scanf("%d", &modeCh);

		//1.�ܾ�������
		if (modeCh == 1) {
			while (1) {
				system("cls");
				printf("\n-------�ܾ�������-------\n\n");
				printWord(word, han, wordTotal);
				printf("\n\n��带 �����ϼ���\n\n");
				printf("1. �ܾ��߰�\n2. �ܾ����\n�����Ϸ��� 0 �Է�\n\n");
				scanf("%d", &modeCh);

				//1-1. �ܾ��߰�
				if (modeCh == 1) {
					if (wordTotal == 50) {
						printf("�ִ� �ܾ� ���� 50���� �ʰ��߽��ϴ�.\n");
						Sleep(1000);
					}
					else {
						printf("���ܾ �Է��ϼ��� : ");
						scanf("%s", userword);
						fputs(userword, file_word); //word���� ���� ����ڰ� �Է��� �ܾ� �߰�
						fputs("\n", file_word);     //���� �߰��� ���� �ٹٲ�
						strcpy(word[wordTotal], strcat(userword, "\n")); // word�迭�� ����ڰ� �Է��� �ܾ� �߰� 
																		 // ���Ͽ��� ������ �ܾ�� ���¸� �Ȱ���
						printf("�ѱ۶��� �Է��ϼ��� : ");                // ���ֱ� ���� ���ڿ� ���� \n �߰�
						fgets(userhan, sizeof(userhan), stdin);
						fgets(userhan, sizeof(userhan), stdin);
						fputs(userhan, file_han);
						strcpy(han[wordTotal++], userhan);

						if (wordTotal == 1) fprintf(file_Wcount, "0");
						else fprintf(file_Wcount, "\n0");  //Ʋ�� Ƚ�� �߰�
						printf("\n�ܾ��߰��� �Ϸ�Ǿ����ϴ�.");
						Sleep(700);
					}
				}
				//1-2. �ܾ����
				else if (modeCh == 2) {
					printf("������ ��ȣ�� �Է��ϼ��� : ");
					scanf("%d", &usernum);
					cut(word, han, Wcount, usernum - 1, wordTotal--); //���迭���� �� �ܾ� ����
					//���ϴݱ�
					fclose(file_word);
					fclose(file_han);
					fclose(file_Wcount);
					//���� �ٽ� ������. w+����̱� ������ ���� ���� ����, ���� �Է�
					file_word = fopen("word.txt", "w+");
					file_han = fopen("han.txt", "w+");
					file_Wcount = fopen("Wcount.txt", "w+");
					for (int i = 0; i < wordTotal; i++) {
						fputs(word[i], file_word);        //���Ͽ� ����ڰ� ������ �ܾ ������ �迭 �Է�
						fputs(han[i], file_han);
						if (i == wordTotal - 1) {
							fprintf(file_Wcount, "%d", Wcount[i]);
							break;
						}
						fprintf(file_Wcount, "%d\n", Wcount[i]);
					}
					printf("\n�ܾ� ������ �Ϸ�Ǿ����ϴ�.");
					Sleep(1000);
				}
				//0�Է� -> �ܾ��� ���� ����
				else if (modeCh == 0) {
					printf("�ܾ��� ������ �����մϴ�.");
					Sleep(700);
					break;
				}
				//�߸� �Է�
				else {
					printf("�ٽ� �Է����ּ���");
					Sleep(900);
				}
			}
		}
		//2. �ܾ����
		else if (modeCh == 2) {
			system("cls");
			printf("\n-------�ܾ����-------\n\n");
			printf("��带 �����ϼ���\n\n");
			printf("1. �Ϲݸ��(����ܾ� ����)\n2. Ȯ����\n");
			scanf("%d", &modeCh);

			//2-1.�Ϲݸ��
			if (modeCh == 1) {
				system("cls");
				printf("\n-----�Ϲݸ��-----\n\n");
				while (1) {
					printf("���� ������ �Է��ϼ��� : ");
					scanf("%d", &size);
					//size���� �����ϱ�
					if (size > 0 && size <= wordTotal) break;
					printf("���� ������ %d ������ ������� �մϴ�.\n\n", wordTotal);
				}
				Sleep(500);
				system("cls");
				wordTest1(word, han, Wcount, size);  //�Լ��� �ܾ���� ����
				//Ʋ��Ƚ�� ������Ʈ
				fclose(file_Wcount);
				file_Wcount = fopen("Wcount.txt", "w+");
				for (int i = 0; i < wordTotal; i++) {
					fprintf(file_Wcount, "%d\n", Wcount[i]);
				}
				printf("\n\nó��ȭ������ ���ư����� 1, �����Ϸ��� �ƹ� ���ڳ� �Է��ϼ���\n");
				scanf("%d", &modeCh);
				if (modeCh == 1) {
					Sleep(500);
				}
				else break;
			}
			//2-2.Ȯ����
			else if (modeCh == 2) {
				system("cls");
				printf("\n-----Ȯ����-----\n\n");
				while (1) {
					printf("���� ������ �Է��ϼ��� : ");
					scanf("%d", &size);
					//size���� �����ϱ�
					if (size > 0 && size <= wordTotal) break;
					printf("���� ������ %d ������ ������� �մϴ�.\n\n", wordTotal);
				}
				Sleep(500);
				system("cls");
				wordTest2(word, han, Wcount, size);  //�Լ��� �ܾ���� ����
				//Ʋ��Ƚ�� ������Ʈ
				fclose(file_Wcount);
				file_Wcount = fopen("Wcount.txt", "w+");
				for (int i = 0; i < wordTotal; i++) {
					fprintf(file_Wcount, "%d\n", Wcount[i]);
				}
				printf("\n\nó��ȭ������ ���ư����� 1, �����Ϸ��� �ƹ� ���ڳ� �Է��ϼ���\n");
				scanf("%d", &modeCh);
				if (modeCh == 1) {
					Sleep(500);
				}
				else break;
			}
			//����
			else if (modeCh == 0) break;
			//�߸� �Է�
			else {
				printf("�߸��� �Է��Դϴ�.\n");
				Sleep(500);
			}
		}
		//3. �ܾ��� ����
		else if (modeCh == 3) {
			system("cls");
			printf("\n-------�ܾ���-------\n\n");
			printWord(word, han, wordTotal);
			printf("\n\nó��ȭ������ ���ư����� 1\nƲ���ܾ� ����� ������ 2, �����Ϸ��� �ƹ� ���ڳ� �Է��ϼ���\n");
			scanf("%d", &modeCh);
			//ó��ȭ������ ���ư���
			if (modeCh == 1) {
				Sleep(500);
			}
			//Ʋ���ܾ���
			else if (modeCh == 2) {
				system("cls");
				printf("\n-------Ʋ���ܾ���-------\n\n");
				//for (int i = 0; i < wordTotal; i++)
					//printf("%d. %s  %s---> %dȸ Ʋ��\n\n", i + 1, word[i], han[i], Wcount[i]);
				sortWcount(sWcount, Wcount, wordTotal); //���� Ʋ�������� ����
				for (int i = 0; i < wordTotal; i++) {
					if (sWcount[i][1] == 0) break; //Ʋ�� Ƚ���� 0�� �Ǹ� for�� ����
					printf("%s%s", word[sWcount[i][0]], han[sWcount[i][0]]); //sWcount[i][0]�� ������ȣ(��ġ)�� ���������
					printf("--> %dȸ Ʋ��\n\n", sWcount[i][1]);  //sWcount[i][1]�� Ʋ�� Ƚ���� ���������
				}
				printf("\n\nó��ȭ������ ���ư����� 1, �����Ϸ��� �ƹ� ���ڳ� �Է��ϼ���\n");
				scanf("%d", &modeCh);
				if (modeCh == 1) {
					Sleep(500);
				}
				else break;
			}
			else break;
		}
		//0�Է� -> ����
		else if (modeCh == 0) {
			break;
		}
		//�߸� �Է�
		else {
			printf("�ٽ� �Է����ּ���");
			Sleep(700);
		}
	}

	//�ؽ�Ʈ���� �ݱ�
	fclose(file_word);
	fclose(file_han);
	fclose(file_Wcount);

	printf("\n���α׷��� �����մϴ�.");
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
	int num[50] = { 0, };  //�ߺ��ȵǰ� ��ȣ �̱� ���� ���
	int length = wordTotal;
	int a = 0, count = 0;
	char user[50];

	for (int i = 0; i < length; i++) {
		num[i] = i;  //num�� �ʱⰪ�� �ڱ� �ڽ��� ��ġ
	}

	for (int i = 0; i < size; i++) {
		a = rand() % length;                    // num�迭���� ��ġ ���� -> num[a]�� �ѱ�, ���� �迭 ��ġ
		printf("\n%d. %s", i + 1, han[num[a]]); // �ѱ� �� �迭�� num[a]��° ��� ���
		scanf("%s", user);
		if (strcmp(word[num[a]], strcat(user, "\n")) == 0) {  //word[num[a]]�� ����ڰ� �Է��� �� ��, �̶� word[num[a]]�� 
			printf("\n�����Դϴ�.\n");                        //���� "\n"�� �߰��Ǿ� �־, user�� "\n"�� �����Ͽ� ���ؾ���
			Sleep(500);
			count++;
		}
		else {
			printf("\n�����Դϴ�.\n����: %s", word[num[a]]);
			Wcount[num[a]]++;  //Ʋ��Ƚ�� ����
			Sleep(1000);
		}
		numCut(num, a, length--);  //num�迭���� a��° ��� ���� -> �ߺ� �ȵǰ� �ϱ� ����
		system("cls");
	}
	printf("\n��ü���� : %2d��\n", size);
	printf("�������� : %2d��\n", count);
	printf("����� : %0.2f%%\n", (float)count / size * 100.0);
}

void wordTest2(char word[][50], char han[][50], int Wcount[], int size)
{
	char user[50];
	int user_ans;
	int type, a = 0, abcd, count = 0, t = 1;
	int b[4] = { -1,-1,-1,-1 };
	int length = wordTotal; //�迭 ����
	int num[50];
	for (int i = 0; i < length; i++) {
		num[i] = i;
	}

	for (int i = 0; i < size; i++) {
		type = rand() % 3; //3���� ���� �������� ����

		if (type == 0) //�ְ��� -> �Ϲ� ���� �Ȱ���
		{
			a = rand() % length;  // num�迭���� ��ġ ���� -> num[a]�� �ѱ�, ���� �迭 ��ġ
			printf("\n%d. %s", i + 1, han[num[a]]); // �ѱ� �� �迭�� num[a]��° ��� ���
			scanf("%s", user);
			if (strcmp(word[num[a]], strcat(user, "\n")) == 0) {  //word[num[a]]�� ����ڰ� �Է��� �� ��, �̶� word[num[a]]��
				printf("\n�����Դϴ�.\n");                        //���� "\n"�� �߰��Ǿ� �־, user�� "\n"�� �����Ͽ� ���ؾ���
				Sleep(500);
				count++;
			}
			else {
				printf("\n�����Դϴ�.\n����: %s", word[num[a]]);
				Wcount[num[a]]++;
				Sleep(1000);
			}
		}
		else if (type == 1) //������1(�ѱ� �� �����ְ� ���ܾ� ã��)
		{
			a = rand() % length; //num�迭���� ��ġ ���� -> num[a]�� ����ܾ� ��ġ
			abcd = rand() % 4;   //����� ����(1.2.3.4)���� ����ܾ� ��ġ ����
			printf("\n%d.%s\n", i + 1, han[num[a]]);  //num[a]��° �ѱ� �� ���

			for (int j = 0; j < 4; j++) {
				if (j == abcd) {                            //����ܾ� ��ġ�ϋ�
					printf("   %d.%s", j + 1, word[num[a]]);  //num[a]��° ���ܾ� ���
				}
				else {
					while (1) {
						t = 1; //t=1�� �ʱ�ȭ
						b[j] = rand() % wordTotal;    //��ü �ܾ� �� ���� �ܾ� ����
						for (int k = 0; k < j; k++) {
							if (b[j] == b[k]) t = 0;  //���� ����� ���� �ܾ�� �ٸ��� ��, ������ ������ t=0
						}
						if (t && num[a] != b[j]) {  //t=1(�ٸ� ����ܾ�� �ٸ�)�̰�, ���� �ܾ�� �ٸ���
							printf("   %d.%s", j + 1, word[b[j]]);      //���� �ܾ� ���
							break;
						}
					}
				}
			}
			printf("\n");
			//����ڰ� ���� �Է�
			scanf("%d", &user_ans);
			if (user_ans == abcd + 1) {  //����ڰ� �Է��� ��ȣ�� ���� ��ġ�� ������
				printf("\n�����Դϴ�.");
				count++;
				Sleep(500);
			}
			else {
				printf("\n�����Դϴ�.\n");
				printf("���� : %d.%s", abcd + 1, word[num[a]]);
				Wcount[num[a]]++;
				Sleep(1500);
			}
		}
		else if (type == 2) //������2(���� �����ְ� �ѱ۶� ã��) -> ������ 1���� ����, �ѱ۸� ���� �ٲٸ� ��
		{
			a = rand() % length; //num�迭���� ��ġ ���� -> num[a]�� ����ܾ� ��ġ
			abcd = rand() % 4;   //����� ����(1.2.3.4)���� ����ܾ� ��ġ ����
			printf("\n%d.%s\n", i + 1, word[num[a]]);
			for (int j = 0; j < 4; j++) {
				if (j == abcd) {      //����ܾ� ��ġ�϶�
					printf("   %d.%s", j + 1, han[num[a]]);
				}
				else {
					while (1) {
						t = 1;
						b[j] = rand() % wordTotal;    //��ü �ܾ� �� ���� �ܾ� ����
						for (int k = 0; k < j; k++) {
							if (b[j] == b[k]) t = 0;  //���� ����� ���� �ܾ�� �ٸ��� ��, ������ ������ t=0
						}
						if (t && num[a] != b[j]) {    //t=1(�ٸ� ����ܾ�� �ٸ�)�̰�, ���� �ܾ�� �ٸ���
							printf("   %d.%s", j + 1, han[b[j]]);  //���� �ܾ� ���
							break;
						}
					}
				}
			}
			printf("\n");
			scanf("%d", &user_ans);
			if (user_ans == abcd + 1) {  //����ڰ� �Է��� ��ȣ�� ���� ��ġ�� ������
				printf("\n�����Դϴ�.");
				count++;
				Sleep(500);
			}
			else {
				printf("\n�����Դϴ�.\n");
				printf("���� : %d.%s", abcd + 1, han[num[a]]);
				Wcount[num[a]]++;
				Sleep(1500);
			}
		}
		numCut(num, a, length--);
		system("cls");
	}
	printf("\n��ü���� : %2d��\n", size);
	printf("�������� : %2d��\n", count);
	printf("����� : %0.2f%%\n", (float)count / size * 100.0);
}

void cut(char word[][50], char han[][50], int Wcount[], int posi, int length)
{
	for (int i = posi; i < length - 1; i++) {
		strcpy(word[i], word[i + 1]);  //strcpy�� �̿��Ͽ� word[i+1]�� ���ڿ��� word[i]�� ����
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
		sWcount[i][0] = i;          //������ȣ(ó����ġ)
		sWcount[i][1] = Wcount[i];  //Ʋ��Ƚ��
	}

	//����
	for (int i = 0; i < length - 1; i++) {
		for (int j = i; j < length; j++) {
			//sWcount[][1](Ʋ��Ƚ��)�� ū ������� ���� 
			if (sWcount[i][1] < sWcount[j][1]) {
				//[][0](������ȣ), [][1](Ʋ��Ƚ��)��� �ű��
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