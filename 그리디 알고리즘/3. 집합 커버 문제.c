#include <stdio.h>
#define MAX_SIZE 10
#define MAX_M 100
#define MAX_N 100

int n, m;
int covered[MAX_N];
int sets[MAX_M][MAX_N];
int SetCover() {

    while (1) {
        // 가장 많은 원소를 커버하는 집합의 원소 수
        int max_count = 0;
        // 가장 많은 원소를 커버하는 집합의 인덱스
        int max_set = -1;
        for (int i = 0; i < m; i++) {
            int cur_count = 0;
            for (int j = 0; j < n; j++) {
                if (sets[i][j] != -1 && !covered[sets[i][j]]) { // 원소의 개수를 세어보는 과정 -> 2차원배열이 -1아닌 실제 값으로 초기화 되어있고 커버가 안되어있다면
                    cur_count++;
                }
            }
            if (cur_count > max_count) { // 가장 많은 원소를 가진 집합의 인덱스를 찾는과정
                max_count = cur_count;
                max_set = i;
            }

        }
        if (max_count == 0)
            break;
        printf("%d\n", max_set);
        // 집합에서 빼는과정
        for (int j = 0; j < n; j++) {
            if (sets[max_set][j] != -1) { // 2차원배열에 실제값이있다면
                covered[sets[max_set][j]] = 1; // 집합 커버에 추가
            }
        }
    }
}


int main(void) {
    int count, value;
    // 2차원 배열 다 -1로 초기화
    for (int i = 0; i < MAX_M; i++) {
        for (int j = 0; j < MAX_N; j++)
            sets[i][j] = -1;

    }
    // 원소의 개수 n 집합의 개수 m
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) { // 집합 개수만큼 반복
        scanf("%d", &count);
        for (int j = 0; j < count; j++) { // count만큼 반복
            scanf("%d", &value);
            sets[i][j] = value; // 입력값 대입
        }
    }

    SetCover();
}