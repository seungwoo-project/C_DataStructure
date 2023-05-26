#include <stdio.h>
#define INT_MAX 10000
#define MAXSIZE 1000
int C[MAXSIZE][MAXSIZE];
int matrixMult_DP(int d[], int n) {
    int i, j, k, L, temp;
    for (i = 1; i <= n; i++)
        C[i][i] = 0; // 연속된 행렬이 아니므로 다 0
    for (L = 1; L <= n - 1; L++) {
        for (i = 1; i <= n - L; i++) {
            j = i + L; // 대각선으로 내려가는 인덱스
            C[i][j] = INT_MAX; // 일단 다 맥스값으로 해준다

            // i부터 j까지의 행렬을 곱하는 최소비용
            for (k = i; k <= j - 1; k++) { 

                // 행렬값을 구해주는 과정
                temp = C[i][k] + C[k + 1][j] + d[i - 1] * d[k] * d[j];

                //갱신 과정
                if (temp < C[i][j])
                    C[i][j] = temp;
            }
        }
    }

    // 1부터 n-1까지 연속행렬 최소 비용 반환
    return C[1][n - 1];
}

int main(void) {
    int n;
    int d[MAXSIZE];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }

    printf("%d", matrixMult_DP(d, n));
}