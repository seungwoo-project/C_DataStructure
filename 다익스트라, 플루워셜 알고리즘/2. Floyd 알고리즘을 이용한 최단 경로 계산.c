// Floyd : 모든 정점 사이의 최단경로를 찾음
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100

// 그래프 구조체
typedef struct GraphType {
	int n; // 정점
	int weight[MAX_VERTICES][MAX_VERTICES]; // 가중치
} GraphType;
int distance[MAX_VERTICES][MAX_VERTICES]; // 최단경로가 알려진 정점들만을 이용한 다른 정점들까지의 최단 경로 길이
// 플루이드 워셜 알고리즘
void floyd(GraphType* g)
{
	int i, j, k;
	for (i = 0; i < g->n; i++)
		for (j = 0; j < g->n; j++)
			distance[i][j] = g->weight[i][j]; // 모든 가중치를 초기화
	for (k = 0; k < g->n; k++) {
		for (i = 0; i < g->n; i++)
			for (j = 0; j < g->n; j++)
				if (distance[i][k] + distance[k][j] < distance[i][j]) /*3중 반복문을 이용한 갱신과정*/
					distance[i][j] = distance[i][k] +
					distance[k][j];
	}
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
	floyd(&g); // 플루이드 알고리즘 함수
	for (i = 0; i < g.n; i++) {
		for (j = 0; j < g.n; j++) {
			printf("%d ", distance[i][j]); // 모든 정점 쌍의 최단 경로 계산
		}
		printf("\n");
	}
	return 0;
}