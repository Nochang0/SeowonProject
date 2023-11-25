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
#include <string.h>
#include <stdbool.h>

// 커스텀 라이브러리
#include "../lib/fs.h"
#include "../lib/data_manager.h"
#include "../lib/ui.h"
#include "../lib/util.h"

static int Fourheight = 11;
static int Sixheight = 14;

char inputBarByMainMenu(void);
char inputBarByIncomeMenu(void);
char inputBarBySpendMenu(void);
char inputBarBySearchMenu(void);
static void moveScene(int height);

// 내역 추가 구조체
struct InputInfo {
    char* Date;     // 날짜
    char* Amount;   // 금액
    char* Source;   // 수입 | 지출 처
    char* Memo;     // 메모글
    char* Tag;      // 카테고리
};


char inputBarByMainMenu(void) {
    mainMenuScene();				// 메인 메뉴 UI 장면
    char moveNum;					// 이동 기호 입력
    char* menuArr = "123q";			// 입력 값 배열
    
    inputBarScene(Fourheight);
    
    gotoxy(11, Fourheight);
    scanf("%c", &moveNum);

	while (true) {
        // 선택지를 잘 골랐을 경우
        if (isArray(moveNum, menuArr, sizeof(menuArr) / sizeof(menuArr[0]))) {
            moveScene(Fourheight);
            return moveNum;
        } else {
            WarningScene(Fourheight+2);

            gotoxy(11, Fourheight);
            printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
            gotoxy(1, Fourheight);
            printf(WHITE "║ ▶️ 입력: " LIGHT_GREEN);
            scanf("%c", &moveNum);
            continue;
        }
    }
}

char inputBarByIncomeMenu(void) {
    incomeMenuScene();			    // 수입 메뉴 UI 장면
    char moveNum;					// 이동 기호 입력
    char* menuArr = "12zq";			// 입력 값 배열
    
    inputBarScene(Fourheight);
    
    gotoxy(11, Fourheight);
    scanf("%c", &moveNum);

	while (true) {
        // 선택지를 잘 골랐을 경우
        if (isArray(moveNum, menuArr, sizeof(menuArr) / sizeof(menuArr[0]))) {
            moveScene(Fourheight);
            return moveNum;
            
        } else {
            WarningScene(Fourheight+2);

            gotoxy(11, Fourheight);
            printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
            gotoxy(1, Fourheight);
            printf(WHITE "║ ▶️ 입력: " LIGHT_GREEN);
            scanf("%c", &moveNum);
            continue;
        }
    }
}

char inputBarBySpendMenu(void) {
    spendMenuScene();				// 지출 메뉴 UI 장면
    
    char moveNum;					// 이동 기호 입력
    char* menuArr = "1234zq";		// 입력 값 배열
    static int Sixheight = 15;      // 지출 입력바 높이
    
    inputBarScene(Sixheight);
    
    gotoxy(11, Sixheight);
    scanf("%c", &moveNum);

	while (true) {
        // 선택지를 잘 골랐을 경우
        if (isArray(moveNum, menuArr, sizeof(menuArr) / sizeof(menuArr[0]))) {
            moveScene(Sixheight+3);
            return moveNum;
        } else {
            WarningScene(Sixheight+2);

            gotoxy(11, Sixheight);
            printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
            gotoxy(1, Sixheight);
            printf(WHITE "║ ▶️ 입력: " LIGHT_GREEN);
            scanf("%c", &moveNum);
            continue;
        }
    }
}

char inputBarBySearchMenu(void) {
    searchMenuScene();				// 검색 메뉴 UI 화면
    char moveNum;					// 이동 기호 입력
    char* menuArr = "123q";			// 입력 값 배열
    
    inputBarScene(Sixheight);
    
    gotoxy(11, 11);
    scanf("%c", &moveNum);

	while (true) {
        // 선택지를 잘 골랐을 경우
        if (isArray(moveNum, menuArr, sizeof(menuArr) / sizeof(menuArr[0]))) {
            moveScene(Sixheight);
            return moveNum;
        } else {
            WarningScene(Sixheight+2);

            gotoxy(11, Sixheight);
            printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
            gotoxy(1, Sixheight);
            printf(WHITE "║ ▶️ 입력: " LIGHT_GREEN);
            scanf("%c", &moveNum);
            continue;
        }
    }
}

// 수입 내역 받기
char* inputIncomeList(void) {
    struct InputInfo Incomedata;	// 업데이트 내역 구조체
    Incomedata.Date = getDate();	// 현재 날짜 저장
    
    // 수입 내역 추가 화면
    plusIncomeScene();	            

    // 날짜 (현재 날짜 자동 입력)
    gotoxy(8, 4);
    printf(LIGHT_CYAN "%s", Incomedata.Date);
    
    // 금액
    gotoxy(8, 5);
    scanf(LIGHT_GREEN "%s", Incomedata.Amount);
    
    // 수입처
    gotoxy(9, 6);
    scanf("%s", Incomedata.Source);
    
    // 메모
    gotoxy(8, 7);
    scanf("%s", Incomedata.Memo);
    
    // 카테고리
    gotoxy(10, 8);
    scanf("%s", Incomedata.Tag);

    // 입력 후 로딩 효과
    gotoxy(1, 10);
    LoadSpin(50, "");
    
    // JSON으로 문자열 데이터 재구성
    char* listjson = createIncomeInfo(Incomedata);
    return listjson;
}

// 지출 내역 받기
char* inputSpendList(void) {
    struct InputInfo Spenddata;	    // 업데이트 내역 구조체
    Spenddata.Date = getDate();	    // 현재 날짜 저장
    
    // 지출내역 추가 UI 화면
    plusSpendScene();

    // 날짜
    gotoxy(8, 4);
    printf(LIGHT_CYAN "%s", Spenddata.Date);
    
    // 금액
    gotoxy(8, 5);
    scanf(LIGHT_GREEN "%s", Spenddata.Amount);
    
    // 수입처
    gotoxy(9, 6);
    scanf("%s", Spenddata.Source);
    
    // 메모
    gotoxy(8, 7);
    scanf("%s", Spenddata.Memo);
    
    // 카테고리
    gotoxy(10, 8);
    scanf("%s", Spenddata.Tag);

    // JSON으로 문자열 데이터 재구성
    char* listjson = createIncomeInfo(Spenddata);
    return listjson;
}

// 화면 전환 로딩 효과
static void moveScene(int height) {
    gotoxy(10, height);
    LoadSpin(50, "║ ");
}

#endif // PROMPT_H