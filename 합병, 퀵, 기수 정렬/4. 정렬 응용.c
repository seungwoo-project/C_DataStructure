#include <stdio.h>
#define MAX_SIZE 1000000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE]; // ���� ����Ʈ
int distance[MAX_SIZE]; // ���� n�� list���ҵ鰣�� ��
int abs(int x) {
    return (x < 0) ? -x : x;
}
// ������
void quick_sort(int list[], int left, int right)
{
    if (left < right) {
        int q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
    }
}
// ���ĺκ�
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
        // distance�迭�� ����n�� list���Ұ��� �����̴�. distance�� list�� ���谡 �ξ����ִ�. �׷��� ������ �� �� ���� �ε��� ��ȣ�� ��ġ �ǵ��� distance�迭���ƴ϶� list�迭�� ���� ���� �����־���Ѵ�.
        if (low < high) { SWAP(distance[low], distance[high], temp); SWAP(list[low], list[high], temp); }
    } while (low < high);
    //�Ȱ��� ����
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
    // ����n�� ����Ʈ���� ���̸� ���ο� distance��� �迭�� ����� ��������ش�. ���⼭ ���밪�� ���� ����n���� �Ÿ��������� ���ش�.
    for (int i = 0; i < num; i++) {
        distance[i] = abs(list[i] - n);
    }

    quick_sort(distance, 0, num - 1); // ������ distance[0]=0 distance[1]=1 distance[2]=1 distance[3]=2 distance[4]=2 distance[5]=3
    for (int i = 0; i < num - 1; i++) {
        // distance�迭�� ���� n=4 �������� ������ ���ĵ� ���� 0, 1, 1, 2, 2, 3 �̴�. �ٵ� 1�� 2�� �ߺ��̵Ǿ��ִ°� �� �� �ִµ� ���⼭�� list���Ұ� ���� �� ū�� �𸣴� �� ���񱳸� ���� �ٲ��ش�.
        if (distance[i] == distance[i + 1]) {
            if (list[i] > list[i + 1])
                SWAP(list[i], list[i + 1], tmp);
        }
    }

    for (int i = 0; i < num; i++)
        printf("%d\n", list[i]);
    return 0;
}