#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int n;
int list[MAX_SIZE] = { -1, };
// 버블정렬 -> 최대값부터 오른쪽 정렬
void bubble_sort(int list[], int n)
{
    int i, j, temp;
    int is_sorted;
    // 마지막 인덱스는 비교를 안해도됨
    for (i = n - 1; i > 0; i--) {
        is_sorted = 1;
        for (j = 0; j < i; j++) // 앞에서 부터 지나가면서 정렬해줌
            if (list[j] > list[j + 1]) { // 앞 인덱스가 뒤 인덱스보다 크다면 바꿔줌 -> 최대값이 뒤로밀림
                SWAP(list[j], list[j + 1], temp);
                is_sorted = 0;
            }
        if (is_sorted) break;
    }
}

int main(void)
{
    int i = 0, input;

    scanf("%d", &n);

    while (scanf("%d", &input) != EOF) {
        list[i] = input;
        i++;
    }

    bubble_sort(list, n);

    for (int i = 0; i < n; i++)
        printf("%d\n", list[i]);
    return 0;
}