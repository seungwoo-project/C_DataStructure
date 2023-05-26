#include <stdio.h>
 
int CoinChange(int money) {
    int num = 0;
    int coin[7] = { 10000, 5000, 1000, 500, 100, 50, 10 };
    for (int i = 0; i < 7; i++) {
        num += (money / coin[i]); // 내림차순 되어있는 coin이 나누어지게 되면(지폐나 동전 제출이 가능하면) 지폐나 동전의 개수 저장
        money %= coin[i]; // 지폐로 나눠지고 난 나머지금액
    }
    return num; // 개수 리턴
}

int main() {
    int n; // 물품 금액
    int m; // 잔돈
    scanf("%d", &n);
    m = 50000 - n; // 잔돈을 구하기 위해 5만원에서 물품 금액을 뺌
    printf("%d", CoinChange(m));

}