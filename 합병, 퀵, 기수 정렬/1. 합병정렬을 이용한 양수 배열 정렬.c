#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000
int list[MAX_SIZE];
int sorted[MAX_SIZE];

void merge(int list[], int left, int mid, int right)
{
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;
    /* 분할 정렬된 list의 합병 */
    while (i <= mid && j <= right) {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if (i > mid) { /* 남아 있는 레코드의 일괄 복사 */
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    }
    else {/* 남아 있는 레코드의 일괄 복사 */
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];
    }
    /* sorted를 list로 복사*/
    for (l = left; l <= right; l++)
        list[l] = sorted[l];
}

// 합병정렬
void merge_sort(int list[], int left, int right)
{
    if (left < right) {
        int mid = (left + right) / 2; // 중간을 기준으로 나누는 mid값
        merge_sort(list, left, mid); // 왼쪽부분 계속 2개로 나눔
        merge_sort(list, mid + 1, right); // 오른쪽부분 계속 2개로 나눔
        merge(list, left, mid, right); // 정렬하고 합침
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

    merge_sort(list, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d\n", list[i]);
    return 0;
}