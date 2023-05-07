#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000

int n;
int list[MAX_SIZE] = { -1, };

// 삽입정렬 -> 정렬되어야 하는 애를 앞 애들과 비교 
void insertion_sort(int list[], int n)
{
    int i, j, key;
    // 인덱스 1부터 마지막까지 why? 앞 애들과 비교 할것이기 때문
    for (i = 1; i < n; i++) {
        key = list[i];
        for (j = i - 1; j >= 0 && list[j] > key; j--) /* i인덱스의 전부터 0인덱스까지 앞으로 갈 것임 그리고 j의인덱스 값이 더 작다면 둘의 위치를 바꿈 */
            list[j + 1] = list[j]; // 뒤에 값을 앞의 값에 덮어씌우고
        list[j + 1] = key; // 반복문 빠져나오는 과정에서 j-- 가 되었으니 이런 식이 나옴
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

    insertion_sort(list, n);

    for (int i = 0; i < n; i++)
        printf("%d\n", list[i]);
    return 0;
}