#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000

typedef struct GraphType {
	int n; // ������ ����
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

int get_min_vertex(int n)
{
	int v, i;
	for (i = 0; i < n; i++)
		if (!selected[i]) {
			v = i;
			break;
		}
	for (i = 0; i < n; i++)
		if (!selected[i] && (distance[i] < distance[v]))
			v = i;
	return (v);
}
void prim(GraphType* g, int s)
{
	int i, u, v;
	for (u = 0; u < g->n; u++)
		distance[u] = INF;
	distance[s] = 0;
	for (i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		if (distance[u] == INF) return;  /*-> �ּҽ���Ʈ���� ���Ǵ� ��� ������ ���� ���� ���� ������ ������� �����ϴ� Ʈ���̴�.
		�� �ڵ带 �� ������ �ּҽ���Ʈ�� ���ǿ� �������� �� ��, �׷����� �� �� �̻��� �׷����� ������ ���� ������ �ȴ�.*/
		printf("%d\n", u);
		for (v = 0; v < g->n; v++)
			if (g->weight[u][v] != INF)
				if (!selected[v] && g->weight[u][v] < distance[v])
					distance[v] = g->weight[u][v];
	}
}
int main(void)
{
	GraphType g;
	int input;
	int i = 0, j = 0;
	scanf("%d", &g.n);
	while (scanf("%d", &input) != EOF) {
		if (j == g.n) {
			i++;
			j = 0;
		}
		g.weight[i][j] = input;
		j++;
	}
	prim(&g, 0);
	return 0;
}