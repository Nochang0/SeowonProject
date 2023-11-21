#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <time.h>
#include <unistd.h>


// char* getDate(void) {
//     char Date[30];
//     time_t t = time(NULL);
//     struct tm tm_info = *localtime(&t);
//     // 현재 날짜를 yyyy-mm-dd 형식으로 문자열에 저장
//     sprintf(Date, "%04d-%02d-%02d", tm_info.tm_year + 1900, tm_info.tm_mon + 1, tm_info.tm_mday);
//     return Date;
// }



void LoadSpin(int file_size) {
    int download_speed = 10;
    float total_time = (float)file_size / download_speed + 1;

    for (int i = 0; i < (int)total_time; i++) {
        int current_size = i * download_speed;
        float ratio = (float)current_size / file_size;
        float percent = ratio * 100;

        const char* cursor = "|/-\\";
        printf("\r[%.1f%%] Loading... %c", percent, cursor[i % 4]);
        fflush(stdout);
        usleep(100000);
    }
	printf("\rSuccess!\r");
}


#endif // UTIL_H