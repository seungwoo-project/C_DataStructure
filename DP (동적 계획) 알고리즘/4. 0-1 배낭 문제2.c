#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define INF 1e9

int K[MAX_SIZE];
int knapsack(int c, int wt[], int val[], int n) {
    for (int i = 1; i <= c; i++)
        K[i] = 0; // 일단 0으로 다 설정

    K[0] = 0; // 배낭 용량이 0 이면 아무것도 들어갈 수 없으니 0
    for (int i = 1; i <= n; i++) { // 물건의 무게들
        for (int j = c; j >= 1; j--) // 배낭의 무게를 최대에서부터 1까지 담게되면 물건중복이 막아짐 갱신
            if (wt[i] <= j && (K[j - wt[i]] + val[i] > K[j])) // 배낭에 물건이 들어갈 수 있는데 1개밖에 못들어감 비교  
                K[j] = K[j - wt[i]] + val[i];
    }
    return K[c]; // 가방무게가 최대일 때 가치 리턴
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