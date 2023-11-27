/*
* 프로그램 내용: 유저의 계정정보와 개인정보를 구조체로 담아 패스워드 인증후 정보를 출력하는 프로그램 (창작 문제)
* 개발자: 연승현 (202311420)
*/

#include <stdio.h>
#include <string.h>

// 개인정보 구조체
struct userinfo {
    int age;        // 나이
    char name[20];  // 이름
};

// 계정 구조체
struct accountinfo {
    int password;  // 패스워드
    struct userinfo Privacy;    // 개인정보 구조체
};


int main() {
    int pw;     // 패스워드 받는 변수
    struct accountinfo Account; // 구조체 변수 선언
    
    Account.password = 2023;    // 패스워드 설정
    Account.Privacy.age = 20;   // 나이 설정
    strcpy(Account.Privacy.name, "홍길동");  // 이름 설정
    
    printf("비밀번호 입력: ");
    scanf("%d", &pw);
    
    if (pw == Account.password) {
        printf("이름: %s\n", Account.Privacy.name);
        printf("나이: %d\n", Account.Privacy.age);
    } else {
        printf("패스워드가 틀렸습니다.\n");
    }
    return 0;
}


// cd /workspace/SeowonCProject/assignment/week4/creation/ && gcc ./202311420.c -o /tmp/a.out -lm && clear && /tmp/a.out