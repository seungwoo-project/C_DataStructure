#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000000

int list[MAX_SIZE];

// 쉘정렬 (삽입정렬 개선)
void inc_insertion_sort(int list[], int first, int last, int gap)
{
    int i, j, key;
    for (i = first + gap; i <= last; i = i + gap) // 삽입정렬와 비슷하게 간격만 추가
    {
        key = list[i]; // 키값 지정
        for (j = i - gap; j >= first && key < list[j]; j = j - gap) // 정렬
        {
            list[j + gap] = list[j];
        }
        list[j + gap] = key;
    }
}

void shell_sort(int list[], int n)
{
    int i, gap;
    for (gap = n / 2; gap > 0; gap = gap / 2) // 간격을 줄여나감
    {
        if (gap % 2 == 0) // 짝수면
            gap++; // 홀수로 바꿔줌 ( 효율성 )
        for (i = 0; i < gap; i++) // 간격개수만큼 반복
            inc_insertion_sort(list, i, n - 1, gap); // 정렬
    }
}

int main(void)
{
    int n;
    int i = 0, input;

    scanf("%d", &n);

    while (scanf("%d", &input) != EOF) {
        list[i] = input;
        i++;
    }

    shell_sort(list, n);

    for (int i = 0; i < n; i++)
        printf("%d\n", list[i]);
    return 0;
}