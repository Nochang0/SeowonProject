/*
* 프로그램 내용: 4주차 팀별과제 1번
* 개발자: 정희태 (202011474)
* 문제: 삼각형, 사각형, 원을 동시에 표현할 수 있는 구조체(공용체 멤버 포함)를 설계하라. 공용체는 삼각형은 밑변과 높이, 사각형은 가로와 세로, 원은 반지름만을 저장하도록 하라. 현재의 공용체가 표현하고 있는 도형의 종 류는 열거형 변수를 사용하여 나타내고 이들 정보를 종합하는 구조체를 선언하여 사용한다. 사용자로부터 도형의 종류와 도형의 데이터를 받아서 구조체(공용체 멤버 포함)변수에 저장한 다음 도형의 면적을 계산하는 프로그램을 작성하라.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 사람 구조체 정의
struct Person {
    char name[50];
    int height;  // 키 (cm)
    int weight;  // 몸무게 (kg)
    float bmi;   // BMI 지수
};

// 함수 선언
struct Person cal_max_BMI(struct Person *people, int size);

int main() {
    srand(time(NULL)); // 무작위 수 생성을 위한 시드 설정

    int numPeople = 5;
    struct Person people[numPeople];

    // 사용자로부터 이름 입력 받기
    for (int i = 0; i < numPeople; ++i) {
        printf("Enter the name of person %d: ", i + 1);
        scanf("%s", people[i].name);

        // 무작위로 키와 몸무게 생성 (160~180cm, 50~90kg)
        people[i].height = rand() % 21 + 160;
        people[i].weight = rand() % 41 + 50;

        // BMI 계산
        float heightInMeters = (float)people[i].height / 100;
        people[i].bmi = (float)people[i].weight / (heightInMeters * heightInMeters);
    }

    // BMI가 가장 높은 사람의 정보 출력
    struct Person maxBMIInfo = cal_max_BMI(people, numPeople);
    printf("\nPerson with the highest BMI:\n");
    printf("Name: %s\n", maxBMIInfo.name);
    printf("Height: %d cm\n", maxBMIInfo.height);
    printf("Weight: %d kg\n", maxBMIInfo.weight);
    printf("BMI: %.2f\n", maxBMIInfo.bmi);

    return 0;
}

// BMI가 가장 높은 사람의 정보를 찾는 함수
struct Person cal_max_BMI(struct Person *people, int size) {
    struct Person maxBMI = people[0];

    for (int i = 1; i < size; ++i) {
        if (people[i].bmi > maxBMI.bmi) {
            maxBMI = people[i];
        }
    }

    return maxBMI;
}





// cd /workspace/SeowonCProject/assignment/week4/problem/ && gcc ./1.c -o /tmp/a.out -lm && clear && /tmp/a.out