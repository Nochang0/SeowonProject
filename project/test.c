// 기본 라이브러리
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <json-c/json.h>
#include <locale.h>

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
static void Main();
static void Income();
static void Spend();
static void Search();


// Entry-Point
void main(void) {
    Splash_Screen();
    Main();
}

// 메인 메뉴
static void Main(void) {
    char getScene = inputBarByMainMenu();
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

// 수입 메뉴
static void Income(void) {
    char move;
    char getScene = inputBarByIncomeMenu();
    while (true) {
        switch (getScene) {
            case '1':		// 수입목록 추가
                move = inputIncomeList();  // 수입 내역 입력 & 저장
                if (move == 'z')
                    return Income();
                else 
                    return ExitScene();
                
            case '2':		// 수입목록 보기
                move = showIncomeList();  // 수입 내역 출력
                if (move == 'z') 
                    return Income();
                else 
                    return ExitScene();
            case 'z':		// 뒤로가기 (메인 메뉴)
                return Main();
            default:		// 종료 (q)
                return ExitScene();
        }
    }
}

// 지출 메뉴
static void Spend(void) {
    char move;
    char getScene = inputBarBySpendMenu();
    while (true) {
        switch (getScene) {
            case '1':		// 지출목록 추가
                move = inputSpendList();    // 수입 내역 입력 & 저장
                if (move == 'z')            // 뒤로 가기
                    return Spend();        
                else 
                    return ExitScene();     // 종료 (q)
            case '2':		// 지출목록 보기
                move = showSpendList();  // 지출 내역 출력
                if (move == 'z') 
                    return Spend();
                else 
                    return ExitScene();     // 종료 (q)
            case '3':		// 지출한도 설정
                move = updateSpendLimit();  // 지출 한도 설정
                if (move == 'z')
                    return Spend();
                else 
                    return ExitScene();     // 종료 (q)
            case '4':		// 지출예약 설정
                move = inputSpendPromiseList();  // 수입 내역 입력 & 저장
                if (move == 'z')
                    return Spend();
                else 
                    return ExitScene();     // 종료 (q)
            case 'z':		// 뒤로가기 (메인 메뉴)
                return Main();
            default:		// 종료 (q)
                return ExitScene();
        }
    }
}

// 검색 메뉴
static void Search(void) {
    char getScene = inputBarBySearchMenu();
    while (true) {
        switch (getScene) {
            case '1':		// 수입내역 날짜검색
                return printf("1");
            case '2':		// 수입내역 테그검색
                return printf("1");
            case '3':		// 지출내역 날짜검색
                return printf("1");
            case '4':		// 지출내역 테그검색
                return printf("1");
            case 'z':		// 뒤로가기 (메인 메뉴)
                return Main();
            default:		// 종료 (q)
                return ExitScene();
        }
    }
}


// cd /workspace/SeowonCProject/project/ && gcc ./test.c -o /tmp/a.out -lm -ljson-c && clear && /tmp/a.out