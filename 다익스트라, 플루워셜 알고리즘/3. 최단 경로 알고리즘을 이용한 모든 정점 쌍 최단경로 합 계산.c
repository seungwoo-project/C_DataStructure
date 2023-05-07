// Floyd : 모든 정점 사이의 최단경로를 찾음
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000

int sum = 0;
int n_insert = 0;
// 그래프 구조체
typedef struct GraphType {
	int n; // 정점
	int weight[MAX_VERTICES][MAX_VERTICES]; // 가중치
} GraphType;
int matrix[MAX_VERTICES][MAX_VERTICES]; // distance랑 같은 개념
// 그래프 초기화 함수
void init_graph(GraphType* g) {
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++) {
		for (int j = 0; j < MAX_VERTICES; j++) {
			g->weight[i][j] = INF; // 모든 가중치를 무한으로 초기화
		}
	}
}
// 가중치 삽입
void insert_edge(GraphType* g, int start, int end, int number) {
	if (n_insert == number - 1) { /* 가중치가 1인 간선번호 삽입 */
		g->weight[start][end] = 1;
		g->weight[end][start] = 1;
	}
	else { // 아니면 0 삽입
		g->weight[start][end] = 0;
		g->weight[end][start] = 0;
	}
	n_insert++;
}
void shortest_path_sum(GraphType* g) {
	//플루이드 알고리즘
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
	// 모든 정점 쌍의 최단 경로 거리의 합
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
	init_graph(g); // 그래프 초기화
	scanf("%d %d", &nvertex, &number); // 정점의 개수 : nvertex 가중치가 1인 간선 번호 : number
	g->n = nvertex; // 정점의 개수 = 그래프의 크기
	while (scanf("%d %d", &start, &end) != EOF) { // 두 정점이 간선으로 연결
		insert_edge(g, start, end, number); // 그래프에 시작, 끝정점과 가중치가 1인 간선번호 삽입
	}
	shortest_path_sum(g); // 플루이드 워셜 알고리즘 함수
	printf("%d", sum / 2); // 모든 정점쌍의 최단거리의 합 (중복 제거 예 : 1->4, 4->1 중복!)
	free(g);
	return 0;
}