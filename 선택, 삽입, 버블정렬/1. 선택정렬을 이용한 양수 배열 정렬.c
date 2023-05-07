#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) ) // swap함수 정의 

int n;
int list[MAX_SIZE] = { -1, };

// 선택정렬
void selection_sort(int list[], int n)
{
    int i, j, least, temp;
    // i가 0번째 인덱스부터 마지막 인덱스 전까지 반복
    for (i = 0; i < n - 1; i++) {
        least = i; // i를 최소로 지정
        for (j = i + 1; j < n; j++) // i의 다음 인덱스 부터 비교
            if (list[j] < list[least]) // 만약 j의 인덱스가 least인덱스 보다 작다면 최소는 j의 인덱스
                least = j;
        SWAP(list[i], list[least], temp); // 서로 바꿈
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

    selection_sort(list, n);

    for (int i = 0; i < n; i++)
        printf("%d\n", list[i]);
    return 0;
}
