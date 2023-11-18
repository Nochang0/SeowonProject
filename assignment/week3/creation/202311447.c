/*
* 프로그램 내용: 배열의 바이트 크기와 크기를 구하는 프로그램을 만드시오 (창작 문제)
* 개발자: 홍정일 (202311447)
*/

#include <stdio.h>

int main(void)
{
    int arr[4];  // 크기가 4인 정수형 배열 선언
    int byte_size = 0;  // 배열의 전체 바이트 크기를 저장할 변수
    int size = 0;       // 배열의 요소 개수를 저장할 변수

    byte_size = sizeof(arr);  // 배열의 전체 바이트 크기 계산
    printf("배열의 바이트 크기: %d\n", byte_size);

    size = sizeof(arr) / sizeof(arr[0]);  // 배열의 요소 개수 계산
    printf("배열의 크기: %d\n", size);

    return 0;
}

// cd /workspace/SeowonCProject/assignment/week3/creation/ && gcc ./202311447.c -o /tmp/a.out -lm && clear && /tmp/a.out