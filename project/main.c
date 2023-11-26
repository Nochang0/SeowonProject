// 기본 라이브러리
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <json-c/json.h>

// 커스텀 라이브러리
#include "./lib/fs.h"
#include "./lib/ui.h"
#include "./lib/util.h"
#include "./lib/prompt.h"
#include "./lib/data_manager.h"

// 기본 메뉴 함수
static void Main(void);     // 메인 메뉴
static void Income(void);   // 수입 메뉴
static void Spend(void);    // 지출 메뉴
static void Search(void);   // 검색 메뉴
static void Move(int menuNum, char moveNum);    // 수입, 지출, 검색 메뉴에 속하는 작업 실행 후 화면 전환 (메뉴이동 또는 종료)


// 시작점 함수
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


// cd /workspace/SeowonCProject/project/ && gcc ./main.c -o /tmp/a.out -lm -ljson-c -lncurses && clear && /tmp/a.out