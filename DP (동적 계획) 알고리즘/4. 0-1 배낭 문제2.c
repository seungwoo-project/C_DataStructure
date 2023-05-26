#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define INF 1e9

int K[MAX_SIZE];
int knapsack(int c, int wt[], int val[], int n) {
    for (int i = 1; i <= c; i++)
        K[i] = 0; // �ϴ� 0���� �� ����

    K[0] = 0; // �賶 �뷮�� 0 �̸� �ƹ��͵� �� �� ������ 0
    for (int i = 1; i <= n; i++) { // ������ ���Ե�
        for (int j = c; j >= 1; j--) // �賶�� ���Ը� �ִ뿡������ 1���� ��ԵǸ� �����ߺ��� ������ ����
            if (wt[i] <= j && (K[j - wt[i]] + val[i] > K[j])) // �賶�� ������ �� �� �ִµ� 1���ۿ� ���� ��  
                K[j] = K[j - wt[i]] + val[i];
    }
    return K[c]; // ���湫�԰� �ִ��� �� ��ġ ����
}

int main(void) {
    int n, c;

    scanf("%d %d", &n, &c); // ������ ���� n�� ����� �뷮 c�� �־���

    int wt[MAX_SIZE]; // �� ������ ����
    int val[MAX_SIZE]; // �� ������ ��ġ

    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &wt[i], &val[i]); // �� ���ǿ� ���� ���Կ� ��ġ�� �־���
    }

    int result = knapsack(c, wt, val, n);
    printf("%d", result);
}