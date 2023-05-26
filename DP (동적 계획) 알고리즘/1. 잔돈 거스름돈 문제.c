#include <stdio.h>
#define MAX_SIZE 50000 // 물품 금액은 5만원을 넘지 않는다.
#define INF 1e9

int DPCoinChange(int money) {
    int C[MAX_SIZE]; // 가상의 거스름돈 배열 선언
    int coin[10] = { 10,50,100,160,500,1000,1600,5000,10000,16000 }; // 10종류의 화폐단위
    for (int i = 0; i <= money; i++) 
        C[i] = INF; // 가상의 거스름돈에 대한 잔돈의 개수를 일단 무한대로 설정
    C[0] = 0; // 0원의 거스름돈은 잔돈의 개수가 0개이므로 0으로 초기화
    for (int j = 1; j <= money; j++) { // 가상의 거스름돈이 1부터 money까지 1씩 증가
        for (int i = 0; i < 10; i++) // 10종류의 화폐 단위로 잔돈의 개수 알아내기
            if (coin[i] <= j && (C[j - coin[i]] + 1 < C[j])) // 자기 동전의 개수 하나와 이전에 최고로 좋은 잔돈의 개수를 기억했던것을 더해 비교해 잔돈의 개수가 가장 적은것을 리턴
                C[j] = C[j - coin[i]] + 1;
    }
    return C[money]; // 가장 적은 동전의 개수를 리턴
}

int main(void) {
    int a; // 물품의 금액
    scanf("%d", &a);
    printf("%d", DPCoinChange(50000 - a)); // 5만원 - 물품 금액 = 거스름돈
}