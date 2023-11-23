#ifndef UTIL_H
#define UTIL_H

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#define WHITE   "\x1b[0m"

// char* getDate(void) {
//     char Date[30];
//     time_t t = time(NULL);
//     struct tm tm_info = *localtime(&t);
//     // 현재 날짜를 yyyy-mm-dd 형식으로 문자열에 저장
//     sprintf(Date, "%04d-%02d-%02d", tm_info.tm_year + 1900, tm_info.tm_mon + 1, tm_info.tm_mday);
//     return Date;
// }


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
	printf("\rSuccess!\r");
}

// 요소가 배열 안에 요소에 해당하는 지 확인
bool isArray(char value, char array[], int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return true;
        }
    }
    return false;
}


#endif // UTIL_H