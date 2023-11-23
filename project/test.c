// 기본 라이브러리
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <json-c/json.h>

// 커스텀 라이브러리
#include "./lib/fs.h"
#include "./lib/ui.h"
#include "./lib/prompt.h"


// int main(void) {
// 	Splash_Screen();
// 	int move = mainMenuScene();
//     printf("%d\n", move[0]);
//     // inputBar(move);
//     return 0;
// }


int main() {
	//Splash_Screen();
    // inputBarByMainMenu();
    incomeMenu();
    return 0;
}



// cd /workspace/SeowonCProject/project/ && gcc ./test.c -o /tmp/a.out -lm -ljson-c && clear && /tmp/a.out