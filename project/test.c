// 기본 라이브러리
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <json-c/json.h>

// 커스텀 라이브러리
#include "./lib/fs.h"
#include "./lib/ui.h"

int main(void) {
    // char *result = loadFile("./db/text.txt");
	// printf("%s\n", result);
	Splash_Screen();
	mainMenuScene();
    return 0;
}


// cd /workspace/SeowonCProject/project/ && gcc ./test.c -o /tmp/a.out -lm -ljson-c && clear && /tmp/a.out