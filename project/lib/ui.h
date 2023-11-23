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

// 커스텀 라이브러리
#include "../lib/util.h"

// UI 장면 함수
void Splash_Screen(void);
void menuScene(void);
void incomeMenu(void);
void spendMenu(void);
void searchMenu(void);
void ExitScene(void);

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
	LoadSpin(150, "");
}

// 0. 메인 메뉴
void mainMenu(void) {
    printf(WHITE "\033[2J\033[H");						// 프롬프트 Clear
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●        📝 가계부 관리 프로그램 By 5팀		  ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║                                                   ║\n");
	printf("║       1. 📝수입 관리        2. 📑지출 관리        ║\n");
    printf("║                                                   ║\n");
	printf("║       3. 🔍내역 검색        " LIGHT_RED "q. ⛔종료하기" WHITE "         ║\n" WHITE);
    printf("║                                                   ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
}

// 1. 수입 메뉴 (0-1)
void incomeMenu(void) {
    printf(WHITE "\033[2J\033[H");						// 프롬프트 Clear
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●        📝 가계부 관리 프로그램 By 5팀		  ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║                                                   ║\n");
	printf("║   1. 📝수입목록 추가        2. 📑수입목록 보기     ║\n");
    printf("║                                                   ║\n");
	printf("║       z. 🚪" YELLOW "뒤로가기        " LIGHT_RED "  q. ⛔종료하기" WHITE "        ║\n" WHITE);
    printf("║                                                   ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
}

// 2. 지출 메뉴 (0-2)
void spendMenu(char* spendNotice) {
    printf(WHITE "\033[2J\033[H");						// 프롬프트 Clear
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●        📝 가계부 관리 프로그램 By 5팀		  ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║                                                   ║\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║                                                   ║\n");
	printf("║   1. 📝지출목록 추가        2. 📑지출목록 보기        ║\n");
    printf("║                                                   ║\n");
	printf("║   3. 📝지출한도 설정        4. 📑지출예약 설정        ║\n");    
    printf("║                                                   ║\n");
	printf("║       z. 🚪" YELLOW "뒤로가기        " LIGHT_RED "q. ⛔종료하기" WHITE "         ║\n" WHITE);
    printf("║                                                   ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
}

// 3. 검색 메뉴 (0-2)
void searchMenu(void) {
    printf(WHITE "\033[2J\033[H");						// 프롬프트 Clear
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●        📝 가계부 관리 프로그램 By 5팀		  ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║                                                   ║\n");
	printf("║  1. 📑수입목록 날짜검색   2. 📑수입목록 테그검색   ║\n");
    printf("║                                                   ║\n");
	printf("║  3. 📑지출목록 날짜검색   4. 📑지출목록 테그검색   ║\n");
    printf("║                                                   ║\n");
	printf("║       z. 🚪" YELLOW "뒤로가기        " LIGHT_RED "q. ⛔종료하기" WHITE "         ║\n" WHITE);
    printf("║                                                   ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
}

// 종료 화면
void ExitScene(void) {
    printf(WHITE "\033[2J\033[H");						// 프롬프트 Clear
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●        📝 가계부 관리 프로그램 By 5팀		  ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
    gotoxy(1, 4);
    printf("║                                                   ║\n");
    disappearText("Thank You For Watching!");
    exit(0);
}



#endif // UI_H