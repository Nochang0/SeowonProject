#include <stdio.h>

int main(void) {
    char name[20];				// 이름 
    int displacement, year;		// 배기량, 연도
    int total_tax;				// 총 세금
    double discount, tax_cc;	// 차령 할인률, 배기량 요금
	
    printf("이름, 배기량, 연식을 입력하세요: ");
    scanf("%s %d %d", name, &displacement, &year);

    // 배기량에 따라 과세 기준 설정 (tax_cc에 배기량 요금저장)
    if (displacement <= 1000) {
        tax_cc = displacement * 80;
    }
	// 1000초과 80대로, 1600이하까진 140
    else if (displacement > 1000 && displacement <= 1600) {
        tax_cc = 1000 * 80 + (displacement - 1000) * 140;
    }
	// 2000이상은 200
    else {
        tax_cc = (1000 * 80) + (600 * 140) + ((displacement - 1600) * 200);
    }

    // 차령에 따른 할인 계산 (discount에 할인률 저장)
	// 차 연령
    int age = 2023 - year + 1;
	
	// 3년: 5% ~ 11년: 45%
    if (age >= 3 && age < 12) {
        discount = (age - 2) * 5;
    }
	// 12년이상: 50%
    else if (age >= 12) {
        discount = 50;
    }
	// 1년이나 2년: X
    else {
        discount = 0;
    }

    // 자동차세 계산 (total_tax에 총 세금 저장)
	// 배기량 요금에서 차령 할인
    tax_cc = tax_cc - (tax_cc * discount / 100);
	// 계산된 배기량 요금(세금)에 교육세 30% 부과
	tax_cc = tax_cc + (tax_cc * 0.3);
	// 10원절삭: 10을 나눠 int로 뒷 자리 없애고 다시 10으로 원상복구
	total_tax = (int)(tax_cc / 10) * 10;
	// 출력
    printf("%s의 자동차세는 %d원 입니다.\n", name, total_tax);

    return 0;
}


// -ljson-c
// gcc /workspace/SeowonCProject/test.c -o /tmp/a.out -ljson-c && /tmp/a.out

/*
{
  "name":"John Doe",
  "age":30,
  "address":{
    "street":"123 ABC Street",
    "city":"New York"
  }
}
{
  "name":"John Doe",
  "address":{
    "street":"123 ABC Street",
    "city":"New York"
  }
}
*/