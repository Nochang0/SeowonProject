#ifndef PROMPT_H
#define PROMPT_H


#define RED     		"\x1b[31m"
#define LIGHT_RED     	"\033[1;31m"
#define GREEN   		"\x1b[32m"
#define LIGHT_GREEN 	"\033[1;32m"
#define YELLOW  		"\x1b[33m"
#define BLUE    		"\x1b[34m"
#define LIGHT_BLUE		"\033[94m"
#define MAGENTA 		"\x1b[35m"
#define CYAN    		"\x1b[36m"
#define LIGHT_CYAN		"\033[96m"
#define WHITE   		"\x1b[0m"

// 기본 라이브러리
#include <stdio.h>
#include <stdbool.h>

// 커스텀 라이브러리
#include "../lib/ui.h"
#include "../lib/util.h"


void showIncomeList();
void showSpendList();
bool isArray(char value, char array[], int size);


void inputBarByMainMenu(void) {
    char moveNum;					// 이동 기호 입력
    mainMenu();						// 입력창 높이 및 ui 장면
    char* menuArr = "123q";			// 입력 값 배열
    
    printf(WHITE);
	printf("╔═══════════════════════════════════════════════════╗\n\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
    gotoxy(1, 11);
    printf("║ ▶️ 입력:                                           ║" LIGHT_GREEN);
    
    gotoxy(11, 11);
    scanf("%c", &moveNum);

    switch(moveNum) {
        case '1':
            gotoxy(10, 11);
            LoadSpin(50, "║ ");
            return "";
        case '2':
            gotoxy(10, 11);
            LoadSpin(50, "║ ");
            break;
        case '3':
            gotoxy(10, 11);
            LoadSpin(50, "║ ");
            break;
        case 'q':
            gotoxy(10, 11);
            LoadSpin(50, "║ ");
            break;
        default:
            gotoxy(1, 11+2);
            printf(LIGHT_RED "╔═══════════════════════════════════════════════════╗\n");
            printf("║" YELLOW " ⚠️Error: 정해진 번호 안에서 입력해주세요." LIGHT_RED "          ║\n");
            printf("╚═══════════════════════════════════════════════════╝\n" WHITE);
            
            while (true) {
                gotoxy(11, 11);
                printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
                gotoxy(1, 11);
                printf("║ ▶️ 입력: " LIGHT_GREEN);
                scanf("%c", &moveNum);
                
                // 선택지를 잘 골랐을 경우
                if (isArray(moveNum, menuArr, sizeof(menuArr) / sizeof(menuArr[0]))) {
                    gotoxy(10, 11);
                    LoadSpin(100, "║ ");
                    break;
                }
                
                printf(WHITE);
                continue;
            }
            break;
    }
}





#endif // PROMPT_H