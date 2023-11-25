#include <stdio.h>
#include <json-c/json.h>


int main(void) {
    // JSON 객체 생성
    json_object *root = json_object_new_object();

    // JSON 요소 추가
    json_object *name = json_object_new_string("John Doe");
    json_object_object_add(root, "name", name);

    json_object *age = json_object_new_int(30);
    json_object_object_add(root, "age", age);

    json_object *address = json_object_new_object();
    json_object *street = json_object_new_string("123 ABC Street");
    json_object *city = json_object_new_string("New York");
    json_object_object_add(address, "street", street);
    json_object_object_add(address, "city", city);
    json_object_object_add(root, "address", address);

    // JSON 형식 데이터 출력
    const char* jsonString = json_object_to_json_string_ext(root, JSON_C_TO_STRING_PRETTY);
    printf("%s\n", jsonString);

    // JSON 요소 제거
    json_object_object_del(root, "age");

    // 수정된 JSON 형식 데이터 출력
    jsonString = json_object_to_json_string_ext(root, JSON_C_TO_STRING_PRETTY);
    printf("%s\n", jsonString);

    // JSON 객체 메모리 해제
    json_object_put(root);

    return 0;
}


// -ljson-c
// gcc /workspace/SeowonCProject/test.c -o /tmp/a.out -ljson-c && /tmp/a.out

/*
{
  "name":"John Doe",
  "age":30,
  "address":{
    "street":"123 ABC Street",
    "city":"New York"
  }
}
{
  "name":"John Doe",
  "address":{
    "street":"123 ABC Street",
    "city":"New York"
  }
}
*/