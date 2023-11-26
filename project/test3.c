// 기본 라이브러리
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <json-c/json.h>

// 커스텀 라이브러리
#include "./lib/data_manager.h"
#include "./lib/fs.h"
#include "./lib/util.h"
#include "./lib/ui.h"

// #include "./lib/ui.h"
// #include "./lib/prompt.h"
// #include "./lib/util.h"

#define INCOME_FILE_PATH "./db/income.json"
#define SPEND_FILE_PATH "./db/spend.json"
#define SPEND_LIMIT_FILE_PATH "./db/spendLimit.txt"
#define SPEND_PROMISE_FILE_PATH "./db/spendPromise.json"
#define RECENT_LISTID_FILE_PATH "./db/uniqueNum.txt"

// int main(void) {
// 	Splash_Screen();
// 	int move = mainMenuScene();
//     printf("%d\n", move[0]);
//     // inputBar(move);
//     return 0;
// }



int main() {
	// printf("╔═══════════════════════════════════════════════════╗\n");
	// printf("●               📝 수입 내역 등록                  ●\n");
	// printf("╠═══════════════════════════════════════════════════╣\n");
	// printf("║  📅날짜:                                           ║\n");
	// printf("║  💰금액:                                             ║\n");
	// printf("║  🛍️수입처:                                          ║\n");
	// printf("║  🧾메모:                                             ║\n");
	// printf("║  📅카테고리:                                        ║\n");
	// printf("╚═══════════════════════════════════════════════════╝\n");
	// char* dd = getDate();
	// printf("%s\n", dd);
    char moveNum;
    bool moveTrue;
    char menuArr[] = { '1', '2', 'z', 'q' };		// 입력 값 배열   
    // inputBarScene(Fourheight);
    printf("ddd");
    printf("\n\n\ncccc");
    printf(LIGHT_GREEN);
    gotoxy(11, 2);

    scanf("%c", &moveNum);

    // moveTrue = isArray(moveNum, menuArr);
    if (isArray(moveNum, menuArr)) {
        printf("성공!!", moveNum);
    } else{
        printf("fuck");
    }
}


// cd /workspace/SeowonCProject/project/ && gcc ./test3.c -o /tmp/a.out -lm -ljson-c && clear && /tmp/a.out