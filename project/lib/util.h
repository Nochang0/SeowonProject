#ifndef UTIL_H
#define UTIL_H

// 기본 라이브러리
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

// 커스텀 유틸리티 함수
void Clear(void);                               // 터미널의 텍스트 전부 삭제
void gotoxy(int x, int y);                      // 터미널의 좌표위치에서 입력 시작
void LoadSpin(int totalSpeed, char* plusText);  // 움직이는 로딩 효과
bool isArray(char value, char array[]);         // 원소가 배열에 속하는 지 확인
void disappearText(char* text);                 // 터미널에서 텍스트의 사라짐 효과 (종료 함수 전용)


// 터미널 텍스트 청소
void Clear(void) {
    gotoxy(1, 1);
    printf(WHITE "\033[2J\033[H");
}

// x: 가로, y: 세로
void gotoxy(int x, int y) {
    printf("\033[%d;%df", y, x);
}

// 로딩 이펙트
void LoadSpin(int totalSpeed, char* plusText) {
    printf(WHITE);
    int download_speed = 10;
    float total_time = (float)totalSpeed / download_speed + 1;

    for (int i = 0; i < (int)total_time; i++) {
        int current_size = i * download_speed;
        float ratio = (float)current_size / totalSpeed;
        float percent = ratio * 100;

        const char* cursor = "|/-\\";
        printf("\r%s[%.1f%%] Loading... %c", plusText, percent, cursor[i % 4]);
        fflush(stdout);
        usleep(100000);
    }
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

// 텍스트 사라짐 효과
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