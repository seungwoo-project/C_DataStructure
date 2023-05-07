#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000000

int list[MAX_SIZE];
// 개선된 순차탐색 
int seq_search(int key, int low, int high)
{
    int i;
    list[high + 1] = key; // high + 1 에 key를 넣음 

    for (i = low; list[i] != key; i++); // key를 찾으면
    if (i == high + 1) // 해당인덱스와 마지막인덱스가 같으면
        return -1; // -1 반환
    else // 아니면
        return i; // 해당인덱스 반환
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