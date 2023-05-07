#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000000

int list[MAX_SIZE];

int search_binary(int key, int low, int high)
{
    int middle;
    while (low <= high) { // 종료조건
        middle = (low + high) / 2;
        if (key == list[middle]) // key를 바로 찾으면
            return middle; // 인덱스 리턴
        else if (key > list[middle]) // key가 중간값보다 크면
            low = middle + 1; // low가 중간값 + 1 부터 다시 탐색
        else // 아니면
            high = middle - 1; // high가 중간값 - 1 부터 다시 탐색
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