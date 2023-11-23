#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <json-c/json.h>

const char* createJsonString() {
    struct json_object *json, *item, *innerObject;
    
    // 최상위 JSON 객체 생성
    json = json_object_new_object();

    // 내부 객체 생성
    innerObject = json_object_new_object();

    // 내부 객체에 속성 추가
    json_object_object_add(innerObject, "날짜", json_object_new_string("2023-11-09"));
    json_object_object_add(innerObject, "금액", json_object_new_string("2000000"));
    json_object_object_add(innerObject, "수입처", json_object_new_string("월급"));
    json_object_object_add(innerObject, "메모", json_object_new_string(""));
    json_object_object_add(innerObject, "카테고리", json_object_new_string("tag1"));

    // 최상위 JSON 객체에 내부 객체 추가
    json_object_object_add(json, "1", innerObject);

    // JSON 문자열 반환
    return json_object_to_json_string_ext(json, JSON_C_TO_STRING_PRETTY);
}

int main() {
    const char* jsonString = createJsonString();
    printf("%s\n", jsonString);

    return 0;
}



// cd /workspace/SeowonCProject/project/ && gcc ./test4.c -o /tmp/a.out -lm -ljson-c -lncurses && clear && /tmp/a.out