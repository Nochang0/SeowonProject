// 기본 라이브러리
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <json-c/json.h>

// 커스텀 라이브러리
#include "./lib/back/fs.h"
#include "./lib/front/ui.h"
#include "./lib/util.h"
#include "./lib/front/prompt.h"
#include "./lib/back/data_manager.h"

// 기본 메뉴 함수
static void Main(void);     // 메인 메뉴
static void Income(void);   // 수입 메뉴
static void Spend(void);    // 지출 메뉴
static void Search(void);   // 검색 메뉴
static void Move(int menuNum, char moveNum);    // 수입, 지출, 검색 메뉴에 속하는 작업 실행 후 화면 전환 (메뉴이동 또는 종료)


// 시작점 함수
void main(void) {
    
    // 스플래시 이미지
    Splash_Screen();
    
    // 메인 메뉴 시작
    Main();
}

// 0. 메인 메뉴
static void Main(void) {
    char getScene = selectMainMenu();	// 메인메뉴 작업선택
    
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
    char moveNum;	// 메뉴 이동 기호 (작업 선택 후)
    char getScene = selectIncomeMenu();	// 수입메뉴 작업선택
    
    while (true) {
        switch (getScene) {
            case '1':		// 수입목록 추가
                moveNum = plusIncomeList();
                Move(1, moveNum);
            case '2':		// 수입목록 보기
                moveNum = showIncomeList();
                Move(1, moveNum);
            case 'z':		// 뒤로가기 (메인 메뉴)
                return Main();
            default:		// 종료 (q)
                return ExitScene();
        }
    }
}

// 2. 지출 메뉴
static void Spend(void) {
    char moveNum;	// 메뉴 이동 기호 (작업 선택 후)
    char getScene = selectSpendMenu();	// 지출메뉴 작업선택
    
    while (true) {
        switch (getScene) {
            case '1':		// 지출목록 추가
                moveNum = plusSpendList();    
                Move(2, moveNum);
            case '2':		// 지출목록 보기
                moveNum = showSpendList();  
                Move(2, moveNum);
            case '3':		// 지출한도 설정
                moveNum = updateSpendLimit();  
                Move(2, moveNum);
            case '4':		// 지출예약 설정
                moveNum = plusSpendPromiseList();
                Move(2, moveNum);
            case 'z':		// 뒤로가기 (메인 메뉴)
                return Main();
            default:		// 종료 (q)
                return ExitScene();
        }
    }
}

// 3. 검색 메뉴
static void Search(void) {
    char moveNum;	// 메뉴 이동 기호 (작업 선택 후)
    char getScene = selectSearchMenu();	// 검색메뉴 작업선택
    while (true) {
        switch (getScene) {
            case '1':		// 수입내역 날짜/카테고리 검색
                moveNum = findIncomeList();
                Move(3, moveNum);
            case '2':		// 지출내역 날짜/카테고리 검색
                moveNum = findSpendList();
                Move(3, moveNum);
            case 'z':		// 뒤로가기 (메인 메뉴)
                return Main();
            default:		// 종료 (q)
                return ExitScene();
        }
    }
}

// 작업 후 화면 전환
static void Move(int menuNum, char moveNum) {
    if (moveNum == 'z') {
        switch(menuNum) {
            case 1:		// 뒤로가기 (수입 메뉴)
                return Income();
            case 2:		// 뒤로가기 (지출 메뉴)
                return Spend();
            default:	// 뒤로가기 (검색 메뉴)
                return Search();
        }
        
    } else {
        return ExitScene(); // 종료 (q)
    }
}


// cd /workspace/SeowonCProject/project/ && gcc ./main.c -o /tmp/a.out -lm -ljson-c -lncurses && clear && /tmp/a.out