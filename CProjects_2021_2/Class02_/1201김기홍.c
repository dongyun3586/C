#include<stdio.h>

typedef struct {
	int state[19][19];
}State;

void print_state(State state) { //���� ���¸� ǥ�� �浹�� ������ '��'��쿡�� ǥ�ø�, �鵹�� �����ִ� ��쿡�� '��'ǥ�ø� �Ѵ�.
	printf("\n����������������������\n"); //��踦 ǥ��
	for (int i = 0; i < 19; i++) {
		printf("��");
		for (int j = 0; j < 19; j++) {
			if ((state.state)[i][j] == 1) //�鵹(1)�� �����ִ� ���
				printf("��");
			else if ((state.state)[i][j] == 2) //�浹(2)�� �����ִ� ���
				printf("��");
			else //�ƹ� ���� �������� ���� ���
				printf("  ");
		}printf("��\n");
	}printf("����������������������\n\n"); //��踦 ǥ��
	return;
}
int determinent(State state) { //�� �Ǵ� ���� 5���� �ϼ��� �Ǿ��� ���� �Ǻ�
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if ((state.state)[i][j] == 1) { //���� ���� �ϼ� ���θ� �Ǻ�
				if ((state.state)[i + 1][j] == 1 && (state.state)[i + 2][j] == 1 && (state.state)[i + 3][j] == 1 && (state.state)[i + 4][j] == 1) { //���η� ���� ���� �Ǻ�
					printf("********************!!!�� ��!!!********************");
					return 0;
				}
				else if ((state.state)[i][j + 1] == 1 && (state.state)[i][j + 2] == 1 && (state.state)[i][j + 3] == 1 && (state.state)[i][j + 4] == 1) { //���η�  ���� ���� �Ǻ�
					printf("********************!!!�� ��!!!********************");
					return 0;
				}
				else if ((state.state)[i - 1][j + 1] == 1 && (state.state)[i - 2][j + 2] == 1 && (state.state)[i - 3][j + 3] == 1 && (state.state)[i - 4][j + 4] == 1) { //������ �� �밢������ ���� ���� �Ǻ�
					printf("********************!!!�� ��!!!********************");
					return 0;
				}
				else if ((state.state)[i + 1][j + 1] == 1 && (state.state)[i + 2][j + 2] == 1 && (state.state)[i + 3][j + 3] == 1 && (state.state)[i + 4][j + 4] == 1) { //������ �Ʒ� �밢������ ���� ���� �Ǻ�
					printf("********************!!!�� ��!!!********************");
					return 0;
				}
			}
			else if ((state.state)[i][j] == 2) { //���� ���� �ϼ� ���θ� �Ǻ�
				if ((state.state)[i + 1][j] == 2 && (state.state)[i + 2][j] == 2 && (state.state)[i + 3][j] == 2 && (state.state)[i + 4][j] == 2) { //���η� ���� ���� �Ǻ�
					printf("********************!!!�� ��!!!********************");
					return 0;
				}
				else if ((state.state)[i][j + 1] == 2 && (state.state)[i][j + 2] == 2 && (state.state)[i][j + 3] == 2 && (state.state)[i][j + 4] == 2) { //���η�  ���� ���� �Ǻ�
					printf("********************!!!�� ��!!!********************");
					return 0;
				}
				else if ((state.state)[i - 1][j + 1] == 2 && (state.state)[i - 2][j + 2] == 2 && (state.state)[i - 3][j + 3] == 2 && (state.state)[i - 4][j + 4] == 2) { //������ �� �밢������ ���� ���� �Ǻ�
					printf("********************!!!�� ��!!!********************");
					return 0;
				}
				else if ((state.state)[i + 1][j + 1] == 2 && (state.state)[i + 2][j + 2] == 2 && (state.state)[i + 3][j + 3] == 2 && (state.state)[i + 4][j + 4] == 2) { //������ �Ʒ� �밢������ ���� ���� �Ǻ�
					printf("********************!!!�� ��!!!********************");
					return 0;
				}
			}
		}
	}return 1;
}

int main() {
	int x = 0, y = 0, s = 0, g = 0; // (x,y)�� ���� ���� ��ġ�� �����ϴ� ����, s�� ���� ������ ���� �������� �����ϴ� ����, g�� ������ �ϼ� �Ǿ������� �Ǵ��ϴ� ����
	State state;

	for (int i = 0; i < 19; i++) { //state�� �ʱ�ȭ
		for (int j = 0; j < 19; j++)
			(state.state)[i][j] = 0;
	}

	while (1) {
		if (s == 0) {
			printf("��(x, y) : ");
			scanf("%d %d", &x, &y);

			if ((state.state)[x][y] == 0) //������ ��ġ�� �浹�� ���´�
				(state.state)[x][y] = 2;
			else { //���� ��ġ�� �� ��츦 ����
				printf("�ߺ��ؼ� �� �� �����ϴ�!\n");
				continue;
			}
			s = 1; //���� ���� �鵹����
		}
		else if (s == 1) {
			printf("��(x, y) : ");
			scanf("%d %d", &x, &y);

			if ((state.state)[x][y] == 0)//������ ��ġ�� �浹�� ���´�
				(state.state)[x][y] = 1;
			else { //���� ��ġ�� �� ��츦 ����
				printf("�ߺ��ؼ� �� �� �����ϴ�!\n");
				continue;
			}
			s = 0; //���� ���� �浹����
		}
		print_state(state); //���� ������ ���� ���¸� ǥ��
		g = determinent(state); //���� �ϼ� ���θ� �Ǻ�
		if (g == 0)
			break; //������ �ϼ��Ǹ� while�� ������ ������
	}
}