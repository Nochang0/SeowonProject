/*
* 프로그램 내용: 4주차 팀별과제 6번
* 개발자: 이호현 (202311437)
* 문제: 주민등록번호 13자리를 '-' 없이 입력받아 생년월일과 성별, 띠를 계산하고, 컴퓨터에 설정된 현재 연월일을 기준으로 만 나이를 계산하여 출력하는 프로그램을 각각 함수로 작성한다.
*/

#include <stdio.h>
#include <time.h>

void getDate(char Social_num[14], int* Now_year, int* Now_month, int* Now_day);	// 현재 날짜 출력 및 저장
void birthday(char Social_num[14], int* year, int* month, int* day);			// 생년월일 출력 및 저장
void zodiac(int birth);															// 별자리 출력


int main(void) {
    int Now_year, Now_month, Now_day;	// 현재 년월일
    char Social_num[14];				// 주민등록번호
    int Birth_year, Birth_month, Birth_day;	// 생년월일

    
    // 주민등록번호 받기
    printf("생년월일과 성별, 띠, 만 나이 계산\n주민 등록번호 13자리 빈칸없이 입력하고 Enter\n주민번호> ");
	scanf("%s", Social_num);
    
	// 주민등록번호 출력
    printf("\033[2J\033[H");	// 터미널 텍스트 청소
    printf("생년월일과 성별, 띠, 만 나이 계산\n주민 등록번호 13자리 빈칸없이 입력하고 Enter\n주민번호> %.*s-*******\n", 6, Social_num);
    
	// 현재 날짜 출력 및 선언
    getDate(Social_num, &Now_year, &Now_month, &Now_day);
	
	// 생년월일 출력 및 선언
	birthday(Social_num, &Birth_year, &Birth_month, &Birth_day);
	
	// 성별 출력 및 선언
	// 뒷번호 시작이 1 또는 3이면 남자 아니면 여자
    char* gender = (Social_num[6] == '1' || Social_num[6] == '3') ? "남자" : "여자";
	printf("성별: %s\n", gender);
	
	// 별자리 출력 (공식: 생일년도 % 12 = 나머지로 따짐)
	zodiac(Birth_year);
    
	// 만나이 출력
	// 현재 년도 - 생일 년도
	int age = Now_year - Birth_year;
	// 이미 생일이 지났다면 나이에 -1
	if (Now_month < Birth_month || (Now_month == Birth_month && Now_day < Birth_day)) {
        age = age -1;
    }
	
	printf("만나이: %d\n", age);
    return 0;
}

// 생년월일 출력
void birthday(char Social_num[14], int* Birth_year, int* Birth_month, int* Birth_day) {
	// 생일년도 (2자리씩 읽어 각각 대입, 이미 포인터는 주소를 가지고 있어서 주소연산자가 필요없음)
    sscanf(Social_num, "%2d%2d%2d", Birth_year, Birth_month, Birth_day);
	// 생일년도 4자리 만들기 (주민번호 뒷자리로 판별)
    *Birth_year = (Social_num[6] <= '2') ? (1900 + *Birth_year) : (2000 + *Birth_year); // 1,2: 19년대 또는 3,4: 20년대
	
	printf("생년 월일: %d년 %d월 %d일\n", *Birth_year, *Birth_month, *Birth_day);
}

// 별자리 출력
void zodiac(int Birth_year) {
	// 생일년도를 12로 나눠 나머지로 따짐
    int zodiac = Birth_year % 12;
	
    switch (zodiac) {
        case 0: printf("띠 계산: 원숭이\n"); break;
        case 1: printf("띠 계산: 닭\n"); break;
        case 2: printf("띠 계산: 개\n"); break;
        case 3: printf("띠 계산: 돼지\n"); break;
        case 4: printf("띠 계산: 쥐\n"); break;
        case 5: printf("띠 계산: 소\n"); break;
        case 6: printf("띠 계산: 호랑이\n"); break;
        case 7: printf("띠 계산: 토끼\n"); break;
        case 8: printf("띠 계산: 용\n"); break;
        case 9: printf("띠 계산: 뱀\n"); break;
        case 10: printf("띠 계산: 말\n"); break;
        case 11: printf("띠 계산: 양\n"); break;
    }
}

// 현재 날짜 출력
void getDate(char Social_num[14], int* Now_year, int* Now_month, int* Now_day) {
	// time.h: struct tm, time(), localtime()
	// time_t: 시간을 나타내는 데이터 타입
	
    time_t t = time(NULL);	// 현재 시간 정보를 받음
	// `localtime(&t)` 코드도 또한 struct tm 구조체를 기반으로 현재 시간대를 리턴함.
	// `struct tm timeInfo`는 이러한 리턴값을 struct tm 구조체를 기반으로 데이터를 받아줌
    struct tm timeInfo = *localtime(&t);	// 우리나라 로컬 시간대로 변환후 tm 구조체로 저장
	
	// 현재 년월일 선언
    *Now_year = timeInfo.tm_year + 1900;
	*Now_month = timeInfo.tm_mon + 1;
	*Now_day = timeInfo.tm_mday;
	
    printf("\n현재 연월일: %04d년 %02d월 %02d일\n", *Now_year, *Now_month, *Now_day);
}


// cd /workspace/SeowonCProject/assignment/week4/problem/ && gcc ./6.c -o /tmp/a.out -lm && clear && /tmp/a.out