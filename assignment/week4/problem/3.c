/*
* 프로그램 내용: 4주차 팀별과제 3번
* 개발자: 이정호(202311431)
* 문제: 파일로 부터 성적 점수를 읽은다음, 점수를 내림차순으로 정렬하여 순위(등수) 를 출력하고 
만약 같은 점수가 있게된다면 같은 등수로 표가합니다.
그리고 다음 점수의 순위는 같은 순위의 사람수를 고려해서 계산합니다
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100]; 
    int score;      // 성적 점수
    int rank;       // 등수
} Student;

int compare(const void* a, const void* b) {
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;

    if (studentA->score < studentB->score) {    // 점수를 기준으로 내림차순 정렬
        return 1;
    }
    else if (studentA->score > studentB->score) {
        return -1;
    }
    else {
        return 0;
    }
}

int main() {
    FILE* file;
    Student students[100];   // 최대 100명의 학생
    int numStudents = 0;

    file = fopen("scores.txt", "r");   // 파일 열기
    if (file == NULL) {
        printf("파일을 열 수 없습니다.");   // 파일을 열수 없을때 출력
        return 1;
    }

    while (fscanf(file, "%s %d", students[numStudents].name, &students[numStudents].score) != EOF) {   // 파일로부터 성적 읽기
        numStudents++;
    }

    fclose(file);   // 파일 닫기

    qsort(students, numStudents, sizeof(Student), compare); // 성적을 내림차순으로 정렬

    students[0].rank = 1;     // 학생들의 점수를 비교해서 등수 계산
    for (int i = 1; i < numStudents; i++) {
        if (students[i].score == students[i - 1].score) {
            students[i].rank = students[i - 1].rank;
        }
        else {
            students[i].rank = i + 1;
        }
    }

    printf("등수\t이름\t성적\n");    // 등수, 이름, 성적 순서대로 출력
    for (int i = 0; i < numStudents; i++) {
        printf("%d\t%s\t%d\n", students[i].rank, students[i].name, students[i].score);
    }
    return 0;
}


// cd /workspace/SeowonCProject/assignment/week4/problem/ && gcc ./3.c -o /tmp/a.out -lm && clear && /tmp/a.out