/*
* 프로그램 내용: 입력받은 문자가 SEOWON과 동일하면 success, 
실패하면 failure를 출력하는 프로그램을 작성하시오 (창작 문제)
* 개발자: 장서진 (202311825)
*/

#include <stdio.h>
#include <string.h>

int main()
{
    // 사용자로부터 입력받을 문자열을 저장할 배열
    char str1[100];

    // 사용자에게 문자열 입력 요청
    printf("문자열을 입력하세요: ");
    
    // 사용자에게서 입력을 받아 str1 배열에 저장
    // 입력받을 배열의 크기를 지정
    scanf("%s", str1, 100);
    
    // 입력된 문자열이 "SEOWON"과 동일한지 비교
    if (!(strcmp(str1, "SEOWON"))) {
        // 만약 동일하면 성공 메시지 출력
        printf("success");
    }
    else {
        // 그렇지 않으면 실패 메시지 출력
        printf("failure");
    }
    return 0;
}



// cd /workspace/SeowonCProject/assignment/week4/creation/ && gcc ./202311825.c -o /tmp/a.out -lm && clear && /tmp/a.out