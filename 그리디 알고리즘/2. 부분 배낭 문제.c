#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
typedef struct _item {
    int value; // 가치
    int weight; // 무게
    double vpw; // 무게당 가치
} item;

// 내림차순 정렬 compare
int compare(const void* a, const void* b) {
    item* item1 = (item*)a;
    item* item2 = (item*)b;

    if (item1->vpw < item2->vpw)
        return 1;
    else if (item1->vpw > item2->vpw)
        return -1;
    else
        return 0;
}


double fractionalKnapsack(int n, item list[], int w) { //n : 개수, list : item리스트, w : 배낭 최대 무게
    qsort(list, n, sizeof(item), compare); // 내림차순 정렬
    double totalValue = 0; // 총 가치
    int currWeight = 0; // 현재 무게
    for (int i = 0; i < n; i++) {
        if (currWeight + list[i].weight <= w) { // 만약 가방에 더 들어갈수 있다면
            currWeight += list[i].weight; // 가방에 넣는다
            totalValue += list[i].value; // 가치도 더해준다
        }
        else { // 가방에 안들어 간다면 단위당 가치 계산
            int remaningWeight = w - currWeight; // 남은 무게
            totalValue += remaningWeight * list[i].vpw; // 남은 무게를 단위당 무게 가치로 곱해서 최대한 돈을 가져간다. 토탈에 더해줌
            break;
        }
    }
    return totalValue;
}
 
int main(void) {
    int w, n;
    item list[MAX_SIZE];

    scanf("%d %d", &w, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &list[i].weight, &list[i].value);
        list[i].vpw = 1.0 * list[i].value / list[i].weight; // 1g당 가치!
    }

    printf("%lf", fractionalKnapsack(n, list, w));
}