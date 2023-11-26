/*
* 프로그램 내용: struct을 이용해 문자열 5개를 저장하고, 사전순으로 정렬하는 함수를 따로 만들어 정렬한다. (창작 문제)
* 개발자: 이호현 (202311437)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 32

typedef struct dictionary
{
	char str[5][SIZE];											//문자열 5개 저장할 변수
}dictionary;

dictionary dictionary_str;										//전역 변수 선언

void dictionary_order();										//사전 정렬 함수 선언
int main(void)
{
	for (int i = 0; i < 5; i++) {								//문자열 5개 입력
		printf("사전순으로 정렬할 문자열을 입력하시오 : ");
		scanf("%s", dictionary_str.str[i]);
	}

	dictionary_order();				
	
	for (int i = 0; i < 5; i++) {								//정렬한 문자열 5개 출력
		printf("%s ", dictionary_str.str[i]);
	}

	return 0;
}

void dictionary_order() {										//문자열 5개 정렬할 함수
	char temp[SIZE];											//비교하기 위한 변수

	for (int i = 0; i < 4; i++) {								//변수의 i번째와 i+1번째 변수의 문자열을 비교 * 5번
		for (int j = i + 1; j < 5; j++) {
			if (strcmp(dictionary_str.str[i], dictionary_str.str[j]) > 0) {
				strcpy(temp, dictionary_str.str[i]);
				strcpy(dictionary_str.str[i], dictionary_str.str[j]);
				strcpy(dictionary_str.str[j], temp);
			}
		}
	}
}

// cd /workspace/SeowonCProject/assignment/week4/creation/ && gcc ./202311437.c -o /tmp/a.out -lm && clear && /tmp/a.out
//예제 9-3번을 변형한 실습 코드(문자열 2개를 입력받아 사전순으로 정렬)를 다시 변형해보았습니다.
//두 개는 반복문을 쓸 필요도 없었는데 5개가 되니 이중 반복문을 써야해서 헷갈렸지만 그래도 해냈습니다!