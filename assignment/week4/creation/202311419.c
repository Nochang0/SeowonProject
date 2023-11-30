/*
* 프로그램 내용: 이름과 주민등록번호를 받아 성별과 같이 출력하는 프로그램 (창작 문제)
* 개발자: 양혜성 (202311419)
*/


#include <stdio.h>

const char* c_gender(char digit) {
    return (digit == '1' || digit == '3') ? "남자" : "여자";
}

int main() {
    char name[50];
    char number[14];

    printf("이름을 입력: "); 
    scanf("%49s", name, sizeof(name));

    printf("주민등록 번호: ");
    scanf("%13s", number, sizeof(number));

    printf("이름: %s\n", name);

    printf("주민등록번호 %.*s - *******\n", 6, number);

    const char* gender = c_gender(number[6]);
    printf("성별: %s\n", gender);

    return 0;
}


// cd /workspace/SeowonCProject/assignment/week4/creation/ && gcc ./202311419.c -o /tmp/a.out -lm && clear && /tmp/a.out