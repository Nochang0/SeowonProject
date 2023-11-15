// 기본 라이브러리
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <json-c/json.h>

// 커스텀 라이브러리
#include "./lib/fs.h"
#include "./lib/json.h"

// 매크로 변수
#define INCOME_FILE_PATH "./db/income.json"
#define SPEND_FILE_PATH "./db/spend.json"


int main(void) {
    // 파일에 문자열 데이터 저장
    // bool result = saveFile(FILE_PATH, data);
    // printf("saveStringToFile 함수 결과: %d\n", result);

    char *examText = "{\"날짜\": \"2023-11-09\",\"금액\": \"5000\",\"수입처\": \"용돈\",\"메모\": \"\",\"카테고리\": \"tag2\"}";
    char *uniqueId = "15";
    char *listData = loadFile(SPEND_FILE_PATH);
    
    // printf("\n%s\n", incomeData);
    // free(incomeData);

    // int getResult = setSpendLimit(incomeData, "300000");
    int getResult = getSpendLimit(listData);
    printf("%d\n", getResult);
    // free(getResult);
    

    return 0;
}

// cd /workspace/SeowonCProject/project/ && gcc ./main.c -o /tmp/a.out -lm -ljson-c && clear && /tmp/a.out