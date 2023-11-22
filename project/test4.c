#include <ncurses.h>
#include <stdio.h>

struct inputData {
    int inputHeight;
    char menuInfo[5];
};

struct inputData getInfo() {   
    struct inputData s; 	// 구조체 inputData을 s 변수로 선언
    s.math = 87;   //structure s의 math 멤버에 87 대입
    s.english = 76; // structure s의 english 멤버에 87 대입
    

    return s ;    // 구조체 변수 반환
}

int main() {
    char menuInfo[10] = { '1', '2', '3', '3' };
    printf("%c", menuInfo[0]);
    return 0;
}

// cd /workspace/SeowonCProject/project/ && gcc ./test4.c -o /tmp/a.out -lm -ljson-c -lncurses && clear && /tmp/a.out