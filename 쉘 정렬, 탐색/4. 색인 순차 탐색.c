#include <stdio.h>
#include <stdlib.h>
#define INDEX_SIZE 10
#define MAX_SIZE 1000000

int list[MAX_SIZE];

typedef struct {
    int key;
    int index;
} itable;
itable index_list[INDEX_SIZE];
// ����Ž��
int seq_search(int key, int low, int high)
{
    int i;
    for (i = low; i <= high; i++) // Ž��
        if (list[i] == key) // keyã����
            return i; // �ε��� ��ȯ
    return -1; // Ž���� �ȵǸ� -1��ȯ 
}
// ����
int index_search(int key, int n)
{
    int i, low, high;
    if (key<list[0] || key>list[n - 1]) // key�� �������� �����
        return -1; // -1 ��ȯ
    for (i = 0; i < INDEX_SIZE; i++)
        if (index_list[i].key <= key && index_list[i + 1].key > key) // key�� �ε�������Ʈ�� �ȿ� ������
            break; // �극��ũ
    if (i == INDEX_SIZE) { // i�� �ε����������̸�
        low = index_list[i - 1].index; // ����
        high = n;
    }
    else { // �� ��
        low = index_list[i].index; // ����
        high = index_list[i + 1].index;
    }
    return seq_search(key, low, high); // ����Ž������
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


    for (int i = 0; i < 10; i++) {
        index_list[i].key = list[n / 10 * i];
        index_list[i].index = n / 10 * i;
    }
    printf("%d", index_search(key, n));

    return 0;
}