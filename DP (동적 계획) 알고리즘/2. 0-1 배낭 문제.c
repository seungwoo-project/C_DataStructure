#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100


int K[MAX_SIZE][MAX_SIZE];
int knapsack(int c, int wt[], int val[], int n) {
    for (int i = 0; i <= n; i++)
        K[i][0] = 0; // 배낭의 용량이 0일 때는 물건을 넣을 수 없으니 다 0
    for (int w = 0; w <= c; w++)
        K[0][w] = 0; // 물건이 0이란 어떤 물건도 고려하지 않을 때
    for (int i = 1; i <= n; i++) // 물건에 대한 무게와 가치
        for (int w = 1; w <= c; w++) // 배낭 무게가 1씩 커진다 가정하고 배낭의 용량까지 1씩 증가
            if (wt[i] > w) // 물건의 무게가 배낭 무게보다 크다면 안들어감
                K[i][w] = K[i - 1][w]; 
            else // 물건의 무게가 배낭 무게에 들어간다면
                // 물건을 배낭에서 빼내고 다른 물건을 넣었을 때의 가치가 더 높다면 그 물건을 넣음
                K[i][w] = (((K[i - 1][w]) > (K[i - 1][w - wt[i]] + val[i])) ? (K[i - 1][w]) : (K[i - 1][w - wt[i]] + val[i]));
    return K[n][c];
}

int main(void) {
    int n, c;

    scanf("%d %d", &n, &c); // 물건의 개수 n과 배냥의 용량 c가 주어짐

    int wt[MAX_SIZE]; // 각 물건의 무게
    int val[MAX_SIZE]; // 각 물건의 가치

    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &wt[i], &val[i]); // 각 물건에 대한 무게와 가치가 주어짐
    }

    int result = knapsack(c, wt, val, n);
    printf("%d", result);
}