// Floyd : ��� ���� ������ �ִܰ�θ� ã��
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100

// �׷��� ����ü
typedef struct GraphType {
	int n; // ����
	int weight[MAX_VERTICES][MAX_VERTICES]; // ����ġ
} GraphType;
int distance[MAX_VERTICES][MAX_VERTICES]; // �ִܰ�ΰ� �˷��� �����鸸�� �̿��� �ٸ� ����������� �ִ� ��� ����
// �÷��̵� ���� �˰���
void floyd(GraphType* g)
{
	int i, j, k;
	for (i = 0; i < g->n; i++)
		for (j = 0; j < g->n; j++)
			distance[i][j] = g->weight[i][j]; // ��� ����ġ�� �ʱ�ȭ
	for (k = 0; k < g->n; k++) {
		for (i = 0; i < g->n; i++)
			for (j = 0; j < g->n; j++)
				if (distance[i][k] + distance[k][j] < distance[i][j]) /*3�� �ݺ����� �̿��� ���Ű���*/
					distance[i][j] = distance[i][k] +
					distance[k][j];
	}
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
	floyd(&g); // �÷��̵� �˰��� �Լ�
	for (i = 0; i < g.n; i++) {
		for (j = 0; j < g.n; j++) {
			printf("%d ", distance[i][j]); // ��� ���� ���� �ִ� ��� ���
		}
		printf("\n");
	}
	return 0;
}