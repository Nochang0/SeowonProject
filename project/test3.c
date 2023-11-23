// 기본 라이브러리
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <json-c/json.h>

// 커스텀 라이브러리
#include "./lib/util.h"

// int main(void) {
// 	Splash_Screen();
// 	int move = mainMenuScene();
//     printf("%d\n", move[0]);
//     // inputBar(move);
//     return 0;
// }


int main() {
    printf("╔═══════════════════════════════════════════════════╗\n");
	printf("●               📝 수입 내역 등록                  ●\n");
    printf("╠═══════════════════════════════════════════════════╣\n");
    printf("║  📅날짜:                                           ║\n");
    printf("║  💰금액:                                             ║\n");
    printf("║  🛍️수입처:                                          ║\n");
    printf("║  🧾메모:                                             ║\n");
    printf("║  📅카테고리:                                        ║\n");
    printf("╚═══════════════════════════════════════════════════╝\n");
    char* dd = getDate();
    printf("%s\n", dd);
}


// cd /workspace/SeowonCProject/project/ && gcc ./test3.c -o /tmp/a.out -lm -ljson-c && clear && /tmp/a.out