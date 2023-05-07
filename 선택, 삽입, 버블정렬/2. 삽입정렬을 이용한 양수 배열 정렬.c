#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000

int n;
int list[MAX_SIZE] = { -1, };

// �������� -> ���ĵǾ�� �ϴ� �ָ� �� �ֵ�� �� 
void insertion_sort(int list[], int n)
{
    int i, j, key;
    // �ε��� 1���� ���������� why? �� �ֵ�� �� �Ұ��̱� ����
    for (i = 1; i < n; i++) {
        key = list[i];
        for (j = i - 1; j >= 0 && list[j] > key; j--) /* i�ε����� ������ 0�ε������� ������ �� ���� �׸��� j���ε��� ���� �� �۴ٸ� ���� ��ġ�� �ٲ� */
            list[j + 1] = list[j]; // �ڿ� ���� ���� ���� ������
        list[j + 1] = key; // �ݺ��� ���������� �������� j-- �� �Ǿ����� �̷� ���� ����
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

    insertion_sort(list, n);

    for (int i = 0; i < n; i++)
        printf("%d\n", list[i]);
    return 0;
}