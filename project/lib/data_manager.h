#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

// 기본 라이브러리
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <json-c/json.h>

// 커스텀 라이브러리
#include "../lib/fs.h"
#include "../lib/prompt.h"

// 매크로 변수
#define INCOME_FILE_PATH "./db/income.json"
#define SPEND_FILE_PATH "./db/spend.json"
#define SPEND_LIMIT_FILE_PATH "./db/spendLimit.txt"
#define SPEND_PROMISE_FILE_PATH "./db/spendPromise.json"
#define RECENT_LISTID_FILE_PATH "./db/uniqueNum.txt"

// 함수 목록
static int updatelistId(char* listId); 								// 내역 고유번호를 업데이트 및 출력합니다.
bool addIncomeList(char* HistoryData);				                // 수입 내역을 추가합니다.
bool addSpendList(char* HistoryData);				                // 지출 내역을 추가합니다.
bool setSpendLimit(char* spendPrice);				                // 지출 한도를 설정합니다.
char* getSpendLimit(void);								            // 지출 내역 현황을 출력합니다.
bool setSpendPromise(char* HistoryData);			                // 지출 예약 내역을 추가합니다.
char* findDate(char* jsonData, char* actList, char* targetDate);	// 수입 및 지출 내역을 날짜로 검색합니다.
char* findTag(char* jsonData, char* actList, char* targetTag);		// 수입 및 지출 내역을 카테고리로 검색합니다.
char* createIncomeInfo(struct InputInfo Incomedata);
char* createSpendInfo(struct InputInfo Spenddata);
    

// 내역 고유번호 업데이트 및 출력 (RETURN: 새로운 내역 고유번호)
static int updatelistId(char* listId) {
    char PushlistId[999];							// 저장할 내역 고유번호
    int NewlistId = (int)(atoi(listId) + 1);		// 새로운 내역 고유번호
    sprintf(PushlistId, "%d", NewlistId);			// 문자열 변경
    
    saveFile(RECENT_LISTID_FILE_PATH, PushlistId);	// 내역 고유번호 파일 저장
    return NewlistId;
}

// 수입 내역 추가 (RETURN: true)
bool addIncomeList(char* HistoryData) {
    struct json_object* root;           				// 전체 리스트 내역 딕셔너리
    struct json_object* typeList;       				// 수입 | 지출내역
    struct json_object* listInfo;       				// 내역 세부 데이터
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
    
    // 메모리 누수 방지
    json_object_put(root);
    updatelistId(listId);
    return true;
}

// 지출 내역 추가 (RETURN: true)
bool addSpendList(char* HistoryData) {
    struct json_object* root;           				// 전체 리스트 내역
    struct json_object* typeList;       				// 수입 | 지출내역
    struct json_object* listInfo;       				// 내역 세부 데이터
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
    
    // 메모리 누수 방지
    json_object_put(root);
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
bool setSpendPromise(char* HistoryData) {
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
    
    // 메모리 누수 방지
    json_object_put(root);
    updatelistId(listId);
    return true;
}

// 내역 날짜 검색
char* findDate(char* jsonData, char* actList, char* targetDate) {
    struct json_object* root = json_tokener_parse(jsonData);

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
                    strcat(result, "------------------------------\n"); // 줄바꿈 추가
                }
            }
        }

        json_object_put(root);
        return result;
    } else {
        json_object_put(root);
        return "지출목록을 찾을 수 없습니다.";
    }
}

// 내역 카테고리 검색
char* findTag(char* jsonData, char* actList, char* targetTag) {
    struct json_object* root = json_tokener_parse(jsonData);

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
                    strcat(result, "------------------------------\n"); // 줄바꿈 추가
                }
            }
        }
        json_object_put(root);
        return result;
    } else {
        json_object_put(root);
        return "지출목록을 찾을 수 없습니다.";
    }
}

// 수입 내역 출력
char* getIncomeList(void) {
    struct json_object* root;		// 전체 리스트 내역
    struct json_object* incomeList;	// 수입 내역
    struct json_object* entry;		// 내역 세부 데이터
    char* result = malloc(1000); 	// 적절한 크기로 메모리 동적 할당
    char entryText[500]; 			// 각 항목을 저장할 임시 문자열 배열

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

        strcat(result, "------------------------------\n");
    }
    // 메모리 누수 방지
    json_object_put(root);
    return result;
}

// 지출 내역 출력
char* getSpendList(void) {
    struct json_object* root;		// 전체 리스트 내역
    struct json_object* spendList;	// 지출 내역
    struct json_object* entry;		// 내역 세부 데이터
    char* result = malloc(1000); 	// 적절한 크기로 메모리 동적 할당
    char entryText[500]; 			// 각 항목을 저장할 임시 문자열 배열
    
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

        strcat(result, "------------------------------\n");
    }
    // 메모리 누수 방지
    json_object_put(root);
    return result;
}

// 지출 예약 내역 출력
char* getSpendPromiseList(void) {
    struct json_object* root;		// 전체 리스트 내역
    struct json_object* spendList;	// 지출 내역
    struct json_object* entry;		// 내역 세부 데이터
    char* result = malloc(1000); 	// 적절한 크기로 메모리 동적 할당
    char entryText[500]; 			// 각 항목을 저장할 임시 문자열 배열

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

        strcat(result, "------------------------------\n");
    }
    // 메모리 누수 방지
    json_object_put(root);
    return result;
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