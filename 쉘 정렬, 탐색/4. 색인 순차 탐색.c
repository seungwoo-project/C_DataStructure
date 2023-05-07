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
// 순차탐색
int seq_search(int key, int low, int high)
{
    int i;
    for (i = low; i <= high; i++) // 탐색
        if (list[i] == key) // key찾으면
            return i; // 인덱스 반환
    return -1; // 탐색이 안되면 -1반환 
}
// 색인
int index_search(int key, int n)
{
    int i, low, high;
    if (key<list[0] || key>list[n - 1]) // key가 범위에서 벗어나면
        return -1; // -1 반환
    for (i = 0; i < INDEX_SIZE; i++)
        if (index_list[i].key <= key && index_list[i + 1].key > key) // key가 인덱스리스트값 안에 있으면
            break; // 브레이크
    if (i == INDEX_SIZE) { // i가 인덱스사이즈이면
        low = index_list[i - 1].index; // 색인
        high = n;
    }
    else { // 그 외
        low = index_list[i].index; // 색인
        high = index_list[i + 1].index;
    }
    return seq_search(key, low, high); // 순차탐색진행
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