#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];

// 퀵정렬
void quick_sort(int list[], int left, int right)
{
    if (left < right) {
        int q = partition(list, left, right); // 정렬하는 곳
        quick_sort(list, left, q - 1); // 피벗부터 작은애 까지 정렬
        quick_sort(list, q + 1, right); // 피벗보다 큰애 정렬
    }
}

int partition(int list[], int left, int right)
{
    int pivot, temp;
    int low, high;
    low = left;
    high = right + 1;
    pivot = list[left]; // 피벗을 가장 왼쪽에 있는 걸로 기준삼음
    do {
        do {
            low++;
        } while (low <= right && list[low] < pivot); // low가 피벗보다 큰 값 만날때까지
        do {
            high--;
        } while (high >= left && list[high] > pivot); // high가 피벗보다 작은 값 만날때까지
        if (low < high) SWAP(list[low], list[high], temp); // low가 high보다 작다면 둘이 바꿔라 
    } while (low < high); // low가 high보다 크거나 같다면 빠져나옴
    SWAP(list[left], list[high], temp); // 피벗과 high의 값과 바꿈
    return high;
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

    quick_sort(list, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d\n", list[i]);
    return 0;
}