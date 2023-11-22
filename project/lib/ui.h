#ifndef UI_H
#define UI_H


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
#include "../lib/util.h"

// LoadSpin
void Splash_Screen();
void menuScene();


// 스플래시 이미지
void Splash_Screen(void) {
    printf("\033[2J\033[H");						// 프롬프트 Clear
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●        📝 가계부 관리 프로그램 By 5팀		  ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                    팀 구성원                      ║\n");
	printf("║  ·" LIGHT_CYAN "연승현 (202311420)" WHITE "   ╦   ·" LIGHT_CYAN "김지성 (202110343)" WHITE "    ║\n");
	printf("║  ·" LIGHT_CYAN "정희태 (202011474)" WHITE "   ║   ·" LIGHT_CYAN "양혜성 (202311419)" WHITE "    ║\n");
	printf("║  ·" LIGHT_CYAN "이호현 (202311437)" WHITE "   ║   ·" LIGHT_CYAN "이정호 (203311431)" WHITE "    ║\n");
	printf("║  ·" LIGHT_CYAN "김예은 (202010319)" WHITE "   ║   ·" LIGHT_CYAN "장서진 (202311825)" WHITE "    ║\n");
	printf("║  ·" LIGHT_CYAN "홍정일 (202311447)" WHITE "   ║                          ║\n");
	printf("╠════════════════════════╩══════════════════════════╣\n");
	printf("║ Github: " LIGHT_GREEN "https://github.com/Nochang0/SeowonProject" WHITE " ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
	LoadSpin(50, "");
}

// 메인 메뉴
char* mainMenuScene(void) {
    char moveNum[5];
    char menuInfo[10] = { "11", '1', '2', '3', '3' };
    
    printf(WHITE "\033[2J\033[H");						// 프롬프트 Clear
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●        📝 가계부 관리 프로그램 By 5팀		  ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n\n");
	printf("        1. 📝수입 관리        2. 📑지출 관리         \n\n");
	printf("        3. 🔍내역 검색        " LIGHT_RED "q. ⛔종료하기\n" WHITE);
    printf("\n╚═══════════════════════════════════════════════════╝\n");
    return menuInfo;
}

// 수입 메뉴
void incomeMenuScene(void) {
    printf(WHITE "\033[2J\033[H");						// 프롬프트 Clear
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●        📝 가계부 관리 프로그램 By 5팀		  ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n\n");
	printf("    1. 📝수입목록 추가        2. 📑수입목록 보기         \n\n");
	printf("    " YELLOW "3. 🚪뒤로가기" LIGHT_RED "              q. ⛔종료하기\n" WHITE);
    printf("\n╚═══════════════════════════════════════════════════╝\n");
}

// 종료 화면
void ExitScene(void) {
    printf(WHITE "\033[2J\033[H");						// 프롬프트 Clear
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●        📝 가계부 관리 프로그램 By 5팀		  ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n\n");
	printf("║                    Bye Bye                      ║\n");
    printf("\n╚═══════════════════════════════════════════════════╝\n");
}



#endif // UI_H