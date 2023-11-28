#include <stdio.h>
#include <stdbool.h>
#include <json-c/json.h>

bool getAmountFromJson(const char* jsonData, int* amount) {
    struct json_object* root;
    struct json_object* amountObj;

    // JSON 데이터 파싱
    root = json_tokener_parse(jsonData);

    // "금액" 객체 가져오기
    if (json_object_object_get_ex(root, "금액", &amountObj)) {
        // "금액" 객체의 값 가져오기
        double plusMoney = json_object_get_double(amountObj);

        // "plusMoney" 값을 int로 변환하여 "amount"에 할당
        *amount = (int)plusMoney;

        // 메모리 누수 방지
        json_object_put(root);

        return true;
    }

    // 메모리 누수 방지
    json_object_put(root);

    return false;
}

int main() {
    const char* jsonData = "{\"날짜\":\"2023-12-04\",\"금액\":\"1000\",\"수입처\":\"은행\",\"메모\":\"없음\",\"카테고리\":\"저금\"}";
    int amount;

    if (getAmountFromJson(jsonData, &amount)) {
        printf("금액: %d\n", amount);
    } else {
        printf("금액을 가져올 수 없습니다.\n");
    }

    return 0;
}



// cd /workspace/SeowonCProject/project/ && gcc ./test3.c -o /tmp/a.out -lm -ljson-c && clear && /tmp/a.out