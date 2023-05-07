#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000000

int list[MAX_SIZE];

// ������ (�������� ����)
void inc_insertion_sort(int list[], int first, int last, int gap)
{
    int i, j, key;
    for (i = first + gap; i <= last; i = i + gap) // �������Ŀ� ����ϰ� ���ݸ� �߰�
    {
        key = list[i]; // Ű�� ����
        for (j = i - gap; j >= first && key < list[j]; j = j - gap) // ����
        {
            list[j + gap] = list[j];
        }
        list[j + gap] = key;
    }
}

void shell_sort(int list[], int n)
{
    int i, gap;
    for (gap = n / 2; gap > 0; gap = gap / 2) // ������ �ٿ�����
    {
        if (gap % 2 == 0) // ¦����
            gap++; // Ȧ���� �ٲ��� ( ȿ���� )
        for (i = 0; i < gap; i++) // ���ݰ�����ŭ �ݺ�
            inc_insertion_sort(list, i, n - 1, gap); // ����
    }
}

int main(void)
{
    int n;
    int i = 0, input;

    scanf("%d", &n);

    while (scanf("%d", &input) != EOF) {
        list[i] = input;
        i++;
    }

    shell_sort(list, n);

    for (int i = 0; i < n; i++)
        printf("%d\n", list[i]);
    return 0;
}