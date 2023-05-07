#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int n;
int list[MAX_SIZE] = { -1, };
// �������� -> �ִ밪���� ������ ����
void bubble_sort(int list[], int n)
{
    int i, j, temp;
    int is_sorted;
    // ������ �ε����� �񱳸� ���ص���
    for (i = n - 1; i > 0; i--) {
        is_sorted = 1;
        for (j = 0; j < i; j++) // �տ��� ���� �������鼭 ��������
            if (list[j] > list[j + 1]) { // �� �ε����� �� �ε������� ũ�ٸ� �ٲ��� -> �ִ밪�� �ڷιи�
                SWAP(list[j], list[j + 1], temp);
                is_sorted = 0;
            }
        if (is_sorted) break;
    }
}

int main(void)
{
    int i = 0, input;

    scanf("%d", &n);

    while (scanf("%d", &input) != EOF) {
        list[i] = input;
        i++;
    }

    bubble_sort(list, n);

    for (int i = 0; i < n; i++)
        printf("%d\n", list[i]);
    return 0;
}