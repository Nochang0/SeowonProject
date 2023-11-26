#ifndef PROMPT_H
#define PROMPT_H


#define RED     		"\x1b[31m"
#define LIGHT_RED       "\033[1;31m"
#define GREEN   		"\x1b[0;32m"
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

static const int FourHeight = 11;
static const int SearchHeight = 12;
static const int SpendHeight = 12;
static const int InputHeight = 12;
static bool clearChar = false;

char inputBarByMainMenu(void);
char inputBarByIncomeMenu(void);
char inputBarBySpendMenu(void);
char inputBarBySearchMenu(void);
static void loadScene(int height);
char inputIncomeList(void);
char inputSpendList(void);

// 내역 추가 구조체
// struct InputInfo {
//     char* Date;     // 날짜
//     char* Amount;   // 금액
//     char* Source;   // 수입 | 지출 처
//     char* Memo;     // 메모글
//     char* Tag;      // 카테고리
// };

// 선택 메뉴 (메인 메뉴에서)
char inputBarByMainMenu(void) {
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
            gotoxy(11, FourHeight);
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
char inputBarByIncomeMenu(void) {
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
            gotoxy(11, FourHeight);
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
char inputBarBySpendMenu(void) {
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

            gotoxy(11, SpendHeight);
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
char inputBarBySearchMenu(void) {
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
            gotoxy(11, SearchHeight);
            printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
            gotoxy(1, SearchHeight);
            printf(WHITE "║ ▶️ 입력: " LIGHT_GREEN);
            
            while (getchar() != '\n');
            scanf("%c", &moveNum);
            continue;
        }
    }
}

// 수입 내역 받기
char inputIncomeList(void) {
    char moveNum;                               // 이동 기호 입력
    char menuArr[] = { 'z', 'q' };		        // 입력 값 배열 
    struct InputInfo Incomedata;	            // 업데이트 내역 구조체
    Incomedata.Date = getDate();	            // 현재 날짜 저장
    
    // 수입 내역 추가 화면
    plusIncomeScene();	            

    // 날짜 (현재 날짜 자동 입력)
    gotoxy(11, 4);
    printf(LIGHT_CYAN "%s", Incomedata.Date);
    
    // 금액
    gotoxy(11, 5);
    printf(LIGHT_GREEN);
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
    gotoxy(1, 12);
    LoadSpin(50, "║ ");
    gotoxy(1, InputHeight);
    printf(WHITE "║ ▶️ 입력:              " LIGHT_GREEN);
    
    // JSON으로 문자열 데이터 재구성
    char* listjson = createIncomeInfo(Incomedata);
    
    // 수입 목록에 추가 (true)
    addIncomeList(listjson);
    
    // 저장완료 표시
    gotoxy(1, InputHeight+2);
    printf(GREEN "저장 완료했습니다." LIGHT_GREEN);
    
    // 이동 기호 입력 받기
    gotoxy(11, InputHeight);
    getchar();
    scanf("%c", &moveNum);
    
    while (1) {
        // 선택지를 잘 골랐을 경우
        if (isArray(moveNum, menuArr)) {
            loadScene(InputHeight);
            
            return moveNum;
        } else {
            WarningScene(InputHeight+2);
            gotoxy(11, InputHeight);
            printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
            gotoxy(1, InputHeight);
            printf(WHITE "║ ▶️ 입력: " LIGHT_GREEN);
            while (getchar() != '\n');
            
            scanf("%c", &moveNum);
            continue;
        }
    }
    return moveNum;
}

// 지출 내역 받기
char inputSpendList(void) {
    char moveNum;                               // 이동 기호 입력
    char menuArr[] = { 'z', 'q' };		        // 입력 값 배열 
    struct InputInfo Spenddata;	            // 업데이트 내역 구조체
    Spenddata.Date = getDate();	            // 현재 날짜 저장
    
    // 수입 내역 추가 화면
    plusSpendScene();	            

    // 날짜 (현재 날짜 자동 입력)
    gotoxy(11, 4);
    printf(LIGHT_CYAN "%s", Spenddata.Date);
    
    // 금액
    gotoxy(11, 5);
    printf(LIGHT_GREEN);
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
    gotoxy(1, 12);
    LoadSpin(50, "║ ");
    gotoxy(1, InputHeight);
    printf(WHITE "║ ▶️ 입력:              " LIGHT_GREEN);
    
    // JSON으로 문자열 데이터 재구성
    char* listjson = createIncomeInfo(Spenddata);
    
    // 수입 목록에 추가 (true)
    addSpendList(listjson);
    
    // 저장완료 표시
    gotoxy(1, InputHeight+2);
    printf(GREEN "저장 완료했습니다." LIGHT_GREEN);
    
    // 이동 기호 입력 받기
    gotoxy(11, InputHeight);
    getchar();
    scanf("%c", &moveNum);
    
    while (1) {
        // 선택지를 잘 골랐을 경우
        if (isArray(moveNum, menuArr)) {
            loadScene(InputHeight);
            return moveNum;
        } else {
            WarningScene(InputHeight+2);
            gotoxy(11, InputHeight);
            printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
            gotoxy(1, InputHeight);
            printf(WHITE "║ ▶️ 입력: " LIGHT_GREEN);
            while (getchar() != '\n');
            
            scanf("%c", &moveNum);
            continue;
        }
    }
    return moveNum;
}

// 지출 예약 내역 받기
char inputSpendPromiseList(void) {
    char moveNum;                               // 이동 기호 입력
    char menuArr[] = { 'z', 'q' };		        // 입력 값 배열 
    struct InputInfo Spenddata;	            // 업데이트 내역 구조체
    Spenddata.Date = getDate();	            // 현재 날짜 저장
    
    // 수입 내역 추가 화면
    plusSpendPromiseScene();	            

    // 날짜 (현재 날짜 자동 입력)
    gotoxy(11, 4);
    printf(LIGHT_CYAN "%s", Spenddata.Date);
    
    // 금액
    gotoxy(11, 5);
    printf(LIGHT_GREEN);
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
    gotoxy(1, 12);
    LoadSpin(50, "║ ");
    gotoxy(1, InputHeight);
    printf(WHITE "║ ▶️ 입력:              " LIGHT_GREEN);
    
    // JSON으로 문자열 데이터 재구성
    char* listjson = createIncomeInfo(Spenddata);
    
    // 수입 목록에 추가 (true)
    addSpendPromise(listjson);
    
    // 저장완료 표시
    gotoxy(1, InputHeight+2);
    printf(GREEN "저장 완료했습니다." LIGHT_GREEN);
    
    // 이동 기호 입력 받기
    gotoxy(11, InputHeight);
    getchar();
    scanf("%c", &moveNum);
    
    while (1) {
        // 선택지를 잘 골랐을 경우
        if (isArray(moveNum, menuArr)) {
            loadScene(InputHeight);
            
            return moveNum;
        } else {
            WarningScene(InputHeight+2);
            gotoxy(11, InputHeight);
            printf("\033[1K");		// 현재 위치에서 줄의 시작까지 지움
            gotoxy(1, InputHeight);
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
            gotoxy(11, ShowHeight);
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
            gotoxy(11, ShowHeight);
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
            gotoxy(11, ShowHeight);
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
            gotoxy(11, 9);
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


// 수입 내역 검색하기
char fineIncomeList(void) {
    char moveNum, choose;               // 이동 기호 입력, 검색 요소
    char menuArr[] = { 'z', 'q' };      // 입력 값 배열
    char searchArr[] = { '1', '2' };    // 검색 요소 배열 (날짜, 테그)
    char* word;                         // 검색어
    
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
    if (isArray(choose, searchArr)) {
        loadScene(21);
        return 'z';
    }
    
    // 검색어 입력받기
    gotoxy(11, 8);
    printf(WHITE);
    getchar();
    scanf("%s", word);
    
    char* fineResult = (choose == '1') ? findDate(jsonData, "수입목록", word) : findTag(jsonData, "수입목록", word);
    
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
            gotoxy(11, 9);
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

#endif // PROMPT_H