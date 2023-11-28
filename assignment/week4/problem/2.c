/*
* 프로그램 내용: 4주차 팀별과제 2번
* 개발자: 홍정일
* 문제: 2. 다음에 해당하는 C 프로그램을 작성하세요.

사람의 이름, 키 몸무게, BMI를 저장하는 구조체(struct person) 선언

5명의 사람의 이름을 입력 받고, 키(160 ~ 180cm 사이)와 몸무게(50 ~ 90 kg)는 random number로 생성 한후에, 각 사람의 BMI 지수값을 계산하여 저장한다.
다음 함수를 이용하여 BMI 지수가 가장 높은 사람의 이름, 키, 몸무게, BMI를 출력한다.
struct person cal_max_BMI(struct person *sp, int size)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 구조체 정의
struct Person {
    char name[50];  // 이름
    int height;     // 키 (cm)
    int weight;     // 몸무게 (kg)
    float bmi;      // BMI 지수
};

// 함수 선언
void generateRandomData(struct Person* p);
float calculateBMI(int height, int weight);
struct Person cal_max_BMI(struct Person* people, int size);

int main() {
    // 랜덤 시드 설정
    srand((unsigned int)time(NULL));

    // 5명의 사람 정보를 저장할 구조체 배열
    struct Person people[5];

    // 정보 입력 및 계산
    for (int i = 0; i < 5; ++i) {
        printf("사람 %d의 이름을 입력하세요: ", i + 1);
        scanf("%s", people[i].name);
        generateRandomData(&people[i]);
        people[i].bmi = calculateBMI(people[i].height, people[i].weight);
    }

    // 최대 BMI를 가진 사람 찾기
    struct Person maxBmiPerson = cal_max_BMI(people, 5);

    // 결과 출력
    printf("\n가장 높은 BMI를 가진 사람:\n");
    printf("이름: %s\n", maxBmiPerson.name);
    printf("키: %d cm\n", maxBmiPerson.height);
    printf("몸무게: %d kg\n", maxBmiPerson.weight);
    printf("BMI: %.2f\n", maxBmiPerson.bmi);

    return 0;
}

// 랜덤으로 키와 몸무게를 생성하는 함수
void generateRandomData(struct Person* p) {
    p->height = rand() % 21 + 160; // 160~180cm 범위의 랜덤 값
    p->weight = rand() % 41 + 50;  // 50~90kg 범위의 랜덤 값
}

// BMI를 계산하는 함수
float calculateBMI(int height, int weight) {
    return (float)weight / ((float)height / 100 * (float)height / 100);
}

// 최대 BMI를 가진 사람을 찾는 함수
struct Person cal_max_BMI(struct Person* people, int size) {
    struct Person maxPerson = people[0];
    for (int i = 1; i < size; ++i) {
        if (people[i].bmi > maxPerson.bmi) {
            maxPerson = people[i];
        }
    }
    return maxPerson;
}





// cd /workspace/SeowonCProject/assignment/week4/problem/ && gcc ./2.c -o /tmp/a.out -lm && clear && /tmp/a.out