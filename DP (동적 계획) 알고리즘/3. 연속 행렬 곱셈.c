#include <stdio.h>
#define INT_MAX 10000
#define MAXSIZE 1000
int C[MAXSIZE][MAXSIZE];
int matrixMult_DP(int d[], int n) {
    int i, j, k, L, temp;
    for (i = 1; i <= n; i++)
        C[i][i] = 0; // ���ӵ� ����� �ƴϹǷ� �� 0
    for (L = 1; L <= n - 1; L++) {
        for (i = 1; i <= n - L; i++) {
            j = i + L; // �밢������ �������� �ε���
            C[i][j] = INT_MAX; // �ϴ� �� �ƽ������� ���ش�

            // i���� j������ ����� ���ϴ� �ּҺ��
            for (k = i; k <= j - 1; k++) { 

                // ��İ��� �����ִ� ����
                temp = C[i][k] + C[k + 1][j] + d[i - 1] * d[k] * d[j];

                //���� ����
                if (temp < C[i][j])
                    C[i][j] = temp;
            }
        }
    }

    // 1���� n-1���� ������� �ּ� ��� ��ȯ
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