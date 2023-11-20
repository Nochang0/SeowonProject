/*
* 프로그램 내용: 정수형 배열에 대하여 배열의 원소중 최댓값과 최솟값을 찾아서 출력하는 프로그램 (창작 문제)
* 개발자: 이정호 (202311431)
*/

#include <stdio.h>

#define SIZE 10  // 배열의 크기
#define INIT_VALUE 0  // 초기화 값

int main() {
    int arr[SIZE];
    int max, min;

    // 배열의 값 입력
    printf("정수형 배열의 값을 입력하세요:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);

        // 초기값 설정
        if (i == 0) {
            max = arr[0];
            min = arr[0];
        }
    }

    // 최댓값과 최솟값 찾기
    for (int i = 1; i < SIZE; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // 최댓값과 최솟값 출력
    printf("배열의 최댓값: %d\n", max);
    printf("배열의 최솟값: %d\n", min);

    return 0;
}

// cd /workspace/SeowonCProject/assignment/week3/creation/ && gcc ./202311431.c -o /tmp/a.out -lm && clear && /tmp/a.out
