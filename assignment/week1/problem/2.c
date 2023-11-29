/*
* 프로그램 내용: 1주차 팀별과제 2번
* 개발자: 김예은 (202010319)
* 문제: 한 자리수의 10진수를 입력 받아, 2진수로 변환하여 출력하는 프로그램을 작성하세요.
*/

#include <stdio.h>

#include <stdio.h>

int main(void)
{
   int num1, num2, num3, num4;
   int decimal;

   printf("10진수를 입력하세요 : ");
   scanf_s("%d", &decimal);

   num1 = decimal % 2;
   decimal /= 2;

   num2 = decimal % 2;
   decimal /= 2;

   num3 = decimal % 2;
   decimal /= 2;

   num4 = decimal % 2;
   
   printf("2진수 : %d%d%d%d", num1, num2, num3, num4);

   return 0;
}
}



// cd /workspace/SeowonCProject/assignment/week1/problem/ && gcc ./2.c -o /tmp/a.out -lm && clear && /tmp/a.out