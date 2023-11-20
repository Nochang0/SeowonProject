/*
* 프로그램 내용: 3주차 팀별과제 3번
* 개발자: 이호현(202311437)
* 문제: 다음 조건을 만족하는 레스토랑의 좌석 예약 시스템을 프로그램으로 작성하세요(함수를 사용하여 프로그램 작성 권장)
   - 레스토랑의 테이블은 5개 있고(각 테이블의 좌석 수는 2, 4, 4, 6, 8개 이다.
   - 테이블 번호는 1, 2, 3, 4, 5로 표시된다.
   - 예약 현황은 예약된 테이블은 1로, 예약되지 않은 테이블은 0으로 표시된다.
   - 하나의 테이블을 선택하여 예약을 진행하며, 예약시 예약인원, 예약자 이름과 전화번호를 저장한다.
   - 이미 예약된 테이블과 테이블 당 좌석수를 초과하는 인원은 예약할 수 없다.
   - 프로그램은 다음 메뉴로 동작한다.
     1. 예약		2. 예약 조회	 3. 종료
   - 예약 조회는 조회할 테이블 번호를 입력 받고, 
      해당 테이블의 예약 여부와 예약이 되어 있는 경우에 예약자 이름과 전화번호, 예약 인원수를 출력한다.
*/

#include <stdio.h>
#include <string.h>

#define TABLE_COUNT 5
#define RESERVED 1
#define NOT_RESERVED 0

char names[TABLE_COUNT][50];
char phones[TABLE_COUNT][11];
int seats[TABLE_COUNT];
int tables[TABLE_COUNT] = { 0 };
int MAX_SEATS[5] = { 2, 4, 4, 6, 8 };

void reserveTable() {
    int tableNum;
    int maxSeats;
    int seatNum;

    printf("예약할 테이블 번호를 입력하세요 (1부터 %d까지): ", TABLE_COUNT);
    scanf("%d", &tableNum);

    if (tableNum < 1 || tableNum > TABLE_COUNT) {
        printf("잘못된 테이블 번호입니다.\n");
        return;
    }

    if (tables[tableNum - 1] == RESERVED) {
        printf("이미 예약된 테이블입니다.\n");
        return;
    }

    maxSeats = MAX_SEATS[tableNum - 1];
    printf("예약할 좌석 수를 입력하세요 (최대 %d): ", maxSeats);
    scanf("%d", &seatNum);

    if (seatNum > maxSeats || seatNum <= 0) {
        printf("잘못된 좌석 수입니다.\n");
        return;
    }

    printf("예약자 이름을 입력하세요: ");
    scanf("%s", names[tableNum - 1]);

    printf("전화번호를 입력하세요: ");
    scanf("%s", phones[tableNum - 1]);

    seats[tableNum - 1] = seatNum;
    tables[tableNum - 1] = RESERVED;

    printf("테이블 %d 예약이 완료되었습니다.\n", tableNum);
}

void viewReservation() {
    int tableNum;

    printf("조회할 테이블 번호를 입력하세요 (1부터 %d까지): ", TABLE_COUNT);
    scanf("%d", &tableNum);

    if (tableNum < 1 || tableNum > TABLE_COUNT) {
        printf("잘못된 테이블 번호입니다.\n");
        return;
    }

    if (tables[tableNum - 1] == NOT_RESERVED) {
        printf("해당 테이블은 예약되어 있지 않습니다.\n");
        return;
    }

    printf("테이블 %d 예약 정보:\n", tableNum);
    printf("예약자 이름: %s\n", names[tableNum - 1]);
    printf("전화번호: %s\n", phones[tableNum - 1]);
    printf("예약된 좌석 수: %d\n", seats[tableNum - 1]);
}

int main() {
    int choice;

    while (1) {
        printf("\n---------------------------\n");
        printf("\n레스토랑 좌석 예약 시스템\n");
        printf("1. 예약\n");
        printf("2. 예약 조회\n");
        printf("3. 종료\n");
        printf("\n---------------------------\n");
        printf("원하는 작업을 선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            reserveTable();
            break;
        case 2:
            viewReservation();
            break;
        case 3:
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 선택입니다. 다시 선택해주세요.\n");
            break;
        }
    }
    return 0;
}







// cd /workspace/SeowonCProject/assignment/week3/problem/ && gcc ./3.c -o /tmp/a.out -lm && clear && /tmp/a.out