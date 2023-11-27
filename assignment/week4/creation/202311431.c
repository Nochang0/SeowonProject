/*
* 프로그램 내용: 배열 원소를 가리키는 포인터를 이용해서 실수형 배열의 평균을 구하는 프로그램을 작성하시오. (창작 문제)
* 개발자: 이정호 (202311431)
*/

#include <stdio.h>
#define SIZE 10  // 배열의 크기

float Average(float* arr, int size) {   //배열의 값을 모두 더하여 구하기
    float sum = 0.0;   // 정확한 평균값을 위해 0.0 사용

    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }

    float average = sum / size;   // 평균값 구하기
    return average;
}

int main() {
    float arr[SIZE];

    printf("실수형 배열의 값을 입력하세요:"); //배열의 값을 입력과 출력
    for (int i = 0; i < SIZE; i++) {
        printf("arr[%d]: ", i);
        scanf("%f", &arr[i]);
    }

    float average = Average(arr, SIZE);

    printf("배열의 평균: %.2f\n", average);   // 평균값을 소숫점 2자리까지 풀력

    return 0;
}

// cd /workspace/SeowonCProject/assignment/week4/creation/ && gcc ./202311431.c -o /tmp/a.out -lm && clear && /tmp/a.out
