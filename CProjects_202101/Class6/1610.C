#include <stdio.h>
#include <math.h>
#include <time.h>

int main() {
	int ggh = 1;

	while (ggh == 1) {
		int Q;
		printf("������ �ñ��ϽŰ���?\n");
		printf("<1> : ����\n<2> : ������ ���ϱ�\n<3>: � ������ �ؾ� �ұ��?\n");
		scanf("%d", &Q);

		//<1> : ����
		if (Q == 1) {
			int n;
			int count = 0;

			//��� ����
			do {
				if (count == 1)
					printf("\n���� ������ �Ͻô��� �𸣰ھ��\n\n�ٽ� �Է����ּ���\n");
				printf("�ϰ� ���� ����� �������ּ���\n");
				printf("1 : ��Ģ����\n2 : �ŵ�����\n");
				scanf("%d", &n);
				if (n != 1 && n != 2)
					count = 1;
			} while (n != 1 && n != 2);//�߸� �Է����� ��� �ٽ� ���� �ޱ�

			//1 : ��Ģ����
			if (n == 1) {
				float a, b;
				char operator=0;

				printf("�ϰ� ���� ������ �Է��ϼ���\n");
				scanf(" %c", &operator);

				//���ϱ�
				if (operator == '+') {
					printf("���ϰ� ���� ���� �Է��ϼ��� ");
					scanf("%f %f", &a, &b);
					printf("\n%f", a + b);
				}

				//����
				if (operator == '-') {
					printf("���� ���� ���� �Է��ϼ��� ");
					scanf("%f %f", &a, &b);
					printf("\n%f", a - b);
				}

				//���ϱ�
				if (operator == '*') {
					printf("���ϰ� ���� ���� �Է��ϼ��� ");
					scanf("%f %f", &a, &b);
					printf("\n%f", a * b);
				}

				//������
				if (operator == '/') {
					printf("������ ���� ���� �Է��ϼ��� ");
					scanf("%f %f", &a, &b);
					printf("\n%f", a / b);
				}
			}

			//2 : �ŵ�����
			if (n == 2) {
				double a, b;
				printf("���� ������? ");
				scanf("%lf %lf", &a, &b);
				printf("\n%lf", pow(a, b));
			}
		}

		//<2> : ������ ���ϱ�
		else if (Q == 2) {
			float meaval, trueval, pererror;
			printf("���谪 : ");
			scanf("%f", &meaval);
			printf("�̷а� : ");
			scanf("%f", &trueval);
			pererror = ((trueval - meaval) / trueval) * 100;
			if (pererror < 0)
				pererror = -pererror;
			printf("\n%f %%", pererror);
		}

		//<3> : � ������ �ؾ� �ұ��?
		else if (Q == 3) {
			char a[50], b[50], c;
			printf("������ְ� �� ���!\n");
			printf("���������� ������ �ֳ���?(�� ���� �������� �Է����ּ���)\n");
			printf("1 : ");
			scanf("%s", a);
			printf("2 : ");
			scanf("%s", b);
			srand(time(NULL));
			c = rand() % 2 + 1;
			if (c == 1)
				printf("\n%d : %s", c, a);
			if (c == 2)
				printf("\n%d : %s", c, b);
		}

		//�߸� �Է����� ���
		else {
			printf("\n���� ������ �Ͻô��� �𸣰ھ��\n\n�ٽ� �Է����ּ���\n");
			continue;//(while(ggh==1))�� ���ư� �ٽ� ���� �ޱ�
		}

		//���� �� ������ �����ϱ�
		int k = 1;
		while (k == 1) {
			int any;
			printf("\n\n�ٸ� �ñ��� ���� ������?\n");
			printf("1 : �־��\n2 : �����\n");
			scanf("%d", &any);

			if (any == 1) {
				printf("\n----------------------\n\n");//�� ������ �� ���� ���� ���м�
				k = 0;//while (k==1) ���������� while(ggh==1) ���� �ٽ� ����
			}

			else if (any == 2) {
				printf("\n�����մϴ�\n");
				k = 0;//while (k==1) ����������
				ggh = 0;//while(ggh==1) ����������

			}

			//�߸� �Է����� ���
			else {
				printf("\n���� ������ �Ͻô��� �𸣰ھ��\n\n�ٽ� �Է����ּ���");
				continue;//(while (k==1))�� ó�� ��ġ�� ���ư� �ٽ� ���� �ޱ�
			}
		}
	}
	return 0;
}