#ifndef FS_H
#define FS_H

// 기본 라이브러리
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// 함수 목록
bool saveFile(const char* filename, const char* data);	// 지정한 경로에 받은 데이터를 파일에 저장합니다.
char* loadFile(const char* filename);					// 지정한 경로에 파일 데이터를 출력합니다.
    

// 가계부 데이터 저장 함수
bool saveFile(const char* filename, const char* data) {
    // 파일 열기
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return false;
    }

    // 데이터 저장
    size_t length = strlen(data);
    size_t written = fwrite(data, sizeof(char), length, file);
    fclose(file);

    // 저장 완료 여부 확인
    if (written < length) {
        printf("데이터를 파일에 저장하는 중 오류가 발생했습니다.\n");
        return false;
    }
    // printf("파일에 데이터를 저장했습니다.\n");
    return true;
}


// 가계부 파일 문자열 리턴 함수
char* loadFile(const char* filename) {
    // 파일 열기
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return NULL;
    }

    // 파일 크기 계산
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // 파일 크기에 맞는 버퍼 동적 할당
    char* buffer = (char* )malloc(fileSize + 1);
    if (buffer != NULL) {
        // 파일 내용 읽기
        fread(buffer, fileSize, 1, file);
        buffer[fileSize] = '\0';
        // printf("파일에서 데이터를 읽어왔습니다.\n");
    } else {
        printf("버퍼를 할당할 수 없습니다.\n");
    }

    fclose(file);
    return buffer;
}

#endif // FS_H