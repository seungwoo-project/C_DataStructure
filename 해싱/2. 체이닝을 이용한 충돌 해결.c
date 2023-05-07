#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int size;

// 구조체 선언
typedef struct {
    int key;
} element;

// 연결리스트 선언
struct list
{
    element item;
    struct list* link;
};

// 연결리스트 해시테이블 선언
struct list* hash_table[MAX_SIZE];

int hash_function(int key)
{
    // 테이블의 크기로 나누어 나머지를 반환
    return key % size;
}

// 해시테이블 연결리스트로 추가하는 함수
void hash_chain_add(element item, struct list* ht[])
{
    int hash_value = hash_function(item.key); // 나머지 값 으로 초기화
    struct list* ptr; // 추가할 연결리스트
    struct list* node_before = NULL; // 이전 노드는 null 로 초기화
    struct list* node = ht[hash_value]; // for문의 초기값

    for (; node; node_before = node, node = node->link) { // 노드가 null이 아니면 반복
        if (node->item.key == item.key) { // 충돌 방지
            printf("-1\n");
            exit(0);
        }
    }
    ptr = (struct list*)malloc(sizeof(struct list)); // 연결리스트 생성
    ptr->item = item; // 값 대입
    ptr->link = NULL; // 링크 null
    if (node_before) // 이전 노드가 null이 아니면
        node_before->link = ptr;  // ptr연결리스트에 연결
    else
        ht[hash_value] = ptr; // null이면 배열에 연결리스트 추가
}

// 체이닝 출력 함수
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
    scanf("%d %d", &size, &n); // 해시테이블 크기와 값 설정

    for (int i = 0; i < n; i++) {
        scanf("%d", &num.key); // 값 대입
        hash_chain_add(num, hash_table); // 연결리스트로 추가
    }
    hash_chain_print(hash_table); // 출력
    return 0;
}