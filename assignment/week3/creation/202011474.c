/*
* 프로그램 내용: 평균 구하기  (창작 문제)
* 개발자: 정희태 (202011474)
*/
#include<stdio.h>
int main(void) {
    int size;

    // 배열의 크기를 사용자로부터 입력 받기
    printf("배열의 크기를 입력하세요: ");
    scanf("%d", &size);


    int arr[size];

    // 배열에 숫자 입력 받기
    for (int i = 0; i < size; ++i) {
        printf("%d번째 숫자를 입력하세요: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // 입력 받은 숫자 출력
    printf("입력한 숫자: ",arr[size]);
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
	int sum=0;
	int number = sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<number;i++)
	{
        sum += arr[i];
    }

    int avg = sum / number;
	printf("전체의 평균은? : %d\n",avg);
    return 0;
}





// cd /workspace/SeowonCProject/assignment/week3/creation/ && gcc ./202011474.c -o /tmp/a.out -lm && clear && /tmp/a.out