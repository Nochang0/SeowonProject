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
   - 예약 조회는 조회할 테이블 번호를 입력 받고, 해당 테이블의 예약 여부와 예약이 되어 있는 경우에 예약자 이름과 전화번호, 예약 인원수를 출력한다.
*/

#include <stdio.h>
#include <string.h>

#define TABLE_COUNT 5                                                           // 매크로 함수 : 테이블 개수 숫자
#define RESERVED 1                                                              // 매크로 함수 : 예약 유
#define NOT_RESERVED 0                                                          // 매크로 함수 : 예약 무

int tables[TABLE_COUNT] = { 0 };                                                // 초기화: 모든 테이블이 예약되지 않은 상태
int MAX_SEATS[5] = { 2, 4, 4, 6, 8 };                                           // 변수 초기화 : 테이블마다의 좌석 수

Reservation reservations[TABLE_COUNT];                                          // 각 테이블의 예약 정보 저장

void reserveTable() {                                                           // 메뉴 1번 : 예약
    int tableNum;                                                               // 예약할 테이블 번호 변수
    int maxSeats = MAX_SEATS[tableNum - 1];                                     // 테이블마다의 최대 좌석 수     
    int seats;                                                                  // 좌석 수 변수

    printf("예약할 테이블 번호를 입력하세요 (1부터 %d까지): ", TABLE_COUNT);
    scanf("%d", &tableNum);

    if (tableNum < 1 || tableNum > TABLE_COUNT) {                               // 없는 테이블 번호인 경우
        printf("잘못된 테이블 번호입니다.\n");
        return;
    }

    if (tables[tableNum - 1] == RESERVED) {                                     // 이미 예약된 테이블 번호인 경우
        printf("이미 예약된 테이블입니다.\n");
        return;
    }

    printf("예약할 좌석 수를 입력하세요 (최대 %d): ", maxSeats);
    scanf("%d", &seats);

    if (seats > maxSeats || seats <= 0) {                                       // 좌석 수가 많거나 없는 경우
        printf("잘못된 좌석 수입니다.\n");
        return;
    }

    printf("예약자 이름을 입력하세요: ");
    scanf("%s", reservations[tableNum - 1].name);

    printf("전화번호를 입력하세요: ");
    scanf("%s", reservations[tableNum - 1].phone);

    reservations[tableNum - 1].seats = seats;
    tables[tableNum - 1] = RESERVED;

    printf("테이블 %d 예약이 완료되었습니다.\n", tableNum);
}

void viewReservation() {                                                         // 메뉴 2번 : 예약 조회
    int tableNum;                                                                // 조회할 테이블 번호 변수

    printf("조회할 테이블 번호를 입력하세요 (1부터 %d까지): ", TABLE_COUNT);
    scanf("%d", &tableNum);

    if (tableNum < 1 || tableNum > TABLE_COUNT) {                                // 없는 테이블 번호를 입력한 경우
        printf("잘못된 테이블 번호입니다.\n");
        return;
    }

    if (tables[tableNum - 1] == NOT_RESERVED) {                                  // 예약되지 않은 테이블 번호를 입력한 경우
        printf("해당 테이블은 예약되어 있지 않습니다.\n");
        return;
    }

    printf("테이블 %d 예약 정보:\n", tableNum);
    printf("예약자 이름: %s\n", reservations[tableNum - 1].name);
    printf("전화번호: %s\n", reservations[tableNum - 1].phone);
    printf("예약된 좌석 수: %d\n", reservations[tableNum - 1].seats);
}

typedef struct {
    char name[50];                                                              // 예약자 이름
    char phone[11];                                                             // 예약자 전화번호
    int seats;                                                                  // 예약자 인원 수 
} Reservation;

int main() {
    int choice;                                                                 // 메뉴 선택 변수
    
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
            reserveTable();                                                     // 메뉴 1번 : 예약
            break;
        case 2:
            viewReservation();                                                  // 메뉴 2번 : 예약 조회
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