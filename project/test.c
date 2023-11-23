// 기본 라이브러리
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <json-c/json.h>

// 커스텀 라이브러리
#include "./lib/fs.h"
#include "./lib/ui.h"
#include "./lib/prompt.h"


static void Main();
static void Income();
static void Spend();
static void Search();


// Entry-Point
void main(void) {
    Splash_Screen();
    Main();
}

// 메인 메뉸
static void Main(void) {
    mainMenu();				// 메인 메뉴 UI 장면
    char* getScene = inputBarByMainMenu();
    while (true) {
        switch (getScene) {
            case "0-1":		// 수입 관리
                Income();
                break;
            case "0-2":		// 지출 관리
                Spend();
                break;
            case "0-3":		// 내역 검색
                Search();
                break;
            default:		// 종료
                ExitScene();
        }
    }
}

// 수입 메뉴
static void Income(void) {
    incomeMenu();			// 수입 메뉴 UI 장면
    char* getScene = inputBarByIncomeMenu();
    while (true) {
        switch (getScene) {
            case "1-1":		// 수입목록 추가
                incomeMenu();
                char* getMove = inputBarByIncomeMenu();
                Income(getMove);
                break;
            case "1-2":		// 수입목록 보기
                spendMenu();
                char* getMove = inputBarBySpendMenu();
                Spend(getMove);
                break;
            case 'z':		// 뒤로가기 (메인 메뉴)
                Main();
                break;
            default:		// 종료
                ExitScene();
        }
    }
}

// 지출 메뉴
static void Spend(void) {
    spendMenu();			// 지출 메뉴 UI 장면
    char* getScene = inputBarBySpendMenu();
    while (true) {
        switch (getScene) {
            case "2-1":		// 지출목록 추가
                incomeMenu();
                char* getMove = inputBarByIncomeMenu();
                Income(getMove);
                break;
            case "2-2":		// 지출목록 보기
                spendMenu();
                char* getMove = inputBarBySpendMenu();
                Spend(getMove);
                break;
            case "2-3":		// 지출한도 설정
                spendMenu();
                char* getMove = inputBarBySpendMenu();
                Spend(getMove);
                break;
            case "2-4":		// 지출예약 설정
                spendMenu();
                char* getMove = inputBarBySpendMenu();
                Spend(getMove);
                break;
            case 'z':		// 뒤로가기 (메인 메뉴)
                Main();
                break;
            default:		// 종료
                ExitScene();
        }
    }
}

// 검색 메뉴
static void Search(void) {
    searchMenu();			// 수입 메뉴 UI 장면
    char* getScene = inputBarByIncomeMenu();
    while (true) {
        switch (getScene) {
            case "3-1":		// 수입 관리
                incomeMenu();
                char* getMove = inputBarByIncomeMenu();
                Income(getMove);
                break;
            case "3-2":		// 지출 관리
                spendMenu();
                char* getMove = inputBarBySpendMenu();
                Spend(getMove);
                break;
            case 'z':		// 뒤로가기 (메인 메뉴)
                Main();
                break;
            default:		// 종료
                ExitScene();
        }
    }
}

// cd /workspace/SeowonCProject/project/ && gcc ./test.c -o /tmp/a.out -lm -ljson-c && clear && /tmp/a.out