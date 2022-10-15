#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L
#define VERTICES_COUNT 7

typedef struct GraphType {
	int n;	// ������ ����
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

// �ּ� dist[v] ���� ���� ������ ��ȯ
int get_min_vertex(int n)
{
	int v, i;
	// ������ ���õ��� �ʾҴ� �������� v �ʱ�ȭ
	for (i = 0; i < n; i++)
		if (!selected[i]) {
			v = i;
			break;
		}

	// ������ ���õ��� �ʾҴ� ���� �� �Ÿ��� ���� ª�� ���� ã��
	for (i = 0; i < n; i++)
		if (!selected[i] && (distance[i] < distance[v]))
			v = i;

	return v;
}

int* prim(GraphType* g, int s)
{
	int i, u, v;
	int* vertices_arr = (int*)malloc(sizeof(int) * VERTICES_COUNT);

	printf("prim �ּ� ���� Ʈ�� �˰���\n\n");
	printf("Ʈ�� Ȯ�� ����\n");

	for (u = 0; u < g->n; u++)
		distance[u] = INF;

	distance[s] = 0;

	for (i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n);	// �ּ� dist[v] ���� ���� ���� ��ȯ
		selected[u] = TRUE;
		vertices_arr[i] = u;

		if (distance[u] == INF) return;
		printf("���� %c �߰�\n", u + 65);

		// ���� distance �迭���� ���� �������� ���Ͽ� �� ���� ������ ��ü
		for (v = 0; v < g->n; v++)
			if (g->weight[u][v] != INF)
				if (!selected[v] && g->weight[u][v] < distance[v])
					distance[v] = g->weight[u][v];
	}
	printf("---------------------------\n\n");
	return vertices_arr;
}

void print_mcst(GraphType* g, int* vertices) {
	int i, j, sum = 0;

	printf("���� �׷��� ���� ����\n");

	for (i = 0; i < VERTICES_COUNT - 1; i++) {
		for (j = i; g->weight[vertices[j]][vertices[i + 1]] == INF; j--);
		printf("���� (%c, %c) %d\n", vertices[j] + 65, vertices[i + 1] + 65, g->weight[vertices[j]][vertices[i + 1]]);
		sum += g->weight[vertices[j]][vertices[i + 1]];
	}
	printf("�� ���: %d\n", sum);
}

int main(void)
{
	GraphType g = { VERTICES_COUNT,
	{{  0,   3,  17,   6, INF, INF, INF },
	{   3,   0, INF,   5, INF, INF,  12 },
	{  17, INF,   0, INF,  10,   8, INF },
	{   6,   5, INF,   0,   9, INF, INF },
	{ INF, INF,  10,   9,   0,   4,   2 },
	{ INF, INF,   8, INF,   4,   0, INF },
	{ INF,  12, INF, INF,   2, INF,   0 } }
	};

	int* vertices = prim(&g, 0);	// �׷���, ���� ����

	print_mcst(&g, vertices);
	return 0;
}