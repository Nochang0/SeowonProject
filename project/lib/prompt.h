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

// 커스텀 라이브러리
#include "../lib/util.h"


void showIncomeList();
void showSpendList();



void getmainMenu() {
	printf("╔═══════════════════════════════════════════════════╗\n\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
    gotoxy(1, 11);
    printf("║ 입력:                                             ║");
    
}


/*
    printf("메뉴 선택: " LIGHT_GREEN);
    scanf("%s", moveNum);
    return moveNum;
*/
#endif // PROMPT_H