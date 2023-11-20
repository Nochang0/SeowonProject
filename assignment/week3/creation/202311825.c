/*
* 프로그램 내용: 5개의 정수를 입력받고 역순으로 출력하는 프로그램을 작성하시오 (창작 문제)
* 개발자: 장서진 (202311825)
*/

#include<stdio.h> 

int main(void)
{
    
    int num[5]={0};         
    
    int count;              

    
    printf("5개의 정수를 입력하세요.\n");           
    
    for (count = 0; count < 5; count++)           
    {
        scanf("%d", &num[count]);
    } 

   
    for (count = 4; count >= 0; count--)           
    {
        
        printf("%d ", num[count]);                 
    } 
    return 0;
}



// cd /workspace/SeowonCProject/assignment/week3/creation/ && gcc ./202311825.c -o /tmp/a.out -lm && clear && /tmp/a.out