#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100


int K[MAX_SIZE][MAX_SIZE];
int knapsack(int c, int wt[], int val[], int n) {
    for (int i = 0; i <= n; i++)
        K[i][0] = 0; // �賶�� �뷮�� 0�� ���� ������ ���� �� ������ �� 0
    for (int w = 0; w <= c; w++)
        K[0][w] = 0; // ������ 0�̶� � ���ǵ� ������� ���� ��
    for (int i = 1; i <= n; i++) // ���ǿ� ���� ���Կ� ��ġ
        for (int w = 1; w <= c; w++) // �賶 ���԰� 1�� Ŀ���� �����ϰ� �賶�� �뷮���� 1�� ����
            if (wt[i] > w) // ������ ���԰� �賶 ���Ժ��� ũ�ٸ� �ȵ�
                K[i][w] = K[i - 1][w]; 
            else // ������ ���԰� �賶 ���Կ� ���ٸ�
                // ������ �賶���� ������ �ٸ� ������ �־��� ���� ��ġ�� �� ���ٸ� �� ������ ����
                K[i][w] = (((K[i - 1][w]) > (K[i - 1][w - wt[i]] + val[i])) ? (K[i - 1][w]) : (K[i - 1][w - wt[i]] + val[i]));
    return K[n][c];
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