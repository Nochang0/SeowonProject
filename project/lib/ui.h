#ifndef UI_H
#define UI_H

// 색상 코드
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

// UI 장면 함수들
void Splash_Screen(void);                       // 스플래시 이미지 (시작 로딩창)

// 메뉴 UI 화면들
void mainMenuScene(void);                       // 메인 메뉴 UI 화면
void incomeMenuScene(void);                     // 수입 메뉴 UI 화면
void spendMenuScene(void);                      // 지출 메뉴 UI 화면
void searchMenuScene(void);                     // 검색 메뉴 UI 화면

// 내역 추가 UI 화면들
void plusIncomeScene(void);                     // 수입내역 추가 UI 화면
void plusSpendScene(void);                      // 지출내역 추가 UI 화면
void plusSpendPromiseScene(void);               // 지출 예약내역 추가 UI 화면

// 내역 전체 보여주기 UI 화면들
void lookIncomeScene(char* listData);           // 수입내역 전체보기 UI 화면
void lookSpendScene(char* listData);            // 지출내역 전체보기 UI 화면
void lookSpendPromiseScene(char* listData);     // 지출 예약내역 전체보기 UI 화면

// 지출 한도 설정 UI 화면
void setupSpendLimitScene(void);                

// 내역 검색 및 보여주기 UI 화면들
void searchIncomeScene(void);                   // 수입내역 검색요소 선택 UI 화면
void searchIncomeResultScene(char* searchData); // 수입내역 검색결과 보여주기 UI 화면

void searchSpendScene(void)                     // 지출내역 검색요소 선택 UI 화면
void searchSpendResultScene(char* searchData);  // 지출내역 검색요소 선택 UI 화면
    
// 나가기 및 경고 UI 화면
void WarningScene(int height);                  // 입력 오류 경고창 UI 화면
void ExitScene(void);                           // 프로그램 종료 UI 화면




// 스플래시 이미지
void Splash_Screen(void) {
    Clear();	// 프롬프트 Clear
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
	LoadSpin(100, "");
}



// 0. 메인 메뉴
void mainMenuScene(void) {
    Clear();	// 프롬프트 Clear
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●        📝 가계부 관리 프로그램 By 5팀		  ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║                   📒메인 메뉴                     ║\n");
    printf("║                                                   ║\n");
	printf("║       1. 📝수입 관리        2. 📑지출 관리        ║\n");
    printf("║                                                   ║\n");
	printf("║       3. 🔍내역 검색        " LIGHT_RED "q. ⛔종료하기" WHITE "         ║\n" WHITE);
    printf("║                                                   ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
    printf("╔═══════════════════════════════════════════════════╗\n");
    printf("║ ▶️ 입력:                                           ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
}

// 1. 수입 메뉴 (0-1)
void incomeMenuScene(void) {
    Clear();	// 프롬프트 Clear
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●        📝 가계부 관리 프로그램 By 5팀		  ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║                   📒수입 메뉴                     ║\n");
    printf("║                                                   ║\n");
	printf("║    1. 📝수입목록 추가      2. 📑수입목록 보기      ║\n");
    printf("║                                                   ║\n");
	printf("║      " YELLOW "z. 🚪뒤로가기         " LIGHT_RED "  q. ⛔종료하기" WHITE "        ║\n" WHITE);
    printf("║                                                   ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
    printf("╔═══════════════════════════════════════════════════╗\n");
    printf("║ ▶️ 입력:                                           ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
}

// 2. 지출 메뉴 (0-2)
void spendMenuScene(void) {
    char* notice = getSpendLimit(); // 지출 현황 문구
    Clear();	// 프롬프트 Clear
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●        📝 가계부 관리 프로그램 By 5팀		  ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║"BLUE " %s   " WHITE "║\n", notice);
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║                   📒지출 메뉴                     ║\n");
    printf("║                                                   ║\n");
	printf("║   1. 📝지출목록 추가        2. 📑지출목록 보기     ║\n");
    printf("║                                                   ║\n");
	printf("║   3. 📝지출한도 설정        4. 📑지출예약 설정     ║\n");    
    printf("║                                                   ║\n");
	printf("║      " YELLOW "z. 🚪뒤로가기         " LIGHT_RED "  q. ⛔종료하기" WHITE "        ║\n" WHITE);
    printf("║                                                   ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
    printf("╔═══════════════════════════════════════════════════╗\n");
    printf("║ ▶️ 입력:                                           ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
}

// 3. 검색 메뉴 (0-2)
void searchMenuScene(void) {
    Clear();	// 프롬프트 Clear
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●        📝 가계부 관리 프로그램 By 5팀		  ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║                   📒검색 메뉴                     ║\n");
    printf("║                                                   ║\n");
	printf("║       1. 📑수입 목록 날짜 / 카테고리 검색           ║\n");
    printf("║                                                   ║\n");
	printf("║       2. 📑지출 목록 날짜 / 카테고리 검색           ║\n");
    printf("║                                                   ║\n");
	printf("║       " YELLOW "z. 🚪뒤로가기        " LIGHT_RED "q. ⛔종료하기" WHITE "           ║\n" WHITE);
    printf("║                                                   ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
    printf("╔═══════════════════════════════════════════════════╗\n");
    printf("║ ▶️ 입력:                                           ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
}




// 수입 내역 추가 화면
void plusIncomeScene(void) {
    Clear();	// 프롬프트 Clear
    printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●               📝 수입 내역 등록                  ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║  📅날짜:                                           ║\n");
    printf("║  💰금액:                                             ║\n");
    printf("║  🛍️수입처:                                          ║\n");
    printf("║  🧾메모:                                            ║\n");
    printf("║  📅카테고리:                                        ║\n");
    printf("║                                                   ║\n");
    printf("║       " YELLOW "z. 🚪뒤로가기        " LIGHT_RED "q. ⛔종료하기" WHITE "           ║\n" WHITE);
    printf("╚═══════════════════════════════════════════════════╝\n");
    printf("╔═══════════════════════════════════════════════════╗\n");
    printf("║                                                   ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
}

// 지출 내역 추가 화면
void plusSpendScene(void) {
    Clear();	// 프롬프트 Clear
    printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●               📝 지출 내역 등록                  ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║  📅날짜:                                           ║\n");
    printf("║  💰금액:                                             ║\n");
    printf("║  🛍️지출처:                                          ║\n");
    printf("║  🧾메모:                                            ║\n");
    printf("║  📅카테고리:                                        ║\n");
    printf("║                                                   ║\n");
    printf("║       " YELLOW "z. 🚪뒤로가기        " LIGHT_RED "q. ⛔종료하기" WHITE "           ║\n" WHITE);
    printf("╚═══════════════════════════════════════════════════╝\n");
    printf("╔═══════════════════════════════════════════════════╗\n");
    printf("║                                                   ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
}

// 지출 예약 내역 추가 화면
void plusSpendPromiseScene(void) {
    Clear();	// 프롬프트 Clear
    printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●            📝 지출 예약 내역 등록                ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║  📅날짜:                                           ║\n");
    printf("║  💰금액:                                             ║\n");
    printf("║  🛍️지출처:                                          ║\n");
    printf("║  🧾메모:                                            ║\n");
    printf("║  📅카테고리:                                        ║\n");
    printf("║                                                   ║\n");
    printf("║       " YELLOW "z. 🚪뒤로가기        " LIGHT_RED "q. ⛔종료하기" WHITE "           ║\n" WHITE);
    printf("╚═══════════════════════════════════════════════════╝\n");
    printf("╔═══════════════════════════════════════════════════╗\n");
    printf("║                                                   ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
}




// 수입 내역 출력 화면
void lookIncomeScene(char* listData) {
    Clear();	// 프롬프트 Clear
    printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●                 📝 수입 내역                     ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║       " YELLOW "z. 🚪뒤로가기        " LIGHT_RED "q. ⛔종료하기" WHITE "           ║\n" WHITE);
    printf("╚═══════════════════════════════════════════════════╝\n");
    printf("%s\n", listData);
	printf("╔═══════════════════════════════════════════════════╗\n");
    printf("║ ▶️ 입력:                                           ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
}

// 지출 내역 출력 화면
void lookSpendScene(char* listData) {
    Clear();	// 프롬프트 Clear
    printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●                 📝 지출 내역                   ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║       " YELLOW "z. 🚪뒤로가기        " LIGHT_RED "q. ⛔종료하기" WHITE "           ║\n" WHITE);
    printf("╚═══════════════════════════════════════════════════╝\n");
    printf("%s\n", listData);
	printf("╔═══════════════════════════════════════════════════╗\n");
    printf("║ ▶️ 입력:                                           ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
}

// 지출 예약 내역 출력 화면
void lookSpendPromiseScene(char* listData) {
    Clear();	// 프롬프트 Clear
    printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●              📝 지출 예약 내역                 ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║       " YELLOW "z. 🚪뒤로가기        " LIGHT_RED "q. ⛔종료하기" WHITE "           ║\n" WHITE);
    printf("╚═══════════════════════════════════════════════════╝\n");
    printf("%s\n", listData);
	printf("╔═══════════════════════════════════════════════════╗\n");
    printf("║ ▶️ 입력:                                           ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
}




// 수입 내역 검색요소 선택 화면
void searchIncomeScene(void) {
    Clear();	// 프롬프트 Clear
    printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●               🔎 수입 내역 검색                  ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║ 1. 📝날짜검색 (yyyy-mm-dd)   2. 📑카테고리 검색    ║\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║ ▶️ 검색 요소 선택:                                 ║\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║ ▶️ 검색:                                           ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
}

// 수입 검색내역 출력 화면
void searchIncomeResultScene(char* searchData) {
    Clear();	// 프롬프트 Clear
    printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●             🔎 수입 내역 검색 결과               ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║       " YELLOW "z. 🚪뒤로가기        " LIGHT_RED "q. ⛔종료하기" WHITE "           ║\n" WHITE);
    printf("╚═══════════════════════════════════════════════════╝\n");
    printf("%s\n", searchData);
	printf("╔═══════════════════════════════════════════════════╗\n");
    printf("║ ▶️ 입력:                                           ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
}


// 지출 내역 검색요소 선택 화면
void searchSpendScene(void) {
    Clear();	// 프롬프트 Clear
    printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●               🔎 지출 내역 검색                  ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║ 1. 📝날짜검색 (yyyy-mm-dd)   2. 📑카테고리 검색    ║\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║ ▶️ 검색 요소 선택:                                 ║\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║ ▶️ 검색:                                           ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
}

// 지출 검색내역 출력 화면
void searchSpendResultScene(char* searchData) {
    Clear();	// 프롬프트 Clear
    printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●             🔎 지출 내역 검색 결과               ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║       " YELLOW "z. 🚪뒤로가기        " LIGHT_RED "q. ⛔종료하기" WHITE "           ║\n" WHITE);
    printf("╚═══════════════════════════════════════════════════╝\n");
    printf("%s\n", searchData);
	printf("╔═══════════════════════════════════════════════════╗\n");
    printf("║ ▶️ 입력:                                           ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
}




// 지출 한도 설정 화면
void setupSpendLimitScene(void) {
    Clear();	// 프롬프트 Clear
    printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●              📝 지출 한도 설정                   ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║ ▶️ 한도 설정 금액:                                 ║\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║       " YELLOW "z. 🚪뒤로가기        " LIGHT_RED "q. ⛔종료하기" WHITE "           ║\n" WHITE);
    printf("╚═══════════════════════════════════════════════════╝\n");
	printf("╔═══════════════════════════════════════════════════╗\n");
    printf("║ ▶️ 입력:                                           ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
}

// 경고 추가 화면
void WarningScene(int height) {
    gotoxy(1, height);
    printf(LIGHT_RED "╔═══════════════════════════════════════════════════╗\n");
    printf("║" YELLOW " ⚠️Error: 정해진 번호 안에서 입력해주세요." LIGHT_RED "          ║\n");
    printf("╚═══════════════════════════════════════════════════╝" WHITE);
}

// 종료 화면
void ExitScene(void) {
    Clear();	// 프롬프트 Clear
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●        📝 가계부 관리 프로그램 By 5팀		  ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
    gotoxy(1, 4);
    printf("║                                                   ║\n");
    disappearText("Thank You For Playing!");
    Clear();
    exit(0);
}


#endif // UI_H