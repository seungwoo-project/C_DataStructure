#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];

// ������
void quick_sort(int list[], int left, int right)
{
    if (left < right) {
        int q = partition(list, left, right); // �����ϴ� ��
        quick_sort(list, left, q - 1); // �ǹ����� ������ ���� ����
        quick_sort(list, q + 1, right); // �ǹ����� ū�� ����
    }
}

int partition(int list[], int left, int right)
{
    int pivot, temp;
    int low, high;
    low = left;
    high = right + 1;
    pivot = list[left]; // �ǹ��� ���� ���ʿ� �ִ� �ɷ� ���ػ���
    do {
        do {
            low++;
        } while (low <= right && list[low] < pivot); // low�� �ǹ����� ū �� ����������
        do {
            high--;
        } while (high >= left && list[high] > pivot); // high�� �ǹ����� ���� �� ����������
        if (low < high) SWAP(list[low], list[high], temp); // low�� high���� �۴ٸ� ���� �ٲ�� 
    } while (low < high); // low�� high���� ũ�ų� ���ٸ� ��������
    SWAP(list[left], list[high], temp); // �ǹ��� high�� ���� �ٲ�
    return high;
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

    quick_sort(list, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d\n", list[i]);
    return 0;
}