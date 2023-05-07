#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000
int list[MAX_SIZE];
int sorted[MAX_SIZE];

void merge(int list[], int left, int mid, int right)
{
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;
    /* ���� ���ĵ� list�� �պ� */
    while (i <= mid && j <= right) {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if (i > mid) { /* ���� �ִ� ���ڵ��� �ϰ� ���� */
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    }
    else {/* ���� �ִ� ���ڵ��� �ϰ� ���� */
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];
    }
    /* sorted�� list�� ����*/
    for (l = left; l <= right; l++)
        list[l] = sorted[l];
}

// �պ�����
void merge_sort(int list[], int left, int right)
{
    if (left < right) {
        int mid = (left + right) / 2; // �߰��� �������� ������ mid��
        merge_sort(list, left, mid); // ���ʺκ� ��� 2���� ����
        merge_sort(list, mid + 1, right); // �����ʺκ� ��� 2���� ����
        merge(list, left, mid, right); // �����ϰ� ��ħ
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

    merge_sort(list, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d\n", list[i]);
    return 0;
}