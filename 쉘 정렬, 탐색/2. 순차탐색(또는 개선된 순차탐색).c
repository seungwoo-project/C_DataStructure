#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000000

int list[MAX_SIZE];
// ������ ����Ž�� 
int seq_search(int key, int low, int high)
{
    int i;
    list[high + 1] = key; // high + 1 �� key�� ���� 

    for (i = low; list[i] != key; i++); // key�� ã����
    if (i == high + 1) // �ش��ε����� �������ε����� ������
        return -1; // -1 ��ȯ
    else // �ƴϸ�
        return i; // �ش��ε��� ��ȯ
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

    printf("%d", seq_search(key, 0, n));

    return 0;
}