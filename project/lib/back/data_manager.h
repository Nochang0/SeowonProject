#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

// 기본 라이브러리
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <json-c/json.h>

// 커스텀 라이브러리
#include "../../lib/back/fs.h"

// 매크로 변수
#define INCOME_FILE_PATH "./db/income.json"                 // 수입 내역 파일
#define SPEND_FILE_PATH "./db/spend.json"                   // 지출 내역 파일
#define SPEND_LIMIT_FILE_PATH "./db/spendLimit.txt"         // 지출 한도 파일
#define SPEND_PROMISE_FILE_PATH "./db/spendPromise.json"    // 지출 예약 내역 파일
#define RECENT_LISTID_FILE_PATH "./db/uniqueNum.txt"        // 내역 고유번호 파일
#define RECENT_MONEY_FILE_PATH "./db/money.txt"             // 현재 내 소지금 파일

// 내역 추가 데이터 구조체 (수입|지출)
struct InputInfo {
    char Date[100];     // 날짜
    char Amount[100];   // 금액
    char Source[100];   // 수입처|지출처
    char Memo[100];     // 메모글
    char Tag[100];      // 카테고리
};

// 내역 출력 UI 관련 구조체 (~Scene 함수)
struct ShowInfo {
    int listHeight;     // 입력바 삽입 높이
    char* listData;     // 내역 데이터
};

// 커스텀 함수 목록
static bool updatelistId(char* listId); 							// 내역 고유번호를 업데이트
bool updateMoney(int turnMoney, bool act);                          // 내 소지금을 업데이트

// 변환 관련 함수
char* createIncomeInfo(struct InputInfo Incomedata);                // 저장할 수입 데이터를 JSON 변환합니다.
char* createSpendInfo(struct InputInfo Spenddata);                  // 저장할 지출&예약 데이터를 JSON 변환합니다.

// 추가 관련 함수 (prompt.h)
bool addIncomeList(char* HistoryData);				                // 수입 내역 추가
bool addSpendList(char* HistoryData);				                // 지출 내역 추가
bool addSpendPromise(char* HistoryData);			                // 지출 예약내역 추가
bool setSpendLimit(char* spendPrice);				                // 지출 한도 설정

// 출력 관련 함수 (UI, ~Scene관련 함수들)
char* getSpendLimit(void);								            // 지출 현황 공지를 출력 (UI)
struct ShowInfo getIncomeList(void);                                // 수입 내역과 줄바꿈 상수 구조체 반환 (UI)
struct ShowInfo getSpendList(void);                                 // 지출 내역과 줄바꿈 상수 구조체 반환 (UI)
struct ShowInfo getSpendPromiseList(void);                          // 지출 예약내역과 줄바꿈 상수 구조체 반환 (UI)
struct ShowInfo findDate(char* jsonData, char* actList, char* targetDate);	// 수입 및 지출 내역의 날짜 검색결과 반환 (UI)
struct ShowInfo findTag(char* jsonData, char* actList, char* targetTag);	// 수입 및 지출 내역의 카테고리 검색결과 반환 (UI)

    
    
// 내역 고유번호 업데이트 (RETURN: true)
static bool updatelistId(char* listId) {
    char PushlistId[100];							// 저장할 내역 고유번호
    int NewlistId = (int)(atoi(listId) + 1);		// 새로운 내역 고유번호
    sprintf(PushlistId, "%d", NewlistId);			// 문자열 변경
    
    saveFile(RECENT_LISTID_FILE_PATH, PushlistId);	// 내역 고유번호 파일 저장
    return true;
}

// 현재 내 소지금 업데이트 (RETURN: true)
bool updateMoney(int turnMoney, bool act) {
    char* Money = loadFile(RECENT_MONEY_FILE_PATH);   // 현재 소지금
    char* PushMoney = malloc(1000);      // 저장할 소지금
    
    // 수입
    if (act) {
        int NewMoney = (int)(atoi(Money) + turnMoney);		// 수입 소지금 업데이트
        sprintf(PushMoney, "%d", NewMoney);		
    }
    // 지출
    else {
        int NewMoney = (int)(atoi(Money) - turnMoney);		// 지출 소지금 업데이트
        sprintf(PushMoney, "%d", NewMoney);			
    }
    
    saveFile(RECENT_MONEY_FILE_PATH, PushMoney);	// 내역 고유번호 파일 저장
    free(PushMoney);
    return true;
}

// 수입 내역 추가 (RETURN: true)
bool addIncomeList(char* HistoryData) {
    struct json_object* root;           				// 전체 리스트 내역 딕셔너리
    struct json_object* typeList;       				// 수입 | 지출내역
    struct json_object* listInfo;       				// 내역 세부 데이터
    struct json_object* amountObj;       				// 금액을 추출할 내역 객체
    char* listId = loadFile(RECENT_LISTID_FILE_PATH);	// 내역 고유번호
    
    // 수입 내역 데이터 불러오기
    char* jsonData = loadFile(INCOME_FILE_PATH);
    
    // 기존 JSON 데이터 파싱
    root = json_tokener_parse(jsonData);

    // 새로운 내역 데이터 파싱
    listInfo = json_tokener_parse(HistoryData);

    // "수입목록" 객체 가져오기
    json_object_object_get_ex(root, "수입목록", &typeList);

    // "수입목록" 객체에 새로운 데이터 추가
    json_object_object_add(typeList, listId, listInfo);
    
    // 내역 파일 업데이트
    saveFile(INCOME_FILE_PATH, json_object_to_json_string_ext(root, JSON_C_TO_STRING_PRETTY));
    
    // 메모리 누수 방지
    json_object_put(root);
    
    // 내역 고유번호 업데이트
    updatelistId(listId);           
    return true;
}

// 지출 내역 추가 (RETURN: true)
bool addSpendList(char* HistoryData) {
    struct json_object* root;           				// 전체 리스트 내역
    struct json_object* typeList;       				// 수입 | 지출내역
    struct json_object* listInfo;       				// 내역 세부 데이터
    struct json_object* amountObj;       				// 금액을 추출할 내역 객체
    char* listId = loadFile(RECENT_LISTID_FILE_PATH);	// 내역 고유번호
    
    // 지출 내역 데이터 불러오기
    char* jsonData = loadFile(SPEND_FILE_PATH);
    
    // 기존 JSON 데이터 파싱
    root = json_tokener_parse(jsonData);

    // 새로운 내역 데이터 파싱
    listInfo = json_tokener_parse(HistoryData);

    // "지출목록" 객체 가져오기
    json_object_object_get_ex(root, "지출목록", &typeList);

    // "지출목록" 객체에 새로운 데이터 추가
    json_object_object_add(typeList, listId, listInfo);
    
    // 내역 파일 업데이트
    saveFile(SPEND_FILE_PATH, json_object_to_json_string_ext(root, JSON_C_TO_STRING_PRETTY));
    
    // 메모리 누수 방지
    json_object_put(root);
    
    // 내역 고유번호 업데이트
    updatelistId(listId);
    return true;
}

// 지출 한도 설정 (RETURN: true)
bool setSpendLimit(char* spendPrice) {
    // 지출 한도 저장
    saveFile(SPEND_LIMIT_FILE_PATH, spendPrice);
    return true;
}

// 지출 예약 내역 추가 (RETURN: true)
bool addSpendPromise(char* HistoryData) {
    struct json_object* root;           				// 전체 리스트 내역
    struct json_object* typeList;       				// 수입 | 지출내역
    struct json_object* listInfo;       				// 내역 세부 데이터
    char* listId = loadFile(RECENT_LISTID_FILE_PATH);	// 내역 고유번호
    
    // 지출 예약 내역 데이터 불러오기
    char* jsonData = loadFile(SPEND_PROMISE_FILE_PATH);
    
    // 기존 JSON 데이터 파싱
    root = json_tokener_parse(jsonData);

    // 새로운 내역 데이터 파싱
    listInfo = json_tokener_parse(HistoryData);

    // "지출예약목록" 객체 가져오기
    json_object_object_get_ex(root, "지출예약목록", &typeList);

    // "지출예약목록" 객체에 새로운 데이터 추가
    json_object_object_add(typeList, listId, listInfo);
    
    // 내역 파일 업데이트
    saveFile(SPEND_PROMISE_FILE_PATH, json_object_to_json_string_ext(root, JSON_C_TO_STRING_PRETTY));
    
    // 메모리 누수 방지
    json_object_put(root);
    updatelistId(listId);
    return true;
}

// 내역 날짜 검색
struct ShowInfo findDate(char* jsonData, char* actList, char* targetDate) {
    struct json_object* root = json_tokener_parse(jsonData);
    struct ShowInfo searchData;     // UI 관련 구조체 (내역, 텍스트 높이)
    int listNum = 0;                // 내역 텍스트 높이
    
    // "지출|수입 목록" 객체 가져오기
    struct json_object* typeList;
    if (json_object_object_get_ex(root, actList, &typeList)) {
        size_t resultLength = 1; // 결과 문자열 길이 (초기값 1)
        char* result = (char*)malloc(resultLength);
        result[0] = '\0'; // 문자열 초기화

        // 각 내역의 "날짜" 항목을 확인하여 필터링
        json_object_object_foreach(typeList, key, value) {
            struct json_object* dateObj;
            if (json_object_object_get_ex(value, "날짜", &dateObj)) {
                const char* date = json_object_get_string(dateObj);

                // 날짜가 targetDate로 시작하는 경우에만 문자열에 추가
                if (strncmp(date, targetDate, strlen(targetDate)) == 0) {
                    // 필요한 문자열 길이 계산
                    size_t keyLength = strlen(key);
                    size_t dateLength = strlen(date);
                    size_t infoLength = json_object_object_length(value) * 50; // 예상되는 정보 길이

                    // 동적으로 메모리 재할당하여 문자열 길이 늘리기
                    resultLength += keyLength + dateLength + infoLength;
                    result = (char*)realloc(result, resultLength);

                    // 문자열에 정보 추가
                    sprintf(result + strlen(result), "내역 고유번호: %s\n", key);

                    // 기타 필요한 정보 추가
                    json_object_object_foreach(value, innerKey, innerValue) {
                        sprintf(result + strlen(result), "%s: %s\n", innerKey, json_object_get_string(innerValue));
                    }
                    strcat(result, "-----------------------------------------------------\n"); // 줄바꿈 추가
                    listNum++;
                }
            }
        }

        searchData.listHeight = listNum;    // 높이
        searchData.listData = result;       // 내역 검색 데이터
        
        json_object_put(root);
        return searchData;
    } else {
        json_object_put(root);
        // return "지출목록을 찾을 수 없습니다.";
    }
}

// 내역 카테고리 검색
struct ShowInfo findTag(char* jsonData, char* actList, char* targetTag) {
    struct json_object* root = json_tokener_parse(jsonData);
    struct ShowInfo searchData;     // UI 관련 구조체 (내역, 텍스트 높이)
    int listNum = 0;                // 내역 텍스트 높이
    
    // "지출|수입 목록" 객체 가져오기
    struct json_object* typeList;
    if (json_object_object_get_ex(root, actList, &typeList)) {
        size_t resultLength = 1; // 결과 문자열 길이 (초기값 1)
        char* result = (char*)malloc(resultLength);
        result[0] = '\0'; // 문자열 초기화

        // 각 내역의 "카테고리" 항목을 확인하여 필터링
        json_object_object_foreach(typeList, key, value) {
            struct json_object* tagObj;
            if (json_object_object_get_ex(value, "카테고리", &tagObj)) {
                const char* tag = json_object_get_string(tagObj);

                // 카테고리가 targetTag로 시작하는 경우에만 문자열에 추가
                if (strncmp(tag, targetTag, strlen(targetTag)) == 0) {
                    // 필요한 문자열 길이 계산
                    size_t keyLength = strlen(key);
                    size_t tagLength = strlen(tag);
                    size_t infoLength = json_object_object_length(value) * 50; // 예상되는 정보 길이

                    // 동적으로 메모리 재할당하여 문자열 길이 늘리기
                    resultLength += keyLength + tagLength + infoLength;
                    result = (char*)realloc(result, resultLength);

                    // 문자열에 정보 추가
                    sprintf(result + strlen(result), "내역 고유번호: %s\n", key);

                    // 기타 필요한 정보 추가
                    json_object_object_foreach(value, innerKey, innerValue) {
                        sprintf(result + strlen(result), "%s: %s\n", innerKey, json_object_get_string(innerValue));
                    }
                    strcat(result, "-----------------------------------------------------\n"); // 줄바꿈 추가
                    listNum++;
                }
            }
        }
        
        searchData.listHeight = listNum;    // 높이
        searchData.listData = result;       // 내역 검색 데이터
        
        json_object_put(root);
        return searchData;
    } else {
        json_object_put(root);
        // return "지출목록을 찾을 수 없습니다.";
    }
}

// 수입 내역 UI 구조체 출력
struct ShowInfo getIncomeList(void) {
    struct json_object* root;		// 전체 리스트 내역
    struct json_object* incomeList;	// 수입 내역
    struct json_object* entry;		// 내역 세부 데이터
    struct ShowInfo incomeData;     // UI 관련 구조체 (내역, 텍스트 높이)
    
    char* result = malloc(1000); 	// 적절한 크기로 메모리 동적 할당
    char entryText[500]; 			// 각 항목을 저장할 임시 문자열 배열
    int listNum = 0;                // 내역 개수 초기화
    
    // 수입 내역 데이터 불러오기
    char* jsonData = loadFile(INCOME_FILE_PATH);
    
    root = json_tokener_parse(jsonData);
    json_object_object_get_ex(root, "수입목록", &incomeList);
    sprintf(result, "");

    json_object_object_foreach(incomeList, key, val) {
        sprintf(entryText, "\"내역 고유번호\": \"%s\",\n", key);  // 키 값을 추가
        strcat(result, entryText);

        entry = json_object_object_get(val, "날짜");
        sprintf(entryText, "\"날짜\": \"%s\",\n", json_object_get_string(entry));
        strcat(result, entryText);

        entry = json_object_object_get(val, "금액");
        sprintf(entryText, "\"금액\": \"%s\",\n", json_object_get_string(entry));
        strcat(result, entryText);

        entry = json_object_object_get(val, "수입처");
        sprintf(entryText, "\"수입처\": \"%s\",\n", json_object_get_string(entry));
        strcat(result, entryText);

        entry = json_object_object_get(val, "메모");
        sprintf(entryText, "\"메모\": \"%s\",\n", json_object_get_string(entry));
        strcat(result, entryText);

        entry = json_object_object_get(val, "카테고리");
        sprintf(entryText, "\"카테고리\": \"%s\"\n", json_object_get_string(entry));
        strcat(result, entryText);

        strcat(result, "-----------------------------------------------------\n");
        listNum++;
    }
    
    incomeData.listHeight = listNum;    // 높이
    incomeData.listData = result;       // 내역 데이터
    
    // 메모리 누수 방지
    json_object_put(root);
    return incomeData;
}

// 지출 내역 UI 구조체 출력
struct ShowInfo getSpendList(void) {
    struct json_object* root;		// 전체 리스트 내역
    struct json_object* spendList;	// 지출 내역
    struct json_object* entry;		// 내역 세부 데이터
    struct ShowInfo spendData;     // UI 관련 구조체 (내역, 텍스트 높이)
    
    char* result = malloc(1000); 	// 적절한 크기로 메모리 동적 할당
    char entryText[500]; 			// 각 항목을 저장할 임시 문자열 배열
    int listNum = 0;                    // 내역 개수 초기화
    
    // 지출 내역 데이터 불러오기
    char* jsonData = loadFile(SPEND_FILE_PATH);
    
    root = json_tokener_parse(jsonData);
    json_object_object_get_ex(root, "지출목록", &spendList);
    sprintf(result, "");

    json_object_object_foreach(spendList, key, val) {
        sprintf(entryText, "\"내역 고유번호\": \"%s\",\n", key);  // 키 값을 추가
        strcat(result, entryText);

        entry = json_object_object_get(val, "날짜");
        sprintf(entryText, "\"날짜\": \"%s\",\n", json_object_get_string(entry));
        strcat(result, entryText);

        entry = json_object_object_get(val, "금액");
        sprintf(entryText, "\"금액\": \"%s\",\n", json_object_get_string(entry));
        strcat(result, entryText);

        entry = json_object_object_get(val, "수입처");
        sprintf(entryText, "\"수입처\": \"%s\",\n", json_object_get_string(entry));
        strcat(result, entryText);

        entry = json_object_object_get(val, "메모");
        sprintf(entryText, "\"메모\": \"%s\",\n", json_object_get_string(entry));
        strcat(result, entryText);

        entry = json_object_object_get(val, "카테고리");
        sprintf(entryText, "\"카테고리\": \"%s\"\n", json_object_get_string(entry));
        strcat(result, entryText);

        strcat(result, "-----------------------------------------------------\n");
        listNum++;
    }
        
    spendData.listHeight = listNum;    // 높이
    spendData.listData = result;       // 내역 데이터
    
    // 메모리 누수 방지
    json_object_put(root);
    return spendData;
}

// 지출 예약 내역 UI 구조체 출력
struct ShowInfo getSpendPromiseList(void) {
    struct json_object* root;		// 전체 리스트 내역
    struct json_object* spendList;	// 지출 내역
    struct json_object* entry;		// 내역 세부 데이터
    struct ShowInfo spendPromiseData;     // UI 관련 구조체 (내역, 텍스트 높이)
    
    char* result = malloc(1000); 	// 적절한 크기로 메모리 동적 할당
    char entryText[500]; 			// 각 항목을 저장할 임시 문자열 배열
    int listNum = 0;                    // 내역 개수 초기화

    // 지출 예약 내역 데이터 불러오기
    char* jsonData = loadFile(SPEND_PROMISE_FILE_PATH);
    
    root = json_tokener_parse(jsonData);
    json_object_object_get_ex(root, "지출예약목록", &spendList);
    sprintf(result, "");

    json_object_object_foreach(spendList, key, val) {
        sprintf(entryText, "\"내역 고유번호\": \"%s\",\n", key);  // 키 값을 추가
        strcat(result, entryText);

        entry = json_object_object_get(val, "날짜");
        sprintf(entryText, "\"날짜\": \"%s\",\n", json_object_get_string(entry));
        strcat(result, entryText);

        entry = json_object_object_get(val, "금액");
        sprintf(entryText, "\"금액\": \"%s\",\n", json_object_get_string(entry));
        strcat(result, entryText);

        entry = json_object_object_get(val, "수입처");
        sprintf(entryText, "\"수입처\": \"%s\",\n", json_object_get_string(entry));
        strcat(result, entryText);

        entry = json_object_object_get(val, "메모");
        sprintf(entryText, "\"메모\": \"%s\",\n", json_object_get_string(entry));
        strcat(result, entryText);

        entry = json_object_object_get(val, "카테고리");
        sprintf(entryText, "\"카테고리\": \"%s\"\n", json_object_get_string(entry));
        strcat(result, entryText);

        strcat(result, "-----------------------------------------------------\n");
        listNum++;
    }
    
    spendPromiseData.listHeight = listNum;    // 높이
    spendPromiseData.listData = result;       // 내역 데이터
    
    // 메모리 누수 방지
    json_object_put(root);
    return spendPromiseData;
}

// 지출 내역 현황 출력 (RETURN: "지출 한도 %s원에서 %d원을 지출하였습니다.")
char* getSpendLimit(void) {
    struct json_object* root;           // 전체 리스트 내역
    struct json_object* typeList;       // 수입 | 지출내역
    int totalPrice = 0;                 // 총지출액
    
    // 지출 내역 데이터 불러오기
    char* jsonData = loadFile(SPEND_FILE_PATH);
    
    // 지출 한도 불러오기
    char* spendLimit = loadFile(SPEND_LIMIT_FILE_PATH);
    
    // 기존 JSON 데이터 파싱
    root = json_tokener_parse(jsonData);

    // "지출목록" 객체 가져오기
    json_object_object_get_ex(root, "지출목록", &typeList);
    
    // 각 내역의 "금액" 항목을 모두 더하기
    json_object_object_foreach(typeList, key, value) {
        struct json_object *getPrice;
        if (json_object_object_get_ex(value, "금액", &getPrice)) {
            totalPrice += json_object_get_int(getPrice);
        }
    }
    // 크키 동적 할당
    char* result = (char*)malloc(1000);
    sprintf(result, "지출 한도 %s원에서 %d원을 지출하였습니다.", spendLimit, totalPrice);
    
    // 메모리 누수 방지
    json_object_put(root);
    return result;
}

// 수입 내역에 추가할 데이터 생성
char* createIncomeInfo(struct InputInfo Incomedata) {
    struct json_object *root, *incomeObject;
    
    // 최상위 JSON 객체 생성
    root = json_object_new_object();

    // 내역 객체 생성
    incomeObject = json_object_new_object();

    // 내부 객체에 속성 추가
    json_object_object_add(incomeObject, "날짜", json_object_new_string(Incomedata.Date));
    json_object_object_add(incomeObject, "금액", json_object_new_string(Incomedata.Amount));
    json_object_object_add(incomeObject, "수입처", json_object_new_string(Incomedata.Source));
    json_object_object_add(incomeObject, "메모", json_object_new_string(Incomedata.Memo));
    json_object_object_add(incomeObject, "카테고리", json_object_new_string(Incomedata.Tag));

    // JSON 문자열 반환
    return json_object_to_json_string_ext(incomeObject, JSON_C_TO_STRING_PRETTY);
}

// 지출 및 예약 내역에 추가할 데이터 생성
char* createSpendInfo(struct InputInfo Spenddata) {
    struct json_object *root, *spendObject;
    
    // 최상위 JSON 객체 생성
    root = json_object_new_object();

    // 내역 객체 생성
    spendObject = json_object_new_object();

    // 내역 객체에 속성 추가
    json_object_object_add(spendObject, "날짜", json_object_new_string(Spenddata.Date));
    json_object_object_add(spendObject, "금액", json_object_new_string(Spenddata.Amount));
    json_object_object_add(spendObject, "지출처", json_object_new_string(Spenddata.Source));
    json_object_object_add(spendObject, "메모", json_object_new_string(Spenddata.Memo));
    json_object_object_add(spendObject, "카테고리", json_object_new_string(Spenddata.Tag));

    // JSON 문자열 반환
    return json_object_to_json_string_ext(spendObject, JSON_C_TO_STRING_PRETTY);
}


#endif // DATA_MANAGER_H