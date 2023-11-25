/*
* 프로그램 내용:  (창작 문제)
* 개발자: 정희태 (202011474)
*/

#include <stdio.h>

// 학생 구조체 정의
struct student {
    char name[50];
    int studentID;
    float grade;
};

int main() {
    int numstudents;

    printf("학생 명 수를  입력해주세요: ");
    scanf("%d", &numstudents);

    // 학생 구조체 배열 선언
    struct student students[numstudents];

    // 학생 정보 입력 받기
    for (int i = 0; i < numstudents; ++i) {
        printf("\n학생 정보를 입력해주세요. %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Student ID: ");
        scanf("%d", &students[i].studentID);

        printf("Grade: ");
        scanf("%f", &students[i].grade);
    }

    // 입력 받은 학생 정보 출력
    printf("\nStudent Information:\n");
    for (int i = 0; i < numstudents; ++i) {
        printf("\nStudent %d\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Student ID: %d\n", students[i].studentID);
        printf("Grade: %.2f\n", students[i].grade);
    }

    return 0;
}





// cd /workspace/SeowonCProject/assignment/week4/creation/ && gcc ./202011474.c -o /tmp/a.out -lm && clear && /tmp/a.out