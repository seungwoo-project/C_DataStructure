#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int size;
// 구조체 선언
typedef struct
{
    int key; // 값
} element;

element hash_table[MAX_SIZE]; // 구조체 해시테이블변수배열 초기화

// 테이블 초기화
void init_table(element ht[]) {
    int i;
    for (i = 0; i < size; i++) {
        ht[i].key = -1; // 해시테이블배열의 값을 -1로 초기화
    }
}

int hash_function(int key)
{
    // 테이블의 크기로 나누어 나머지를 반환
    return key % size;
}

// 해시테이블 추가 함수
void hash_lp_add(element item, element ht[])
{
    int i, hash_value;
    hash_value = i = hash_function(item.key);

    // 해시테이블 키 값이 -1이 아니라면 비교
    while (!(ht[i].key == -1)) {
        if (item.key == ht[i].key) { // 충돌이 발생!
            printf("-1\n");
            exit(0);
        }
        i = (i + 1) % size; // 원형 큐와 비슷한 원리
        if (i == hash_value) { // 가득차면
            printf("-2\n");
            exit(0);
        }
    }
    ht[i] = item; // 해시테이블에 값 대입
}

// 해시테이블 값 출력
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

    scanf("%d %d", &size, &n); // 해싱테이블의 크기와 양수의 개수
    init_table(hash_table); // 해싱테이블 초기화과정

    for (int i = 0; i < n; i++) {
        scanf("%d", &num.key); // 해싱테이블에 들어갈 값
        hash_lp_add(num, hash_table); // 해싱테이블에 값을 추가하는 함수
    }

    hash_lp_print(hash_table); // 해싱테이블 출력함수
    return 0;
}