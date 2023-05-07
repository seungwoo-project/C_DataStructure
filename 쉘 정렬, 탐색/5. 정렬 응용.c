#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000000

int list[MAX_SIZE];
int answer[MAX_SIZE];
int seq_search(int high, int key, int key2, int version)
{
    int i, j;
    // case 1번일때
    if (version == 1)
    {
        for (i = 0; i <= high; i++) // 탐색
            if (list[i] >= key) // key보다 크거나 같을때
                return high - i; // 마지막인덱스 - 선택된인덱스
        return 0; // key조건에 해당 안되면 0반환
    }
    // case 2번일때
    if (version == 2)
    {
        for (i = 0; i <= high; i++) // 탐색
            if (list[i] > key) // key보다 클때
                return high - i; // 마지막인덱스 - 선택된인덱스
        return 0; // key조건에 해당 안되면 0반환
    }
    // case 3번일때
    if (version == 3)
    {
        for (i = 0; i <= high; i++) { // 탐색
            if (list[i] >= key) { // list[i]가 key보다 크거나 같을때 
                for (j = high - 1; j > i; j--) { // 뒤에서 부터 탐색
                    if (list[j] <= key2) { // list[j]가 key보다 작거나 같을때
                        break; // 브레이크 -> i와 j 인덱스 저장되어있음
                    }
                }
                if (i == j) // i와 j가 같을때 ex) 3 4 4
                    return j - i; // j-i
                else // 그렇지 않으면
                    return j - i + 1;  // j인덱스 - i인덱스
            }

        }
        return 0; // 탐색이 되지 않으면 0 반환

    }


}

int main(void)
{
    int n, num, version;
    int key = 0, key2 = 0;;
    int input;

    scanf("%d %d", &n, &num); // n : 양수의 개수 , num : 질의 개수

    for (int i = 0; i < n; i++) { // 양수의 개수 만큼 리스트 값 입력
        scanf("%d", &input);
        list[i] = input;
    }

    for (int i = 0; i < num; i++) { // 질의의 개수 만큼 반복
        scanf("%d", &version); // case 1,2 : key  , case 3 : key , key2 
        if (version == 3) {
            scanf("%d %d", &key, &key2);
            printf("%d\n", seq_search(n, key, key2, version));
        }
        else {
            scanf("%d", &key);
            printf("%d\n", seq_search(n, key, 0, version));
        }
    }

    return 0;
}