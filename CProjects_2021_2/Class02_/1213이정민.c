#include <stdio.h>
#include <time.h>

int level;
int arrayGaybokchi[6];
int* cursor; //����⸦ ����Ű�� ����

void initialData();
void printGaybokchi();
void decreaseWater(long elapsedTime);

int main(void) {
	long startTime = 0; //���� ���۽ð�
	long totalElapsedTime = 0; //�� ����ð�
	long prevElapsedTime = 0; //���� ��� �ð� (�ֱٿ� ���� �� �ð� ����)

	int num; //�� �� ���׿� ���� �� ������, ����� �Է�
	initialData();

	cursor = arrayGaybokchi; //�����ͺ����� �̿� �迭ó�� ���

	startTime = clock(); //����ð��� ms ������ ��ȯ
	while (1) {
		printGaybokchi();
		//getchar(); �ӽ÷� ����� �Է��� ��� 
		printf("�� �� ���׿� ���� �ֽðھ��?");
		scanf_s("%d", &num);

		//�Է°� Ȯ��
		if (num < 1 || num>6)
		{
			printf("\n �Է°��� �߸��Ǿ����ϴ�. \n");
			continue;
		}
		//�� ����ð�
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("�� ����ð� : %ld ��\n", prevElapsedTime);

		//������ ���� ����
		decreaseWater(prevElapsedTime);

		//����ڰ� �Է��� ���׿� ���� ��.
		// ������ ���� 0�� ��� ���� ���� �ʴ´�. (����Ⱑ �̹� ����)
		if (cursor[num - 1] <= 0)
		{
			printf("%d�� ������ �̹� �׾����ϴ�. ���� ���� �ʽ��ϴ�. \n", num);
		}
		// ������ ���� 0�� �ƴ� ��� ���� �ش�. (100�� ������ �ʴ��� Ȯ���� �ʿ���)

		else if (cursor[num - 1] + 1 <= 100)
		{
			//���� �ش�
			printf("%d�� ���׿� ���� �ݴϴ�\n\n", num);
			cursor[num - 1] += 1;
		}

		//Levelup�� �� �Ǳ� Ȯ�� (20seconds ���� �ѹ��� Levelup ����)
		if (totalElapsedTime / 20 > level - 1) //ó�������� 1�̹Ƿ� 1���� ���� 0.XXX �� ���� int ���� 0���� ����
		{
			level++;
			printf("�� ������! ���� %d �������� %d������ ���׷��̵� ����! \n\n", level - 1, level);
			//���������� ���� Levelup �� ���緹������ 1��ŭ ����.

			//�������� : 5Level
			if (level == 5)
			{
				printf("\n\n ����! �ְ� ������ �޼��Ͽ����ϴ�! ���ӳ�!\n\n");

				exit(0); //���α׷� ��ü�� �����ϴ� �۾�
			}
		}

		//��� ����Ⱑ �׾����� Ȯ�� 

		if (checkFishAlive() == 0)
		{
			//����Ⱑ �Ѹ����� ���� �ʰ� ��� �׾���
			printf("��� ����Ⱑ ����߽��ϴ�. \n");
		}
		else
		{
			//�Ѹ��� �Ǵ� ���̻��� �������� �������
			printf("����Ⱑ ���� �����־��!\n");
		}
		prevElapsedTime = totalElapsedTime;

		//25�ʿ��� 15�ʸ� �������� �ӽð��� ���� while ������
	}
	return 0;
}

void initialData()
{
	level = 1; //���ӷ����� 1�������� 5�������� (5�� �ִ�)
	for (int i = 0; i < 6; i++)
	{
		arrayGaybokchi[i] = 100; //������ �� ���� (0���� 100����)
	}
}

void printGaybokchi() {

	printf("%3d�� 3d�� %3d�� %3d�� %3d�� %3d�� \n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++)
	{
		printf("%3d", arrayGaybokchi[i]);
	}
	printf("\n\n");
}

void decreaseWater(long elapsedTime) //�ֱٰ���ð�
{
	for (int i = 0; i < 6; i++)
	{
		arrayGaybokchi[i] -= (level * 3 * (int)elapsedTime); //3�� ���̵�������, 10���� ��쿡�� 30��ŭ ����
		if (arrayGaybokchi[i] < 0)
		{
			arrayGaybokchi[i] = 0;
		}
	}
}

int checkFishAlive() {

	for (int i = 0; i < 6; i++)
	{
		if (arrayGaybokchi[i] > 0)
			return 1; //�� Ture
	}
	return 0;
}