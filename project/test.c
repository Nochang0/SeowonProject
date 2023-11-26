// 기본 라이브러리
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <json-c/json.h>

// 커스텀 라이브러리
#include "./lib/data_manager.h"
#include "./lib/fs.h"
#include "./lib/ui.h"
#include "./lib/prompt.h"
#include "./lib/util.h"

// 파일
#define INCOME_FILE_PATH "./db/income.json"
#define SPEND_FILE_PATH "./db/spend.json"
#define SPEND_LIMIT_FILE_PATH "./db/spendLimit.txt"
#define SPEND_PROMISE_FILE_PATH "./db/spendPromise.json"
#define RECENT_LISTID_FILE_PATH "./db/uniqueNum.txt"

// 지역 함수
static void Main(void);
static void Income(void);
static void Spend(void);
static void Search(void);
static void Move(int menuNum, char moveNum);


// Entry Point
void main(void) {
    Splash_Screen();
    Main();
}

// 0. 메인 메뉴
static void Main(void) {
    char getScene = selectMainMenu();
    while (true) {
        switch (getScene) {
            case '1':		// 수입 관리
                return Income();
            case '2':		// 지출 관리
                return Spend();
            case '3':		// 내역 검색
                return Search();
            default:		// 종료 (q)
                return ExitScene();
        }
    }
}

// 1. 수입 메뉴
static void Income(void) {
    char move;
    char getScene = selectIncomeMenu();
    while (true) {
        switch (getScene) {
            case '1':		// 수입목록 추가
                move = plusIncomeList();  // 수입 내역 입력 & 저장
                Move(1, move);
            case '2':		// 수입목록 보기
                move = showIncomeList();  // 수입 내역 출력
                Move(1, move);
            case 'z':		// 뒤로가기 (메인 메뉴)
                return Main();
            default:		// 종료 (q)
                return ExitScene();
        }
    }
}

// 2. 지출 메뉴
static void Spend(void) {
    char move;
    char getScene = selectSpendMenu();
    while (true) {
        switch (getScene) {
            case '1':		// 지출목록 추가
                move = plusSpendList();    // 수입 내역 입력 & 저장   
                Move(2, move);
            case '2':		// 지출목록 보기
                move = showSpendList();  // 지출 내역 출력
                Move(2, move);
            case '3':		// 지출한도 설정
                move = updateSpendLimit();  // 지출 한도 설정
                Move(2, move);
            case '4':		// 지출예약 설정
                move = plusSpendPromiseList();  // 수입 내역 입력 & 저장
                Move(2, move);
            case 'z':		// 뒤로가기 (메인 메뉴)
                return Main();
            default:		// 종료 (q)
                return ExitScene();
        }
    }
}

// 3. 검색 메뉴
static void Search(void) {
    char move;
    char getScene = selectSearchMenu();
    while (true) {
        switch (getScene) {
            case '1':		// 수입내역 날짜/카테고리 검색
                move = findIncomeList();
                Move(3, move);
            case '2':		// 지출내역 날짜/카테고리 검색
                move = findSpendList();
                Move(3, move);
            case 'z':		// 뒤로가기 (메인 메뉴)
                return Main();
            default:		// 종료 (q)
                return ExitScene();
        }
    }
}

// 메뉴별 화면 전환
static void Move(int menuNum, char moveNum) {
    if (moveNum == 'z') {
        switch(menuNum) {
            case 1:
                    return Income();
            case 2:
                    return Spend();
            default:
                    return Search();
        }
    } else {
        return ExitScene();     // 종료 (q)
    } 
}


// cd /workspace/SeowonCProject/project/ && gcc ./test.c -o /tmp/a.out -lm -ljson-c && clear && /tmp/a.out