/*
* 프로그램 내용: 1주차 팀별과제 1번
* 개발자: 연승현 (202311420)
* 문제: 6자리수의 2진수 정수를 키보드로부터 입력 받아, 10진수로 변환하여 출력하는 프로그램을 작성하세요.
*/

#include <stdio.h>

int main(void) {
    int bin, dword = 0, pow = 1;

    printf("6자리의 2진수 정수를 입력하세요: ");
    scanf("%d", &bin);

    // 주어진 2진수를 각 자릿수의 값과 2의 거듭제곱을 곱함 (ex. 110101 => 1 * 2^5 + 1 * 2^4 + 0 * 2^3 + 1 * 2^2 + 0 * 2^1 + 1 * 2^0 => 32 + 16 + 0 + 4 + 0 + 1 = 53)
    
    while (bin > 0) {
        int remainder = bin % 10;
        dword += remainder * pow;
        pow *= 2;
        bin /= 10;
    }

    printf("10진수로 변환된 값: %d\n", dword);
    return 0;
}






// cd /workspace/SeowonCProject/assignment/week1/problem/ && gcc ./1.c -o /tmp/a.out -lm && clear && /tmp/a.out