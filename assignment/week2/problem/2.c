/*
* 프로그램 내용: 2주차 팀별과제 2번
* 개발자: 김지성 (202110343)
* 문제: 계차수열은 인접하는 항의 차로 이루어진 수열을 말한다. 점화식을 이용하여 표현한 다음의 계차수열에 대해 항까지 출력하는 함수와 프로그램을 작성한다.
*/

#include <stdio.h>

int count(int n)//함수를 의미 int라는 반환형을 가지고 int n 이라는 정수형 인수를 받고서 count 라는 변수명 함수를 만듬 
{
    int term = 1;
    
    printf("점화식\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", term);
        term += i + 1// 1 2 3 4 5 이런식으로 흘러감;
    }
    printf("\n");
}

int main(void) {
    int n;

    printf("출력할 항의 개수를 입력 후 Enter>");
    scanf("%d", &n);

    count(n);// 매개변수에 n을 대입해 n+1 n+2 이런 식으로 흘러감
	return 0;
	}
	/*
	int count(int n)
	
	int main(void){
	int n;

    printf("출력할 항의 개수를 입력 후 Enter>");
    scanf("%d", &n);

    count(n);
	
	return 0;
	}
	int count(int n)//함수를 의미 int라는 반환형을 가지고 int n 이라는 정수형 인수를 받고서 count 라는 변수명 함수를 만듬 
{
    int term = 1;
    
    printf("점화식\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", term);
        term += i + 1// 1 2 3 4 5 이런식으로 흘러감;
    }
    printf("\n");
	이런 식으로도 가능
}
	*/
    
		
    return 0;
}





// cd /workspace/SeowonCProject/assignment/week2/problem/ && gcc ./2.c -o /tmp/a.out -lm && clear && /tmp/a.out