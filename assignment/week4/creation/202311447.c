/*
* 프로그램 내용: 각 사람의 키를 기준으로 평균 키를 계산하여 출력하는 프로그램 (창작 문제)
* 개발자: 홍정일 (202311447)
*/

#include <stdio.h>

// 구조체 정의
struct Person {
    char name[50];
    float height; // 키 (cm)
};

// 함수 선언
void inputPersonInfo(struct Person* p);
float calculateAverageHeight(struct Person* people, int size);

int main() {
    // 3명의 사람 정보를 저장할 구조체 배열
    struct Person people[3];

    // 정보 입력
    for (int i = 0; i < 3; ++i) {
        printf("사람 %d의 이름을 입력하세요: ", i + 1);
        scanf("%s", people[i].name);
        inputPersonInfo(&people[i]);
    }

    // 평균 키 계산 및 출력
    float averageHeight = calculateAverageHeight(people, 3);
    printf("\n평균 키: %.2f cm\n", averageHeight);

    return 0;
}

// 개인 정보 입력 함수
void inputPersonInfo(struct Person* p) {
    printf("키를 입력하세요 (cm): ");
    scanf("%f", &p->height);
}

// 평균 키 계산 함수
float calculateAverageHeight(struct Person* people, int size) {
    float sumHeight = 0;

    for (int i = 0; i < size; ++i) {
        sumHeight += people[i].height;
    }

    return sumHeight / size;
}

// cd /workspace/SeowonCProject/assignment/week4/creation/ && gcc ./202311447.c -o /tmp/a.out -lm && clear && /tmp/a.out