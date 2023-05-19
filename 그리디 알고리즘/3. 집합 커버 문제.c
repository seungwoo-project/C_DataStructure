#include <stdio.h>
#define MAX_SIZE 10
#define MAX_M 100
#define MAX_N 100

int n, m;
int covered[MAX_N];
int sets[MAX_M][MAX_N];
int SetCover() {

    while (1) {
        // ���� ���� ���Ҹ� Ŀ���ϴ� ������ ���� ��
        int max_count = 0;
        // ���� ���� ���Ҹ� Ŀ���ϴ� ������ �ε���
        int max_set = -1;
        for (int i = 0; i < m; i++) {
            int cur_count = 0;
            for (int j = 0; j < n; j++) {
                if (sets[i][j] != -1 && !covered[sets[i][j]]) { // ������ ������ ����� ���� -> 2�����迭�� -1�ƴ� ���� ������ �ʱ�ȭ �Ǿ��ְ� Ŀ���� �ȵǾ��ִٸ�
                    cur_count++;
                }
            }
            if (cur_count > max_count) { // ���� ���� ���Ҹ� ���� ������ �ε����� ã�°���
                max_count = cur_count;
                max_set = i;
            }

        }
        if (max_count == 0)
            break;
        printf("%d\n", max_set);
        // ���տ��� ���°���
        for (int j = 0; j < n; j++) {
            if (sets[max_set][j] != -1) { // 2�����迭�� ���������ִٸ�
                covered[sets[max_set][j]] = 1; // ���� Ŀ���� �߰�
            }
        }
    }
}


int main(void) {
    int count, value;
    // 2���� �迭 �� -1�� �ʱ�ȭ
    for (int i = 0; i < MAX_M; i++) {
        for (int j = 0; j < MAX_N; j++)
            sets[i][j] = -1;

    }
    // ������ ���� n ������ ���� m
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) { // ���� ������ŭ �ݺ�
        scanf("%d", &count);
        for (int j = 0; j < count; j++) { // count��ŭ �ݺ�
            scanf("%d", &value);
            sets[i][j] = value; // �Է°� ����
        }
    }

    SetCover();
}