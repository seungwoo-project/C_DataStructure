#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int size;
// ����ü ����
typedef struct
{
    int key; // ��
} element;

element hash_table[MAX_SIZE]; // ����ü �ؽ����̺����迭 �ʱ�ȭ

// ���̺� �ʱ�ȭ
void init_table(element ht[]) {
    int i;
    for (i = 0; i < size; i++) {
        ht[i].key = -1; // �ؽ����̺�迭�� ���� -1�� �ʱ�ȭ
    }
}

int hash_function(int key)
{
    // ���̺��� ũ��� ������ �������� ��ȯ
    return key % size;
}

// �ؽ����̺� �߰� �Լ�
void hash_lp_add(element item, element ht[])
{
    int i, hash_value;
    hash_value = i = hash_function(item.key);

    // �ؽ����̺� Ű ���� -1�� �ƴ϶�� ��
    while (!(ht[i].key == -1)) {
        if (item.key == ht[i].key) { // �浹�� �߻�!
            printf("-1\n");
            exit(0);
        }
        i = (i + 1) % size; // ���� ť�� ����� ����
        if (i == hash_value) { // ��������
            printf("-2\n");
            exit(0);
        }
    }
    ht[i] = item; // �ؽ����̺� �� ����
}

// �ؽ����̺� �� ���
void hash_lp_print(element ht[])
{
    int i;
    for (i = 0; i < size; i++)
        if (ht[i].key != -1)
            printf("%d\n", ht[i].key);
}

int main(void)
{
    int n;
    element num;

    scanf("%d %d", &size, &n); // �ؽ����̺��� ũ��� ����� ����
    init_table(hash_table); // �ؽ����̺� �ʱ�ȭ����

    for (int i = 0; i < n; i++) {
        scanf("%d", &num.key); // �ؽ����̺� �� ��
        hash_lp_add(num, hash_table); // �ؽ����̺� ���� �߰��ϴ� �Լ�
    }

    hash_lp_print(hash_table); // �ؽ����̺� ����Լ�
    return 0;
}