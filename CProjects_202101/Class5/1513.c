#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	//�÷��̾�� �����ϱ�
	while (1) {

		int playnum, outputnum, sum = 0, input;
		//playnum=�÷��̾��, sum=�� �Ͽ��� �հ�
		//outputnum=��µǴ� ��(31-100), input: �� �÷��̾ �Է��ϴ� ��(0-99)

		printf("\n###���ڸ� �Է��Ͻñ� �ٶ��ϴ�.###\n");
		printf("�÷��̾� ���� �Է��ϼ���: ");
		scanf("%d", &playnum);


		//�÷��̾���� 1-4�� �ƴ� �� �ٽ� �Է��ϱ�
		if (playnum > 4 || playnum < 1)
		{
			printf("�÷��̾���� 1���� 4���Դϴ�.\n");
			printf("�ٽ� �Է��ϱ�\n");
		}

		//�ùٸ��� �ԷµǾ��� ��
		else
		{
			printf("�÷��̾���� %d���Դϴ�.\n", playnum);
			printf("--------------------start-----------------------\n");

			//���� ����
			while (1) {

				//���Ǵ� ���� ����
				srand(time(NULL));
				outputnum = rand() % 69 + 31;
				input = rand() % 13 + 3;

				//�÷��̾ 1���� ��
				//��ǻ�Ͷ� �����ϴ� �� �ȵǼ� ȥ�ڼ� �����ϴ� ������ �ٲ�

				if (playnum == 1) {
					printf("���ڸ� �Է��ϼ���: ");
					scanf("%d", &input);
					if (input < 0 || input >99)
					{
						printf("\n******���� ���� �����Դϴ�.******\n");
						printf("----�ٽ� �Է��ϱ�----\n\n");

					}

					else
					{
						if (input <= 9)
							sum += 1;
						else
							sum += 2;

						if (sum >= outputnum) {
							printf("\n==========���� ����==========\n\n");
							break;
						}
						else
							printf("\n----�հ�: %d----\n\n", sum);
					}
				}

				else {

					//�÷��̾ 2�� �̻��� �� 

					if (sum < outputnum) {

						for (int i = 1; i <= playnum; i++) {

							printf("%d--���ڸ� �Է��ϼ���: ", i);
							scanf("%d", &input);

							if (input < 0 || input >99)
							{
								printf("\n******���� ���� �����Դϴ�.******\n");
								printf("----�ٽ� �Է��ϱ�----\n\n");
								printf("�߸� �Է��� %d�� �÷��̾��� ���ʴ� ��ȿ�Դϴ�.\n\n", i);
								//�߸� �Է��� ����� ���ʴ� ��ȿ
							}

							else
							{
								if (input <= 9)
									sum += 1;
								else
									sum += 2;

								printf("\n----�հ�: %d----\n\n", sum);
							}
						}
					}
					else
					{
						printf("==========���� ����==========\n\n");
						printf("�������� �Է��� ����� �����Դϴ�.\n\n\n\n");
						break;
					}
				}
			}
		}
	}
}