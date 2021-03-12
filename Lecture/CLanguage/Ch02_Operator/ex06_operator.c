/* 10000원 이하의 물건 가격과 사용자가 낸 금액을 입력하면
거스름돈이 얼마인지 출력하는 프로그램 */

#include<stdio.h>

int main_ex06_operator() {
	// 변수 선언
	int price, received_money, change;

	// 사용자 입력값 받기
	printf("물건 가격: ");
	scanf_s("%d", &price);
	printf("받은 금액: ");
	scanf_s("%d", &received_money);

	// 거스름돈 계산
	change = received_money - price;

	// 거스름돈 출력
	printf("\n*** 거스름돈 ***\n");
	printf("10000원: %d장\n", change / 10000);
	change = change % 10000;

	printf(" 5000원: %d장\n", change / 5000);
	change = change % 5000;

	printf(" 1000원: %d장\n", change / 1000);

	return 0;

}