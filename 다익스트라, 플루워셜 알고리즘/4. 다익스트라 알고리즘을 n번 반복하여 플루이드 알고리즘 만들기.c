// Dijkstra알고리즘: 하나의 시작 정점에서 다른 정점까지의 최단 경로 계산
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100

// 그래프 구조체
typedef struct GraphType {
	int n; // 정점
	int weight[MAX_VERTICES][MAX_VERTICES]; // 가중치
} GraphType;
int distance[MAX_VERTICES]; // 최단경로가 알려진 정점들만을 이용한 다른 정점들까지의 최단 경로 길이
int found[MAX_VERTICES]; // 방문한 정점 표시
int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX; // 최소값 초기화
	minpos = -1;
	for (i = 0; i < n; i++)
		if (distance[i] < min && !found[i]) { // 만약 방문안했고 distance가 min 보다 작으면 min이 distance가 됨
			min = distance[i];
			minpos = i; // 최소거리의 노드번호
		}
	return minpos; // 최소거리의 노드번호 리턴
}
void shortest_path(GraphType* g, int start) // 다익스트라 최단경로 매개변수로 그래프 g와 start = 0 을 받음
{
	int i, u, w;
	for (i = 0; i < g->n; i++) /* 초기화 */
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE; /* 시작 정점 방문 표시 */
	distance[start] = 0;
	for (i = 0; i < g->n - 1; i++) {
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		for (w = 0; w < g->n; w++)
			if (!found[w]) // 방문 하지 않은 노드들에 대해
				if (distance[u] + g->weight[u][w] < distance[w]) /*
				갱신 과정 */
					distance[w] = distance[u] +
					g->weight[u][w];
	}
	for (int i = 0; i < g->n; i++) {

		printf("%d ", distance[i]); // 최단경로로만 이루어진 길 출력
	}
	printf("\n");
}
int main(void)
{
	GraphType g; // 그래프 생성
	int input; // 입력
	int i = 0, j = 0;
	scanf("%d", &g.n); // 정점의 수 입력
	while (scanf("%d", &input) != EOF) { // 사용자가 끝낼때까지 가중치를 입력받는다
		if (j == g.n) { // 만약 j열이 정점의 수와 같다면 i열 +1 해준다
			i++;
			j = 0; // 다시 0부터 시작
		}
		g.weight[i][j] = input; // 입력받은 값을 가중치 배열에 넣기
		j++; // j열 반복
	}
	for (i = 0; i < g.n; i++)
		shortest_path(&g, i); // 받은 그래프를 다익스트라 최단경로로 나타내는 함수
	return 0;
}