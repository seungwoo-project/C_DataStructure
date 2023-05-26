#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int value[MAX_SIZE];

// 오름차순 정렬
int compare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 < num2)
        return -1;
    else if (num1 > num2)
        return 1;
    else
        return 0;
}



int main() {
    int n;
    int i;
    int total = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value[i]);
    }
     
    qsort(value, n, sizeof(int), compare); // 오름차순 정렬

    // 이전의 더해진 값에서 자기자신 더하기 버블정렬느낌으로 비슷하게
    for (i = 0; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            total += value[j];
        }
    }
    printf("%d", total);
}