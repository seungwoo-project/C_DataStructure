#include <stdio.h>
#define MAX_SIZE 1000000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE]; // 기존 리스트
int distance[MAX_SIZE]; // 기준 n과 list원소들간의 차
int abs(int x) {
    return (x < 0) ? -x : x;
}
// 퀵정렬
void quick_sort(int list[], int left, int right)
{
    if (left < right) {
        int q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
    }
}
// 정렬부분
int partition(int distance[], int left, int right)
{
    int pivot, temp;
    int low, high;
    low = left;
    high = right + 1;
    pivot = distance[left];
    do {
        do {
            low++;
        } while (low <= right && distance[low] < pivot);
        do {
            high--;
        } while (high >= left && distance[high] > pivot);
        // distance배열은 기준n과 list원소간에 차이이다. distance와 list는 관계가 맺어져있다. 그래서 정렬을 할 때 같은 인덱스 번호가 매치 되도록 distance배열만아니라 list배열도 같이 정렬 시켜주어야한다.
        if (low < high) { SWAP(distance[low], distance[high], temp); SWAP(list[low], list[high], temp); }
    } while (low < high);
    //똑같이 정렬
    SWAP(distance[left], distance[high], temp);
    SWAP(list[left], list[high], temp);
    return high;
}


int main(void)
{
    int num, n;
    int i = 0, input;
    int tmp;
    scanf("%d %d", &num, &n);
    for (int i = 0; i < num; i++) {
        scanf("%d", &list[i]);
    }
    // 기준n과 리스트간에 차이를 새로운 distance라는 배열을 만들어 저장시켜준다. 여기서 절대값을 씌어 기준n과의 거리느낌으로 해준다.
    for (int i = 0; i < num; i++) {
        distance[i] = abs(list[i] - n);
    }

    quick_sort(distance, 0, num - 1); // 퀵정렬 distance[0]=0 distance[1]=1 distance[2]=1 distance[3]=2 distance[4]=2 distance[5]=3
    for (int i = 0; i < num - 1; i++) {
        // distance배열은 지금 n=4 기준으로 했을때 정렬된 값은 0, 1, 1, 2, 2, 3 이다. 근데 1과 2는 중복이되어있는걸 볼 수 있는데 여기서는 list원소가 누가 더 큰지 모르니 두 수비교를 통해 바꿔준다.
        if (distance[i] == distance[i + 1]) {
            if (list[i] > list[i + 1])
                SWAP(list[i], list[i + 1], tmp);
        }
    }

    for (int i = 0; i < num; i++)
        printf("%d\n", list[i]);
    return 0;
}