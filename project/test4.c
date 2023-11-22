#include <ncurses.h>

int main() {
    initscr();  // ncurses 초기화
    cbreak();   // 키 입력 버퍼를 사용하지 않고 즉시 입력을 받음
    noecho();   // 입력한 문자를 화면에 표시하지 않음
    keypad(stdscr, TRUE);  // 특수 키(예: 화살표, 함수 키)의 입력을 활성화

    mousemask(ALL_MOUSE_EVENTS, NULL);  // 모든 마우스 이벤트 감지

    while (1) {
        int ch = getch();
        if (ch == KEY_MOUSE) {
            MEVENT event;
            if (getmouse(&event) == OK) {
                if (event.bstate & BUTTON1_PRESSED) {
                    // 마우스 왼쪽 버튼 클릭 시 동작 수행
                    // 원하는 로직을 작성하세요.
                    printf("good");
                }
            }
        }
    }

    
    endwin();  // ncurses 종료
    return 0;
}

// cd /workspace/SeowonCProject/project/ && gcc ./test4.c -o /tmp/a.out -lm -ljson-c -lncurses && clear && /tmp/a.out