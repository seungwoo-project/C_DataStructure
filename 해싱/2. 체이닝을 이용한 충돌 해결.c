#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int size;

// ����ü ����
typedef struct {
    int key;
} element;

// ���Ḯ��Ʈ ����
struct list
{
    element item;
    struct list* link;
};

// ���Ḯ��Ʈ �ؽ����̺� ����
struct list* hash_table[MAX_SIZE];

int hash_function(int key)
{
    // ���̺��� ũ��� ������ �������� ��ȯ
    return key % size;
}

// �ؽ����̺� ���Ḯ��Ʈ�� �߰��ϴ� �Լ�
void hash_chain_add(element item, struct list* ht[])
{
    int hash_value = hash_function(item.key); // ������ �� ���� �ʱ�ȭ
    struct list* ptr; // �߰��� ���Ḯ��Ʈ
    struct list* node_before = NULL; // ���� ���� null �� �ʱ�ȭ
    struct list* node = ht[hash_value]; // for���� �ʱⰪ

    for (; node; node_before = node, node = node->link) { // ��尡 null�� �ƴϸ� �ݺ�
        if (node->item.key == item.key) { // �浹 ����
            printf("-1\n");
            exit(0);
        }
    }
    ptr = (struct list*)malloc(sizeof(struct list)); // ���Ḯ��Ʈ ����
    ptr->item = item; // �� ����
    ptr->link = NULL; // ��ũ null
    if (node_before) // ���� ��尡 null�� �ƴϸ�
        node_before->link = ptr;  // ptr���Ḯ��Ʈ�� ����
    else
        ht[hash_value] = ptr; // null�̸� �迭�� ���Ḯ��Ʈ �߰�
}

// ü�̴� ��� �Լ�
void hash_chain_print(struct list* ht[])
{
    struct list* node;
    for (int i = 0; i < size; i++) {
        for (node = ht[i]; node; node = node->link) {
            printf("%d\n", node->item.key);
        }
    }
}


int main(void)
{
    int n;
    element num;
    scanf("%d %d", &size, &n); // �ؽ����̺� ũ��� �� ����

    for (int i = 0; i < n; i++) {
        scanf("%d", &num.key); // �� ����
        hash_chain_add(num, hash_table); // ���Ḯ��Ʈ�� �߰�
    }
    hash_chain_print(hash_table); // ���
    return 0;
}