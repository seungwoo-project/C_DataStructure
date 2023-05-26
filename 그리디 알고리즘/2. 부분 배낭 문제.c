#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
typedef struct _item {
    int value; // ��ġ
    int weight; // ����
    double vpw; // ���Դ� ��ġ
} item;

// �������� ���� compare
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


double fractionalKnapsack(int n, item list[], int w) { //n : ����, list : item����Ʈ, w : �賶 �ִ� ����
    qsort(list, n, sizeof(item), compare); // �������� ����
    double totalValue = 0; // �� ��ġ
    int currWeight = 0; // ���� ����
    for (int i = 0; i < n; i++) {
        if (currWeight + list[i].weight <= w) { // ���� ���濡 �� ���� �ִٸ�
            currWeight += list[i].weight; // ���濡 �ִ´�
            totalValue += list[i].value; // ��ġ�� �����ش�
        }
        else { // ���濡 �ȵ�� ���ٸ� ������ ��ġ ���
            int remaningWeight = w - currWeight; // ���� ����
            totalValue += remaningWeight * list[i].vpw; // ���� ���Ը� ������ ���� ��ġ�� ���ؼ� �ִ��� ���� ��������. ��Ż�� ������
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
        list[i].vpw = 1.0 * list[i].value / list[i].weight; // 1g�� ��ġ!
    }

    printf("%lf", fractionalKnapsack(n, list, w));
}