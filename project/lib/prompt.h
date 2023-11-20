#ifndef PROMPT_H
#define PROMPT_H


#define COLOR_RED     		"\x1b[31m"
#define COLOR_LIGHT_RED     "\033[1;31m"
#define COLOR_GREEN   		"\x1b[32m"
#define COLOR_LIGHT_GREEN 	"\033[1;32m"
#define COLOR_YELLOW  		"\x1b[33m"
#define COLOR_BLUE    		"\x1b[34m"
#define COLOR_MAGENTA 		"\x1b[35m"
#define COLOR_CYAN    		"\x1b[36m"
#define COLOR_WHITE   		"\x1b[0m"

// 기본 라이브러리
#include <stdio.h>

void menuScene();



void menuScene() {
    printf("\033[2J\033[H");						// 프롬프트 Clear
	printf("╔═══════════════════════════════╗\n");
    printf("     가계부 관리 프로그램\n");
    printf("╠═══════════════════════════════╣\n");
    printf("╚═══════════════════════════════╝\n");
}


#endif // PROMPT_H