#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000000

int list[MAX_SIZE];
int answer[MAX_SIZE];
int seq_search(int high, int key, int key2, int version)
{
    int i, j;
    // case 1���϶�
    if (version == 1)
    {
        for (i = 0; i <= high; i++) // Ž��
            if (list[i] >= key) // key���� ũ�ų� ������
                return high - i; // �������ε��� - ���õ��ε���
        return 0; // key���ǿ� �ش� �ȵǸ� 0��ȯ
    }
    // case 2���϶�
    if (version == 2)
    {
        for (i = 0; i <= high; i++) // Ž��
            if (list[i] > key) // key���� Ŭ��
                return high - i; // �������ε��� - ���õ��ε���
        return 0; // key���ǿ� �ش� �ȵǸ� 0��ȯ
    }
    // case 3���϶�
    if (version == 3)
    {
        for (i = 0; i <= high; i++) { // Ž��
            if (list[i] >= key) { // list[i]�� key���� ũ�ų� ������ 
                for (j = high - 1; j > i; j--) { // �ڿ��� ���� Ž��
                    if (list[j] <= key2) { // list[j]�� key���� �۰ų� ������
                        break; // �극��ũ -> i�� j �ε��� ����Ǿ�����
                    }
                }
                if (i == j) // i�� j�� ������ ex) 3 4 4
                    return j - i; // j-i
                else // �׷��� ������
                    return j - i + 1;  // j�ε��� - i�ε���
            }

        }
        return 0; // Ž���� ���� ������ 0 ��ȯ

    }


}

int main(void)
{
    int n, num, version;
    int key = 0, key2 = 0;;
    int input;

    scanf("%d %d", &n, &num); // n : ����� ���� , num : ���� ����

    for (int i = 0; i < n; i++) { // ����� ���� ��ŭ ����Ʈ �� �Է�
        scanf("%d", &input);
        list[i] = input;
    }

    for (int i = 0; i < num; i++) { // ������ ���� ��ŭ �ݺ�
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