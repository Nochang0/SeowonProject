/*
* 프로그램 내용: 정수형 변수를 선언하고 해당 변수의 값을 변경 (창작 문제)
* 개발자: 김지성 (202110343)
*/

#include <stdio.h>

int main() {
    int num = 10;
    int* ptr = &num;

    printf("변수의 값: %d\n", *ptr);

    *ptr = 20;
    printf("변경된 변수의 값 : %d\n", num);

    return 0;
}


// cd /workspace/SeowonCProject/assignment/week4/creation/ && gcc ./202110343.c -o /tmp/a.out -lm && clear && /tmp/a.out