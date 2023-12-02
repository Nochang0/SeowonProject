/*
* 프로그램 내용: 3주차 팀별과제 6번
* 개발자: 정희태(202011474)
* 문제: 30명에 대해 발 크기(cm)를 조사하여 평균과 표준편차를 계산하고, 구간의 개수를 10으로 하여 빈도수와 수평 막대그래프를 출력한다.
*/

#include <stdio.h>
#include <math.h>

#define NUM_DATA_POINTS 30
#define NUM_BINS 10

void print_star_histogram(int histogram[]) // 별 찍기 함수의 매개변수는 배열을 인수로 받는다
{
    printf("별 그래프:\n");
    for (int i = 0; i < NUM_BINS; ++i) {
        printf("%3d-%3d: ", i * 10 + 180, (i + 1) * 10 + 179);
        for (int j = 0; j < histogram[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

int main(void) {
    int foot_data[NUM_DATA_POINTS] = {270, 260, 250, 230, 210, 225, 260, 285, 245, 250, 260, 290, 295, 275, 260, 255, 245, 230, 220, 225, 210, 200, 180, 185, 190, 195, 205, 215, 235, 245};
    int number = sizeof(foot_data) / sizeof(foot_data[0]); // 배열의 마지막 인덱스를 값 구하기
    int sum = 0; // 평균

    for (int i = 0; i < number; i++) {
        sum += foot_data[i]; // 모든 발 크기를 다 더한다 
    }

    float avg = (float)sum / number; //모든 발 크기의 평균 구하기

    float sum2 = 0; // 표준편차
    for (int i = 0; i < number; ++i) {
        float diff = foot_data[i] - avg; //인덱스 0~29까지 모두 평균에서 뺀다
        sum2 += diff * diff; //그것을 sum2에 제곱을한 값을 저장
    }
    float std = sqrt(sum2 / number); // sum2와 number을 나누고 그것의 제곱근을 붙인다

    // 최대 최소
    int min_value = foot_data[0]; // 일단 0번째 인덱스를 min과 max로 둔다
    int max_value = foot_data[0];

    for (int i = 1; i < number; ++i) {
        if (foot_data[i] < min_value) {
            min_value = foot_data[i];
        } //만약 0번째 인덱스가 min_value보다 작으면 min_value에 저장, 0번째 인덱스가 min보다 크면 min_value을 min_value에 저장
        if (foot_data[i] > max_value) {
            max_value = foot_data[i];
			//위와 반대
        }
    }

    int range = max_value - min_value; // 제일 큰 발 사이즈와 제일 작은
    float bin_width = (float)range / NUM_BINS;

    int histogram[NUM_BINS] = {0};
    for (int i = 0; i < number; ++i) {
        int bin_index = (int)((foot_data[i] - min_value) / bin_width);
        histogram[bin_index]++;
    }

    printf("통계결과\n");
    printf("평균: %.2f cm\n표준편차: %.2f\n", avg, std);
    printf("수평 막대 그래프\n");
    printf("최소 발 크기: %d cm 최대 발 크기: %d\n범위: %d\n", min_value, max_value, range);
    print_star_histogram(histogram);

    return 0;
}


	



// cd /workspace/SeowonCProject/assignment/week3/problem/ && gcc ./6.c -o /tmp/a.out -lm && clear && /tmp/a.out