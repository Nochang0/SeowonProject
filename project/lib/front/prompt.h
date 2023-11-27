#ifndef PROMPT_H
#define PROMPT_H

// 기본 라이브러리
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// 커스텀 라이브러리
#include "../../lib/back/fs.h"
#include "../../lib/front/ui.h"
#include "../../lib/util.h"
#include "../../lib/back/data_manager.h"

// 입력바 높이 변수들 (UI)
static const int eraseWidth = 40;   // 입력바 입력위치 청소할 길이
static const int FourHeight = 12;   // 메인, 수입메뉴 입력바 높이
static const int SearchHeight = 14; // 검색메뉴 입력바 높이
static const int SpendHeight = 16;  // 지출메뉴 입력바 높이
static const int plusHeight = 13;   // 내역추가 관련 입력바 높이 (plus~ 함수)
static bool clearChar = false;      // 메인메뉴 개행문자('\n') 제거 제어변수

// UI 효과 관련 함수 (Util)
static void loadScene(int height);  // 입력 엔터 후 로딩 효과
static void allInputScene(void);    // 내역추가 관련 저장 알림 효과 (plus~ 함수)

// RETURN: 화면 전환 기호(char)
// 메뉴 선택 함수
char selectMainMenu(void);          // 0: 메인메뉴 선택창
char selectIncomeMenu(void);        // 1: 수입메뉴 선택창
char selectSpendMenu(void);         // 2: 지출메뉴 선택창
char selectSearchMenu(void);        // 3: 검색메뉴 선택창

// 내역 추가 함수
char plusIncomeList(void);          // 1-1: 수입내역 추가
char plusSpendList(void);           // 2-1: 지출내역 추가
char plusSpendPromiseList(void);    // 2-4: 지출 예약내역 추가

// 내역 출력 함수
char showIncomeList(void);          // 1-2: 수입내역 출력
char showSpendList(void);           // 2-2: 지출내역 출력
char showSpendPromiseList(void);    // 지출 예약내역 출력

// 내역 검색결과 출력 함수
char findIncomeList(void);          // 3-1: 수입내역 검색 및 출력 (날짜, 카테고리)
char findSpendList(void);           // 3-2: 지출내역 검색 및 출력 (날짜, 카테고리)

// 지출 한도 설정 함수
char updateSpendLimit(void);        // 2-3: 지출한도 금액 설정



// 선택 메뉴 (메인 메뉴에서)
char selectMainMenu(void) {
    mainMenuScene();				// 메인 메뉴 UI 장면
    char moveNum;					// 이동 기호 입력
    char menuArr[] = { '1', '2', '3', 'q' };		// 입력 값 배열   
    
    gotoxy(11, FourHeight);
    printf(LIGHT_GREEN);
    
    if (clearChar) getchar();
    scanf("%c", &moveNum);

	while (1) {
        // 선택지를 잘 골랐을 경우
        if (isArray(moveNum, menuArr)) {
            loadScene(FourHeight);
            return moveNum;
        } else {
            WarningScene(FourHeight+2);
            gotoxy(eraseWidth, FourHeight);
            printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
            gotoxy(1, FourHeight);
            printf(WHITE "║ ▶️ 입력: " LIGHT_GREEN);
            while (getchar() != '\n');
            
            scanf("%c", &moveNum);
            continue;
        }
    }
}

// 선택 메뉴 (수입 메뉴에서)
char selectIncomeMenu(void) {
    incomeMenuScene();	                    // 수입 메뉴 UI 장면
    char moveNum;					        // 이동 기호 입력
    char menuArr[] = { '1', '2', 'z', 'q' };	// 입력 값 배열
    
    gotoxy(11, FourHeight);
    printf(LIGHT_GREEN);
    
    getchar();
    scanf("%c", &moveNum);
    
	while (1) {
        // 선택지를 잘 골랐을 경우
        if (isArray(moveNum, menuArr)) {
            loadScene(FourHeight);
            clearChar = true;
            return moveNum;
        } else {
            WarningScene(FourHeight+2);
            gotoxy(eraseWidth, FourHeight);
            printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
            gotoxy(1, FourHeight);
            printf(WHITE "║ ▶️ 입력: " LIGHT_GREEN);
            while (getchar() != '\n');
            
            scanf("%c", &moveNum);
            continue;
        }
    }
    
}

// 선택 메뉴 (지출 메뉴에서)
char selectSpendMenu(void) {
    spendMenuScene();				// 지출 메뉴 UI 장면
    char moveNum;					                    // 이동 기호 입력
    char menuArr[] = { '1', '2', '3', '4', 'z', 'q' };	// 입력 값 배열
    
    gotoxy(11, SpendHeight);
    printf(LIGHT_GREEN);
    getchar();
    scanf("%c", &moveNum);

	while (1) {
        // 선택지를 잘 골랐을 경우
        if (isArray(moveNum, menuArr)) {
            loadScene(SpendHeight);
            clearChar = true;
            return moveNum;
        } else {
            WarningScene(SpendHeight+2);

            gotoxy(eraseWidth, SpendHeight);
            printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
            gotoxy(1, SpendHeight);
            printf(WHITE "║ ▶️ 입력: " LIGHT_GREEN);
            while (getchar() != '\n');
            
            scanf("%c", &moveNum);
            continue;
        }
    }
}

// 선택 메뉴 (검색 메뉴에서)
char selectSearchMenu(void) {
    searchMenuScene();				// 검색 메뉴 UI 화면
    static char moveNum;					                    // 이동 기호 입력
    static char menuArr[] = { '1', '2', '3', '4', 'z', 'q' };	// 입력 값 배열
    
    gotoxy(11, SearchHeight);
    printf(LIGHT_GREEN);
    
    getchar();
    scanf("%c", &moveNum);
    
	while (1) {
        // 선택지를 잘 골랐을 경우
        if (isArray(moveNum, menuArr)) {
            loadScene(SearchHeight);
            clearChar = true;
            return moveNum;
        } else {
            WarningScene(SearchHeight+2);
            gotoxy(eraseWidth, SearchHeight);
            printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
            gotoxy(1, SearchHeight);
            printf(WHITE "║ ▶️ 입력: " LIGHT_GREEN);
            
            while (getchar() != '\n');
            scanf("%c", &moveNum);
            continue;
        }
    }
}



// 수입 내역 추가하기
char plusIncomeList(void) {
    char moveNum;                               // 이동 기호 입력
    char menuArr[] = { 'z', 'q' };		        // 입력 값 배열 
    struct InputInfo Incomedata;	            // 업데이트 내역 구조체
    
    // 수입 내역 추가 화면
    plusIncomeScene();	            

    // 날짜
    gotoxy(11, 4);
    printf(LIGHT_GREEN);
    scanf("%s", Incomedata.Date);
    // printf(LIGHT_CYAN "%s", Incomedata.Date);
    
    // 금액
    gotoxy(11, 5);
    scanf("%s", Incomedata.Amount);
    
    // 수입처
    gotoxy(13, 6);
    scanf("%s", Incomedata.Source);
    
    // 메모
    gotoxy(11, 7);
    scanf("%s", Incomedata.Memo);
    
    // 카테고리
    gotoxy(15, 8);
    scanf("%s", Incomedata.Tag);

    // 입력 후 로딩 효과
    gotoxy(1, plusHeight);
    LoadSpin(50, "║ ");
    gotoxy(1, plusHeight);
    printf(WHITE "║ ▶️ 입력:              " LIGHT_GREEN);
    
    // JSON으로 문자열 데이터 재구성
    char* listjson = createIncomeInfo(Incomedata);
    
    // 수입 목록에 추가 (true)
    addIncomeList(listjson);
    
    // 저장완료 표시
    allInputScene();
    gotoxy(1, plusHeight+2);
    printf(GREEN "저장 완료했습니다." LIGHT_GREEN);
    
    // 이동 기호 입력 받기
    gotoxy(11, plusHeight);
    getchar();
    scanf("%c", &moveNum);
    
    while (1) {
        // 선택지를 잘 골랐을 경우
        if (isArray(moveNum, menuArr)) {
            loadScene(plusHeight);
            return moveNum;
        } else {
            WarningScene(plusHeight+2);
            gotoxy(eraseWidth, plusHeight);
            printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
            gotoxy(1, plusHeight);
            printf(WHITE "║ ▶️ 입력: " LIGHT_GREEN);
            while (getchar() != '\n');
            
            scanf("%c", &moveNum);
            continue;
        }
    }
    return moveNum;
}

// 지출 내역 추가하기
char plusSpendList(void) {
    char moveNum;                               // 이동 기호 입력
    char menuArr[] = { 'z', 'q' };		        // 입력 값 배열 
    struct InputInfo Spenddata;	            // 업데이트 내역 구조체
    
    // 수입 내역 추가 화면
    plusSpendScene();	            

    // 날짜 (현재 날짜 자동 입력)
    gotoxy(11, 4);
    printf(LIGHT_GREEN);
    scanf("%s", Spenddata.Date);
    
    // 금액
    gotoxy(11, 5);
    scanf("%s", Spenddata.Amount);
    
    // 수입처
    gotoxy(13, 6);
    scanf("%s", Spenddata.Source);
    
    // 메모
    gotoxy(11, 7);
    scanf("%s", Spenddata.Memo);
    
    // 카테고리
    gotoxy(15, 8);
    scanf("%s", Spenddata.Tag);

    // 입력 후 로딩 효과
    gotoxy(1, plusHeight);
    LoadSpin(50, "║ ");
    gotoxy(1, plusHeight);
    printf(WHITE "║ ▶️ 입력:              " LIGHT_GREEN);
    
    // JSON으로 문자열 데이터 재구성
    char* listjson = createIncomeInfo(Spenddata);
    
    // 수입 목록에 추가 (true)
    addSpendList(listjson);
    
    // 저장완료 표시
    allInputScene();
    gotoxy(1, plusHeight+2);
    printf(GREEN "저장 완료했습니다." LIGHT_GREEN);
    
    // 이동 기호 입력 받기
    gotoxy(11, plusHeight);
    getchar();
    scanf("%c", &moveNum);
    
    while (1) {
        // 선택지를 잘 골랐을 경우
        if (isArray(moveNum, menuArr)) {
            loadScene(plusHeight);
            return moveNum;
        } else {
            WarningScene(plusHeight+2);
            gotoxy(eraseWidth, plusHeight);
            printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
            gotoxy(1, plusHeight);
            printf(WHITE "║ ▶️ 입력: " LIGHT_GREEN);
            while (getchar() != '\n');
            
            scanf("%c", &moveNum);
            continue;
        }
    }
    return moveNum;
}

// 지출 예약 내역 추가하기
char plusSpendPromiseList(void) {
    char moveNum;                       // 이동 기호 입력
    char menuArr[] = { 'z', 'q' };		// 입력 값 배열 
    struct InputInfo Spenddata;	        // 업데이트 내역 구조체
    
    // 수입 내역 추가 화면
    plusSpendPromiseScene();	            

    // 날짜 (현재 날짜 자동 입력)
    gotoxy(11, 4);
    printf(LIGHT_GREEN);
    scanf("%s", Spenddata.Date);
    
    // 금액
    gotoxy(11, 5);
    scanf("%s", Spenddata.Amount);
    
    // 수입처
    gotoxy(13, 6);
    scanf("%s", Spenddata.Source);
    
    // 메모
    gotoxy(11, 7);
    scanf("%s", Spenddata.Memo);
    
    // 카테고리
    gotoxy(15, 8);
    scanf("%s", Spenddata.Tag);

    // 입력 후 로딩 효과
    gotoxy(1, plusHeight);
    LoadSpin(50, "║ ");
    gotoxy(1, plusHeight);
    printf(WHITE "║ ▶️ 입력:              " LIGHT_GREEN);
    
    // JSON으로 문자열 데이터 재구성
    char* listjson = createIncomeInfo(Spenddata);
    
    // 수입 목록에 추가 (true)
    addSpendPromise(listjson);
    
    // 저장완료 표시
    allInputScene();
    gotoxy(1, plusHeight+2);
    printf(GREEN "저장 완료했습니다." LIGHT_GREEN);
    
    // 이동 기호 입력 받기
    gotoxy(11, plusHeight);
    getchar();
    scanf("%c", &moveNum);
    
    while (1) {
        // 선택지를 잘 골랐을 경우
        if (isArray(moveNum, menuArr)) {
            loadScene(plusHeight);
            return moveNum;
        } else {
            WarningScene(plusHeight+2);
            gotoxy(eraseWidth, plusHeight);
            printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
            gotoxy(1, plusHeight);
            printf(WHITE "║ ▶️ 입력: " LIGHT_GREEN);
            while (getchar() != '\n');
            
            scanf("%c", &moveNum);
            continue;
        }
    }
    return moveNum;
}



// 수입 내역 보여주기
char showIncomeList(void) {
    char moveNum;                   // 이동 기호 입력
    char menuArr[] = { 'z', 'q' };  // 입력 값 배열
    struct ShowInfo Incomedata;	    // 수입내역&입력바높이 구조체
    
    // 수입 내역 데이터 구조체
    Incomedata = getIncomeList();
    
    // 수입 내역 화면
    lookIncomeScene(Incomedata.listData);
    
    // 입력바 높이
    int ShowHeight = Incomedata.listHeight*7+8;
    
    // 이동 기호 입력 받기
    gotoxy(11, ShowHeight);
    printf(LIGHT_GREEN);
    getchar();
    scanf("%c", &moveNum);
    
    while (1) {
        // 선택지를 잘 골랐을 경우
        if (isArray(moveNum, menuArr)) {
            loadScene(ShowHeight);
            return moveNum;
        } else {
            WarningScene(ShowHeight+2);
            gotoxy(eraseWidth, ShowHeight);
            printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
            gotoxy(1, ShowHeight);
            printf(WHITE "║ ▶️ 입력: " LIGHT_GREEN);
            while (getchar() != '\n');
    
            scanf("%c", &moveNum);
            continue;
        }
    }
    return moveNum;
}

// 지출 내역 보여주기
char showSpendList(void) {
    char moveNum;                   // 이동 기호 입력
    char menuArr[] = { 'z', 'q' };  // 입력 값 배열
    struct ShowInfo Spenddata;	    // 수입내역&입력바높이 구조체
    
    // 지출 내역 데이터 구조체
    Spenddata = getSpendList();
    
    // 지출 내역 화면
    lookSpendScene(Spenddata.listData);
    
    // 입력바 높이
    int ShowHeight = Spenddata.listHeight*7+8;
    
    // 이동 기호 입력 받기
    gotoxy(11, ShowHeight);
    printf(LIGHT_GREEN);
    getchar();
    scanf("%c", &moveNum);
    
    while (1) {
        // 선택지를 잘 골랐을 경우
        if (isArray(moveNum, menuArr)) {
            loadScene(ShowHeight);
            return moveNum;
        } else {
            WarningScene(ShowHeight+2);
            gotoxy(eraseWidth, ShowHeight);
            printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
            gotoxy(1, ShowHeight);
            printf(WHITE "║ ▶️ 입력: " LIGHT_GREEN);
            while (getchar() != '\n');
    
            scanf("%c", &moveNum);
            continue;
        }
    }
    return moveNum;
}

// 지출 예약 내역 보여주기
char showSpendPromiseList(void) {
    char moveNum;                       // 이동 기호 입력
    char menuArr[] = { 'z', 'q' };      // 입력 값 배열
    struct ShowInfo SpendPromisedata;	// 수입내역&입력바높이 구조체
    
    // 지출 예약 내역 데이터 구조체
    SpendPromisedata = getSpendPromiseList();
    
    // 지출 예약 내역 화면
    lookSpendPromiseScene(SpendPromisedata.listData);
    
    // 입력바 높이
    int ShowHeight = SpendPromisedata.listHeight*7+8;
    
    // 이동 기호 입력 받기
    gotoxy(11, ShowHeight);
    printf(LIGHT_GREEN);
    getchar();
    scanf("%c", &moveNum);
    
    while (1) {
        // 선택지를 잘 골랐을 경우
        if (isArray(moveNum, menuArr)) {
            loadScene(ShowHeight);
            return moveNum;
        } else {
            WarningScene(ShowHeight+2);
            gotoxy(eraseWidth, ShowHeight);
            printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
            gotoxy(1, ShowHeight);
            printf(WHITE "║ ▶️ 입력: " LIGHT_GREEN);
            while (getchar() != '\n');
    
            scanf("%c", &moveNum);
            continue;
        }
    }
    return moveNum;
}



// 수입 내역 검색하기
char findIncomeList(void) {
    char moveNum, choose;               // 이동 기호 입력, 검색 요소
    char menuArr[] = { 'z', 'q' };      // 입력 값 배열
    char searchArr[] = { '1', '2' };    // 검색 요소 배열 (날짜, 테그)
    char* word = malloc(100);           // 검색어
    
    // 수입 내역 데이터 불러오기
    char* jsonData = loadFile(INCOME_FILE_PATH);
    
    // 수입 검색 요소 선택 UI 화면
    searchIncomeScene();
    
    // 검색 요소 입력받기
    gotoxy(21, 6);
    printf(LIGHT_CYAN);
    getchar();
    scanf("%c", &choose);
    
    // 선택지에 없는 것 입력 시 메인 화면 이동
    if (!isArray(choose, searchArr)) {
        loadScene(21);
        return 'z';
    }
    
    // 검색어 입력받기
    gotoxy(11, 8);
    printf(WHITE);
    getchar();
    scanf("%s", word);
    
    // 결과 문자열 데이터
    struct ShowInfo fineResult = (choose == '1') ? findDate(jsonData, "수입목록", word) : findTag(jsonData, "수입목록", word);
    
    // 결과 화면
    searchIncomeResultScene(fineResult.listData);
    
    // 입력바 높이
    int FindHeight = fineResult.listHeight*7+8;
    
    // 이동 기호 입력 받기
    gotoxy(11, FindHeight);
    printf(LIGHT_GREEN);
    getchar();
    scanf("%c", &moveNum);
    
    while (1) {
        // 선택지를 잘 골랐을 경우
        if (isArray(moveNum, menuArr)) {
            loadScene(FindHeight);
            return moveNum;
        } else {
            WarningScene(FindHeight+2);
            gotoxy(eraseWidth, FindHeight);
            printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
            gotoxy(1, FindHeight);
            printf(WHITE "║ ▶️ 입력: " LIGHT_GREEN);
            while (getchar() != '\n');
    
            scanf("%c", &moveNum);
            continue;
        }
    }
    return moveNum;
}

// 지출 내역 검색하기
char findSpendList(void) {
    char moveNum, choose;               // 이동 기호 입력, 검색 요소
    char menuArr[] = { 'z', 'q' };      // 입력 값 배열
    char searchArr[] = { '1', '2' };    // 검색 요소 배열 (날짜, 테그)
    char* word = malloc(100);                         // 검색어
    
    // 지출 내역 데이터 불러오기
    char* jsonData = loadFile(SPEND_FILE_PATH);
    
    // 지출 검색 요소 선택 UI 화면
    searchSpendScene();
    
    // 검색 요소 입력받기
    gotoxy(21, 6);
    printf(LIGHT_CYAN);
    getchar();
    scanf("%c", &choose);
    
    // 선택지에 없는 것 입력 시 메인 화면 이동
    if (!isArray(choose, searchArr)) {
        loadScene(21);
        return 'z';
    }
    
    // 검색어 입력받기
    gotoxy(11, 8);
    printf(WHITE);
    getchar();
    scanf("%s", word);
    
    // 결과 문자열 데이터
    struct ShowInfo fineResult = (choose == '1') ? findDate(jsonData, "지출목록", word) : findTag(jsonData, "지출목록", word);
    
    // 결과 화면
    searchIncomeResultScene(fineResult.listData);
    
    // 입력바 높이
    int FindHeight = fineResult.listHeight*7+8;
    
    // 이동 기호 입력 받기
    gotoxy(11, FindHeight);
    printf(LIGHT_GREEN);
    getchar();
    scanf("%c", &moveNum);
    
    while (1) {
        // 선택지를 잘 골랐을 경우
        if (isArray(moveNum, menuArr)) {
            loadScene(FindHeight);
            return moveNum;
        } else {
            WarningScene(FindHeight+2);
            gotoxy(eraseWidth, FindHeight);
            printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
            gotoxy(1, FindHeight);
            printf(WHITE "║ ▶️ 입력: " LIGHT_GREEN);
            while (getchar() != '\n');
    
            scanf("%c", &moveNum);
            continue;
        }
    }
    return moveNum;
}



// 지출 한도 설정하기
char updateSpendLimit(void) {
    char moveNum;                   // 이동 기호 입력
    char menuArr[] = { 'z', 'q' };  // 입력 값 배열
    char* limit = malloc(100);      // 지출 한도 액
    
    // 지출 한도 설정 UI 화면
    setupSpendLimitScene();
    
    // 한도 액 입력받기
    gotoxy(21, 4);
    printf(LIGHT_CYAN);
    getchar();
    scanf("%s", limit);
    
    // 지출 한도액 설정 및 저장
    setSpendLimit(limit);
    
    // 이동 기호 입력 받기
    gotoxy(11, 9);
    printf(LIGHT_GREEN);
    getchar();
    scanf("%c", &moveNum);
    
    while (1) {
        // 선택지를 잘 골랐을 경우
        if (isArray(moveNum, menuArr)) {
            loadScene(9);
            return moveNum;
        } else {
            WarningScene(9+2);
            gotoxy(eraseWidth, 9);
            printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
            gotoxy(1, 9);
            printf(WHITE "║ ▶️ 입력: " LIGHT_GREEN);
            while (getchar() != '\n');
    
            scanf("%c", &moveNum);
            continue;
        }
    }
    return moveNum;
}


// 화면 전환 로딩 효과 (검색바)
static void loadScene(int height) {
    gotoxy(10, height);
    LoadSpin(50, "║ ");
}

// '저장 완료' 표시 (내역 추가 관련 특별 UI)
static void allInputScene() {
    // 날짜
    gotoxy(11, 4);
    printf(CYAN);
    printf("저장 완료                     ");
    
    // 금액
    gotoxy(11, 5);
    printf("저장 완료                     ");
    
    // 수입처
    gotoxy(13, 6);
    printf("저장 완료                     ");
    
    // 메모
    gotoxy(11, 7);
    printf("저장 완료                     ");
    
    // 카테고리
    gotoxy(15, 8);
    printf("저장 완료                     ");
    printf(WHITE);
}

#endif // PROMPT_H