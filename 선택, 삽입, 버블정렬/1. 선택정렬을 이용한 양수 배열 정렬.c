#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) ) // swap�Լ� ���� 

int n;
int list[MAX_SIZE] = { -1, };

// ��������
void selection_sort(int list[], int n)
{
    int i, j, least, temp;
    // i�� 0��° �ε������� ������ �ε��� ������ �ݺ�
    for (i = 0; i < n - 1; i++) {
        least = i; // i�� �ּҷ� ����
        for (j = i + 1; j < n; j++) // i�� ���� �ε��� ���� ��
            if (list[j] < list[least]) // ���� j�� �ε����� least�ε��� ���� �۴ٸ� �ּҴ� j�� �ε���
                least = j;
        SWAP(list[i], list[least], temp); // ���� �ٲ�
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

    selection_sort(list, n);

    for (int i = 0; i < n; i++)
        printf("%d\n", list[i]);
    return 0;
}
