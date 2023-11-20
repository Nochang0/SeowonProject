/*
* 프로그램 내용: 3주차 팀별과제 1번
* 개발자: 이정호 (202311431)
* 문제: (숫자 맞추기 게임) 컴퓨터가 1부터 99 사이의 임의의 숫자(k)를 생성합니다. 사용자가 그 난수를 맞추기 위해 숫자를 입력(m)하면 컴퓨터가 다음 조건에 맞는 내용을 힌트로 출력합니다. 사용자는 힌트로 출력된 내용을 참고로 하여 범위를 좁혀가며 숫자를 맞추는 게임입니다. 각 게임별로 사용자가 최대 시도할 수 있는 횟수는 10회입니다. 10회를 초과하면 해당 게임은 실패로 끝나게 됩니다. 한 게임이 끝나는 경우에 게임을 한 총시간(몇분 몇초)을 출력합니다. 또한 사용자가 숫자 입력시에 0을 입력하면 프로그램은 종료됩니다. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int targetNumber, guessNumber;
    int attempts = 0;
    int gameCount = 0;
    int totalMinutes = 0, totalSeconds = 0;
    time_t startTime, endTime;

    // 시드값을 현재 시간으로 설정하여 난수 생성기 초기화
    srand(time(NULL));

    printf("숫자 맞추기 게임을 시작합니다!");

        while (1) {
            attempts = 0;

            // 1부터 99 사이의 임의의 숫자 생성
            targetNumber = (rand() % 99) + 1;

            printf("게임 %d을 시작합니다!", gameCount + 1);
                startTime = time(NULL);

            do {
                printf("숫자를 입력하세요 (0 입력 시 종료): ");
                scanf("%d", &guessNumber);

                if (guessNumber == 0) {
                    printf("프로그램을 종료합니다.");
                        endTime = time(NULL);
                    totalSeconds += difftime(endTime, startTime);
                    printf("게임을 플레이한 총 시간: %d분 %d초", totalMinutes, totalSeconds);
                        return 0;
                }

                attempts++;

                if (guessNumber > targetNumber) {
                    printf("낮음! ");
                }
                else if (guessNumber < targetNumber) {
                    printf("높음!");
                }
                else {
                    printf("축하합니다! 정답을 맞추셨습니다.");
                        break;
                }

                int difference = abs(guessNumber - targetNumber);

                if (difference < 25) {
                    printf("조금 ");
                }
                else if (difference == 25) {
                    printf("아주 ");
                }

                printf("가깝습니다!");

            } while (attempts < 10);

                if (attempts >= 10) {
                    printf("게임 실패! 시도 횟수를 초과하였습니다.");
                }

                endTime = time(NULL);
                totalSeconds += difftime(endTime, startTime);
                totalMinutes = totalSeconds / 60;
                totalSeconds %= 60;

                printf("게임을 완료한 총 시간: %d분 %d초", totalMinutes, totalSeconds);

                    gameCount++;
        }
    return 0;
}




// cd /workspace/SeowonCProject/assignment/week3/problem/ && gcc ./1.c -o /tmp/a.out -lm && clear && /tmp/a.out