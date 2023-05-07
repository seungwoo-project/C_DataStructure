#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000000

int list[MAX_SIZE];

int search_binary(int key, int low, int high)
{
    int middle;
    while (low <= high) { // ��������
        middle = (low + high) / 2;
        if (key == list[middle]) // key�� �ٷ� ã����
            return middle; // �ε��� ����
        else if (key > list[middle]) // key�� �߰������� ũ��
            low = middle + 1; // low�� �߰��� + 1 ���� �ٽ� Ž��
        else // �ƴϸ�
            high = middle - 1; // high�� �߰��� - 1 ���� �ٽ� Ž��
    }
    return -1;
}

int main(void)
{
    int n, key;
    int i = 0, input;

    scanf("%d %d", &n, &key);

    while (scanf("%d", &input) != EOF) {
        list[i] = input;
        i++;
    }

    printf("%d", search_binary(key, 0, n));

    return 0;
}