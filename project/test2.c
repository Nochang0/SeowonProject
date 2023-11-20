#include <stdio.h>
#include <unistd.h>

int main() {
    int i;
    char text[] = "Hello, World!"; // 출력할 텍스트
    int text_length = sizeof(text) - 1; // 텍스트의 길이

    for (i = 0; ; i++) {
        int color_value = (i / 2) % 2; // 10번마다 색 변경
        int color_code = color_value ? 30 : 37; // 검은색 또는 흰색 선택

        printf("\033[%dm", color_code); // 색상 설정

        for (int j = 0; j < text_length; j++) {
            printf("%c", text[j]); // 텍스트 출력
            fflush(stdout); // 출력 버퍼 비우기
            usleep(100000); // 0.1초 대기
        }
        printf("\033[0m"); // 색상 초기화
        printf("\r"); // 커서를 줄의 맨 앞으로 이동

        usleep(500000); // 0.5초 대기
    }

    return 0;
}





// cd /workspace/SeowonCProject/project/ && gcc ./test2.c -o /tmp/a.out -lm -ljson-c && clear && /tmp/a.out