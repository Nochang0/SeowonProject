/*
* 프로그램 내용: 4주차 팀별과제 4번
* 개발자: 
* 문제: 
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define TOTAL_CARDS (NUM_SUITS * NUM_RANKS)
#define HAND_SIZE 10

// 트럼프 카드 구조체 정의
struct PlayingCard {
    char pattern;   // 'S' (Spades), 'D' (Diamonds), 'H' (Hearts), 'C' (Clubs)
    char value;   // '2' to '9', 'T' (10), 'J' (Jack), 'Q' (Queen), 'K' (King), 'A' (Ace)
};

// 함수 선언
void initializeDeck(struct PlayingCard deck[]);
void shuffleDeck(struct PlayingCard deck[]);
void displayDeck(struct PlayingCard deck[]);
void displayHand(struct PlayingCard hand[], int numCards);

int main() {
    // 초기화 및 난수 시드 설정
    srand(time(NULL));

    // 트럼프 카드 배열
    struct PlayingCard deck[TOTAL_CARDS];

    // 카드 초기화
    initializeDeck(deck);

    // 카드 출력
    printf("섞지않은 상태의 카드\n");
    displayDeck(deck);

    // 카드 섞기
    shuffleDeck(deck);

    // 선택된 카드 배열
    struct PlayingCard hand[HAND_SIZE];

    // 10장의 카드 선택
    for (int i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }

    // 선택된 카드 출력
    printf("\n섞은 후 뽑은 랜덤 카드 10장\n");
    displayHand(hand, HAND_SIZE);

    return 0;
}

// 트럼프 카드 초기화 함수
void initializeDeck(struct PlayingCard deck[]) {
    char patterns[NUM_SUITS] = { 'S', 'D', 'H', 'C' };
    char values[NUM_RANKS] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };

    int cardIndex = 0;
    for (int patternIndex = 0; patternIndex < NUM_SUITS; patternIndex++) {
        for (int valueIndex = 0; valueIndex < NUM_RANKS; valueIndex++) {
            deck[cardIndex].pattern = patterns[patternIndex];
            deck[cardIndex].value = values[valueIndex];
            cardIndex++;
        }
    }
}

// 트럼프 카드 섞기 함수
void shuffleDeck(struct PlayingCard deck[]) {
    for (int i = TOTAL_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        // Swap
        struct PlayingCard temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// 전체 카드 출력 함수
void displayDeck(struct PlayingCard deck[]) {
    for (int i = 0; i < TOTAL_CARDS; i++) {
        printf("%c%c ", deck[i].value, deck[i].pattern);
        if ((i + 1) % NUM_RANKS == 0) {
            printf("\n");
        }
    }
}

// 선택된 카드 출력 함수
void displayHand(struct PlayingCard hand[], int numCards) {
    for (int i = 0; i < numCards; i++) {
        printf("%c%c ", hand[i].value, hand[i].pattern);
    }
    printf("\n");
}




// cd /workspace/SeowonCProject/assignment/week4/problem/ && gcc ./4.c -o /tmp/a.out -lm && clear && /tmp/a.out