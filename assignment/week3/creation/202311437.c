/*
* 프로그램 내용: 랜덤 함수로 2차원 배열에 넣고, 넣은 숫자들을 다 더한 값까지 출력하기 (창작 문제)
* 개발자: 이호현 (202311437)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sum(int number[5][5])                                  // 열의 숫자를 다 더하는 함수
{
    int rowSum[5] = { 0 };                                  // 더한 값을 넣는 배열 변수

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            rowSum[i] += number[i][j];

    for (int i = 0; i < 5; i++)
        printf("%d번째 행의 총합 : %d\n", i, rowSum[i]);
}

int main(void)
{
    int number[5][5] = { 0 };   

    srand((unsigned)time(NULL));                            // 랜덤 함수

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            number[i][j] = rand() % 100 + 1;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("%d ", number[i][j]);
        printf("\n");
    }

    sum(number);                                            // sum 함수를 호출

    return 0;
}

// cd /workspace/SeowonCProject/assignment/week3/creation/ && gcc ./202311437.c -o /tmp/a.out -lm && clear && /tmp/a.out