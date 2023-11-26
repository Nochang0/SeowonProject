#ifndef UTIL_H
#define UTIL_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#define WHITE   	"\x1b[0m"

void Clear(void); 
char* getDate(void);
void gotoxy(int x, int y);
void LoadSpin(int file_size, char* plusText);
bool isArray(char value, char array[]);
void disappearText(char* text);


char* getDate(void) {
    char* Date = malloc(1000);
    time_t t = time(NULL);
    struct tm tm_info = *localtime(&t);
    // 현재 날짜를 yyyy-mm-dd 형식으로 문자열에 저장
    sprintf(Date, "%04d-%02d-%02d", tm_info.tm_year + 1900, tm_info.tm_mon + 1, tm_info.tm_mday);
    return Date;
}


// x: 들여쓰기, y: 줄바꿈
void gotoxy(int x, int y) {
    printf("\033[%d;%df", y, x);
}

// 로딩 모션
void LoadSpin(int file_size, char* plusText) {
    printf(WHITE);
    int download_speed = 10;
    float total_time = (float)file_size / download_speed + 1;

    for (int i = 0; i < (int)total_time; i++) {
        int current_size = i * download_speed;
        float ratio = (float)current_size / file_size;
        float percent = ratio * 100;

        const char* cursor = "|/-\\";
        printf("\r%s[%.1f%%] Loading... %c", plusText, percent, cursor[i % 4]);
        fflush(stdout);
        usleep(100000);
    }
}

// 프롬프트 청소
void Clear(void) {
    gotoxy(1, 1);
    printf(WHITE "\033[2J\033[H");
}

// 요소가 배열 안에 요소에 해당하는 지 확인
bool isArray(char value, char array[]) {
    int size = sizeof(array) / sizeof(array[0]);
    
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return true;
        }
    }
    return false;
}

void disappearText(char* text) {
    int text_length = strlen(text); // 텍스트의 길이

    for (int i = 0; i < 2; i++) {
        int color_value = (i / 1) % 2; // 10번마다 색 변경
        int color_code = color_value ? 30 : 37; // 검은색 또는 흰색 선택

        printf("\033[%dm", color_code); // 색상 설정
        gotoxy(15, 4);
        for (int j = 0; j < text_length; j++) {
            
            printf("%c", text[j]); // 텍스트 출력
            fflush(stdout); // 출력 버퍼 비우기
            usleep(100000); // 0.1초 대기
        }
        printf("\033[0m"); // 색상 초기화
        printf("\r"); // 커서를 줄의 맨 앞으로 이동
        usleep(500000); // 0.5초 대기
    }
}

#endif // UTIL_H