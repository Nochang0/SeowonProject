/*
* 프로그램 내용: 서점에서 도서를 판매하거나 반품처리를 할 경우에 
현재의 재고량을 파일로 관리하여 처리하는 프로그램 (창작 문제)
* 개발자: 김예은 (202010319)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

// 함수 선언
void displayMenu();
void readBookData(char titles[MAX_BOOKS][50], char authors[MAX_BOOKS][50], int publication_years[MAX_BOOKS], int prices[MAX_BOOKS], int stock_quantities[MAX_BOOKS], int* bookCount);
void displayBookList(char titles[MAX_BOOKS][50], char authors[MAX_BOOKS][50], int publication_years[MAX_BOOKS], int prices[MAX_BOOKS], int stock_quantities[MAX_BOOKS], int bookCount);
void updateStock(char titles[MAX_BOOKS][50], int stock_quantities[MAX_BOOKS], int bookCount);
void saveToFile(char titles[MAX_BOOKS][50], char authors[MAX_BOOKS][50], int publication_years[MAX_BOOKS], int prices[MAX_BOOKS], int stock_quantities[MAX_BOOKS], int bookCount);


int main() {
    // 도서 정보를 저장하는 배열 및 변수
    char titles[MAX_BOOKS][50];             // 제목
    char authors[MAX_BOOKS][50];            // 저자
    int publication_years[MAX_BOOKS];       // 출판연도
    int prices[MAX_BOOKS];                  // 가격
    int stock_quantities[MAX_BOOKS];        // 재고수량

    int bookCount = 0; // 책의 총 수
    char choice;       // 사용자의 선택

    // 파일에서 도서 데이터 읽어오기
    readBookData(titles, authors, publication_years, prices, stock_quantities, &bookCount);

    do {
        // 메뉴 표시 및 선택
        displayMenu();
        printf("메뉴 번호를 선택하세요.: ");
        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            // 책 목록 표시
            displayBookList(titles, authors, publication_years, prices, stock_quantities, bookCount);
            break;
        case '2':
            // 재고 업데이트
            updateStock(titles, stock_quantities, bookCount);
            break;
        case '3':
            // 파일에 저장
            saveToFile(titles, authors, publication_years, prices, stock_quantities, bookCount);
            break;
        case '4':
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("올바르지 않은 선택입니다. 다시 시도 하세요.\n");
        }
    } while (choice != '4');

    return 0;
}

// 메뉴 표시 함수
void displayMenu() {
    printf("\n===== 도서 재고 관리 =====\n");
    printf("1. 도서 목록 \n");
    printf("2. 재고수량 업데이트 \n");
    printf("3. 파일 저장 \n");
    printf("4. 종료 \n");
}

// 파일에서 책 데이터 읽어오는 함수
void readBookData(char titles[MAX_BOOKS][50], char authors[MAX_BOOKS][50], int publication_years[MAX_BOOKS], int prices[MAX_BOOKS], int stock_quantities[MAX_BOOKS], int* bookCount) {
    FILE* file = fopen("./file/bookdata.txt", "r");

    if (file == NULL) {
        printf("파일 열기 오류. 프로그램을 종료합니다. \n");
        exit(1);
    }
    while (fscanf(file, "%s %s %d %d %d",
        titles[*bookCount],
        authors[*bookCount],
        &publication_years[*bookCount],
        &prices[*bookCount],
        &stock_quantities[*bookCount]) == 5) { 
        (*bookCount)++;
    }

    fclose(file);
}

// 도서 목록을 표시하는 함수
void displayBookList(char titles[MAX_BOOKS][50], char authors[MAX_BOOKS][50], int publication_years[MAX_BOOKS], int prices[MAX_BOOKS], int stock_quantities[MAX_BOOKS], int bookCount) {
    printf("\n===== 도서 목록 =====\n");
    printf("%-30s %-20s %-15s %-10s %15s\n", "Title", "Author", "Publication Year", "Price", "Stock Quantity");

    for (int i = 0; i < bookCount; i++) {
        printf("%-30s %-20s %-15d %-10d %-15d\n", 
            titles[i],
            authors[i],
            publication_years[i],
            prices[i],
            stock_quantities[i]);
    }
}

// 재고를 업데이트하는 함수
void updateStock(char titles[MAX_BOOKS][50], int stock_quantities[MAX_BOOKS], int bookCount) {
    char searchTitle[100];       // 제목 검색
    int newStockQuantity;       // 새로운 재고 수량

    printf("\n 재고수량을 업데이트할 책의 제목을 입력하세요.: ");
    scanf(" %[^\n]", searchTitle);

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(titles[i], searchTitle) == 0) {
            printf("현재 재고 수량: %d\n", stock_quantities[i]);
            printf("새로운 재고수량을 입력하세요.: ");
            scanf("%d", &newStockQuantity);
            stock_quantities[i] = newStockQuantity;
            printf("재고수량이 성공적으로 업데이트 되었습니다.\n");
            return;
        }
}

    printf("책을 찾을 수 없습니다. 수량이 업데이트 되지 않았습니다.\n");
}

// 변경된 책 정보를 파일에 저장하는 함수
void saveToFile(char titles[MAX_BOOKS][50], char authors[MAX_BOOKS][50], int publication_years[MAX_BOOKS], int prices[MAX_BOOKS], int stock_quantities[MAX_BOOKS], int bookCount) {
    FILE* file = fopen("./file/bookdata.txt", "w");

    if (file == NULL) {
        printf("파일 열기에 실패했습니다. 프로그램을 종료합니다.\n");
        exit(1);
    }

    for (int i = 0; i < bookCount; i++) {
        fprintf(file, "%-30s %-20s %-15d %-10d %-15d\n",
            titles[i],
            authors[i],
            publication_years[i],
            prices[i],
            stock_quantities[i]);
    }

    fclose(file);
    printf("변경사항이 파일에 저장되었습니다.\n");
}

// cd /workspace/SeowonCProject/assignment/week4/creation/ && gcc ./202010319.c -o /tmp/a.out -lm && clear && /tmp/a.out