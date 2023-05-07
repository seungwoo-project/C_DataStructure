// Floyd : ��� ���� ������ �ִܰ�θ� ã��
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000

int sum = 0;
int n_insert = 0;
// �׷��� ����ü
typedef struct GraphType {
	int n; // ����
	int weight[MAX_VERTICES][MAX_VERTICES]; // ����ġ
} GraphType;
int matrix[MAX_VERTICES][MAX_VERTICES]; // distance�� ���� ����
// �׷��� �ʱ�ȭ �Լ�
void init_graph(GraphType* g) {
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++) {
		for (int j = 0; j < MAX_VERTICES; j++) {
			g->weight[i][j] = INF; // ��� ����ġ�� �������� �ʱ�ȭ
		}
	}
}
// ����ġ ����
void insert_edge(GraphType* g, int start, int end, int number) {
	if (n_insert == number - 1) { /* ����ġ�� 1�� ������ȣ ���� */
		g->weight[start][end] = 1;
		g->weight[end][start] = 1;
	}
	else { // �ƴϸ� 0 ����
		g->weight[start][end] = 0;
		g->weight[end][start] = 0;
	}
	n_insert++;
}
void shortest_path_sum(GraphType* g) {
	//�÷��̵� �˰���
	int i, j, k;
	for (i = 0; i < g->n; i++)
		for (j = 0; j < g->n; j++)
			matrix[i][j] = g->weight[i][j];
	for (k = 0; k < g->n; k++) {
		for (i = 0; i < g->n; i++)
			for (j = 0; j < g->n; j++)
				if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
					matrix[i][j] = matrix[i][k] + matrix[k][j];
				}
	}
	// ��� ���� ���� �ִ� ��� �Ÿ��� ��
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			sum += matrix[i][j];
		}
	}
}
int main(void)
{
	int start, end;
	int nvertex, number;
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init_graph(g); // �׷��� �ʱ�ȭ
	scanf("%d %d", &nvertex, &number); // ������ ���� : nvertex ����ġ�� 1�� ���� ��ȣ : number
	g->n = nvertex; // ������ ���� = �׷����� ũ��
	while (scanf("%d %d", &start, &end) != EOF) { // �� ������ �������� ����
		insert_edge(g, start, end, number); // �׷����� ����, �������� ����ġ�� 1�� ������ȣ ����
	}
	shortest_path_sum(g); // �÷��̵� ���� �˰��� �Լ�
	printf("%d", sum / 2); // ��� �������� �ִܰŸ��� �� (�ߺ� ���� �� : 1->4, 4->1 �ߺ�!)
	free(g);
	return 0;
}