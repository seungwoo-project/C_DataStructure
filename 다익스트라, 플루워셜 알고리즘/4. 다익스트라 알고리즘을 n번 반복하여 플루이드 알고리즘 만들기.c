// Dijkstra�˰���: �ϳ��� ���� �������� �ٸ� ���������� �ִ� ��� ���
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100

// �׷��� ����ü
typedef struct GraphType {
	int n; // ����
	int weight[MAX_VERTICES][MAX_VERTICES]; // ����ġ
} GraphType;
int distance[MAX_VERTICES]; // �ִܰ�ΰ� �˷��� �����鸸�� �̿��� �ٸ� ����������� �ִ� ��� ����
int found[MAX_VERTICES]; // �湮�� ���� ǥ��
int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX; // �ּҰ� �ʱ�ȭ
	minpos = -1;
	for (i = 0; i < n; i++)
		if (distance[i] < min && !found[i]) { // ���� �湮���߰� distance�� min ���� ������ min�� distance�� ��
			min = distance[i];
			minpos = i; // �ּҰŸ��� ����ȣ
		}
	return minpos; // �ּҰŸ��� ����ȣ ����
}
void shortest_path(GraphType* g, int start) // ���ͽ�Ʈ�� �ִܰ�� �Ű������� �׷��� g�� start = 0 �� ����
{
	int i, u, w;
	for (i = 0; i < g->n; i++) /* �ʱ�ȭ */
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE; /* ���� ���� �湮 ǥ�� */
	distance[start] = 0;
	for (i = 0; i < g->n - 1; i++) {
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		for (w = 0; w < g->n; w++)
			if (!found[w]) // �湮 ���� ���� ���鿡 ����
				if (distance[u] + g->weight[u][w] < distance[w]) /*
				���� ���� */
					distance[w] = distance[u] +
					g->weight[u][w];
	}
	for (int i = 0; i < g->n; i++) {

		printf("%d ", distance[i]); // �ִܰ�ηθ� �̷���� �� ���
	}
	printf("\n");
}
int main(void)
{
	GraphType g; // �׷��� ����
	int input; // �Է�
	int i = 0, j = 0;
	scanf("%d", &g.n); // ������ �� �Է�
	while (scanf("%d", &input) != EOF) { // ����ڰ� ���������� ����ġ�� �Է¹޴´�
		if (j == g.n) { // ���� j���� ������ ���� ���ٸ� i�� +1 ���ش�
			i++;
			j = 0; // �ٽ� 0���� ����
		}
		g.weight[i][j] = input; // �Է¹��� ���� ����ġ �迭�� �ֱ�
		j++; // j�� �ݺ�
	}
	for (i = 0; i < g.n; i++)
		shortest_path(&g, i); // ���� �׷����� ���ͽ�Ʈ�� �ִܰ�η� ��Ÿ���� �Լ�
	return 0;
}