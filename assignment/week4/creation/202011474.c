/*
* 프로그램 내용:학생들의 정보들을 출력하는 시스템 (창작 문제)
* 개발자: 정희태 (202011474)
*/

#include <stdio.h>

// 학생 구조체 정의
struct student {
    char name[50]; //학생 이름
    int studentID; //학생 아이디
    int grade; //학생 성적
};

int main() {
    int numstudents;// 학생 수 변수 선언

    printf("학생 명 수를  입력해주세요: ");
    scanf("%d", &numstudents);

    // 학생 구조체 배열 선언
    struct student students[numstudents];

    // 학생 정보 입력 받기
    for (int i = 0; i < numstudents; ++i) {
        printf("\n학생 정보를 입력해주세요. %d:\n", i + 1);

        printf("이름 : ");
        scanf("%s", students[i].name);

        printf("아이디 : ");
        scanf("%d", &students[i].studentID);

        printf("성적 : ");
        scanf("%d", &students[i].grade);
    }

    // 입력 받은 학생 정보 출력
    printf("\n학생들의 정보 :\n");
    for (int i = 0; i < numstudents; ++i) {
        printf("\n학생 %d\n", i + 1);
        printf("학생 이름 : %s\n", students[i].name);
        printf("학생 아이디 : %d\n", students[i].studentID);
        printf("성적 : %d\n", students[i].grade);
    }

    return 0;
}





// cd /workspace/SeowonCProject/assignment/week4/creation/ && gcc ./202011474.c -o /tmp/a.out -lm && clear && /tmp/a.out