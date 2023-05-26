#include <stdio.h>
 
int CoinChange(int money) {
    int num = 0;
    int coin[7] = { 10000, 5000, 1000, 500, 100, 50, 10 };
    for (int i = 0; i < 7; i++) {
        num += (money / coin[i]); // �������� �Ǿ��ִ� coin�� ���������� �Ǹ�(���� ���� ������ �����ϸ�) ���� ������ ���� ����
        money %= coin[i]; // ����� �������� �� �������ݾ�
    }
    return num; // ���� ����
}

int main() {
    int n; // ��ǰ �ݾ�
    int m; // �ܵ�
    scanf("%d", &n);
    m = 50000 - n; // �ܵ��� ���ϱ� ���� 5�������� ��ǰ �ݾ��� ��
    printf("%d", CoinChange(m));

}