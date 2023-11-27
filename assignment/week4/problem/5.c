/*
* 프로그램 내용: 4주차 팀별과제 5번
* 개발자: 김예은
* 문제: CD 판매점에서 CD를 판매하거나 반품처리를 할 경우에 현재의 재고량을 파일로 관리하여 처리하는 프로그램
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CDS 100

// 함수 선언
void displayMenu();
void readCDData(char titles[MAX_CDS][50], char artists[MAX_CDS][50], int release_years[MAX_CDS], int prices[MAX_CDS], int stock_quantities[MAX_CDS], int* cdCount);
void displayCDList(char titles[MAX_CDS][50], char artists[MAX_CDS][50], int release_years[MAX_CDS], int prices[MAX_CDS], int stock_quantities[MAX_CDS], int cdCount);
void updateStock(char titles[MAX_CDS][50], int stock_quantities[MAX_CDS], int cdCount);
void saveToFile(char titles[MAX_CDS][50], char artists[MAX_CDS][50], int release_years[MAX_CDS], int prices[MAX_CDS], int stock_quantities[MAX_CDS], int cdCount);

int main() {
    // CD 정보를 저장하는 배열 및 변수
    char titles[MAX_CDS][50];       // 제목
    char artists[MAX_CDS][50];      // 가수 또는 제목
    int release_years[MAX_CDS];     // 발매연도
    int prices[MAX_CDS];          // 가격
    int stock_quantities[MAX_CDS];  // 재고수량

    int cdCount = 0; // CD의 총 수
    char choice;     // 사용자의 선택

    // 파일에서 CD 데이터 읽어오기
    readCDData(titles, artists, release_years, prices, stock_quantities, &cdCount);

    do {
        // 메뉴 표시 및 선택
        displayMenu();
        printf("메뉴 번호를 선택하세요: ");
        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            // CD 목록 표시
            displayCDList(titles, artists, release_years, prices, stock_quantities, cdCount);
            break;
        case '2':
            // 재고 업데이트
            updateStock(titles, stock_quantities, cdCount);
            break;
        case '3':
            // 파일에 저장
            saveToFile(titles, artists, release_years, prices, stock_quantities, cdCount);
            break;
        case '4':
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("올바르지 않은 선택입니다. 다시 시도 하세요. \n");
        }
    } while (choice != '4');

    return 0;
}

// 메뉴 표시 함수
void displayMenu() {
    printf("\n===== CD 재고 관리 =====\n");
    printf("1. CD 목록 \n");
    printf("2. 재고수량 업데이트 \n");
    printf("3. 파일 저장 \n");
    printf("4. 종료 \n");
}

// 파일에서 CD 데이터 읽어오는 함수
void readCDData(char titles[MAX_CDS][50], char artists[MAX_CDS][50], int release_years[MAX_CDS], int prices[MAX_CDS], int stock_quantities[MAX_CDS], int* cdCount) {
    FILE* file = fopen("./file/cddata.txt", "r");

    if (file == NULL) {
        printf("파일 열기 오류. 프로그램을 종료합니다.\n");
        exit(1);
    }
    
    while (fscanf(file, "%s %s %d %d %d",
        titles[*cdCount],
        artists[*cdCount],
        &release_years[*cdCount],
        &prices[*cdCount],
        &stock_quantities[*cdCount]) != EOF) {
        (*cdCount)++;
    }

    fclose(file);
}

// CD 목록을 표시하는 함수
void displayCDList(char titles[MAX_CDS][50], char artists[MAX_CDS][50], int release_years[MAX_CDS], int prices[MAX_CDS], int stock_quantities[MAX_CDS], int cdCount) {
    printf("\n===== CD 목록 =====\n");
    printf("%-30s %-20s %-10s %-10s %-15s\n", "Title", "Artist", "Year", "Price", "Stock Quantity");

    for (int i = 0; i < cdCount; i++) {
        printf("%-30s %-20s %-10d %-10d %-15d\n",
            titles[i],
            artists[i],
            release_years[i],
            prices[i],
            stock_quantities[i]);
    }
}

// 재고를 업데이트하는 함수
void updateStock(char titles[MAX_CDS][50], int stock_quantities[MAX_CDS], int cdCount) {
    char searchTitle[50];
    int newStockQuantity;

    printf("\n 재고수량을 업데이트할 CD의 이름을 입력하세요: ");
    scanf(" %[^\n]", searchTitle);

    for (int i = 0; i < cdCount; i++) {
        if (strcmp(titles[i], searchTitle) == 0) {
            printf("현재 재고 수량: %d\n", stock_quantities[i]);
            printf("새로운 재고수량을 입력하세요 : ");
            scanf("%d", &newStockQuantity);
            stock_quantities[i] = newStockQuantity;
            printf("재고수량이 성공적으로 업데이트 되었습니다.\n");
            return;
        }
    }

    printf("CD를 찾을 수 없습니다. 수량이 업데이트 되지 않았습니다.\n");
}

// 변경된 CD 정보를 파일에 저장하는 함수
void saveToFile(char titles[MAX_CDS][50], char artists[MAX_CDS][50], int release_years[MAX_CDS], int prices[MAX_CDS], int stock_quantities[MAX_CDS], int cdCount) {
    FILE* file = fopen("./file/cddata.txt", "w");

    if (file == NULL) {
        printf("파일 열기에 실패했습니다. 프로그램을 종료합니다.\n");
        exit(1);
    }

    for (int i = 0; i < cdCount; i++) {
        fprintf(file, "%s %s %d %d %d\n",
            titles[i],
            artists[i],
            release_years[i],
            prices[i],
            stock_quantities[i]);
    }

    fclose(file);
    printf("변경사항이 파일에 저장되었습니다.\n");
}


// cd /workspace/SeowonCProject/assignment/week4/problem/ && gcc ./5.c -o /tmp/a.out -lm && clear && /tmp/a.out