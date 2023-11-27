
/*
* 프로그램 내용: 4주차 팀별과제 1번
* 개발자: 정희태 (202011474)
* 문제: 삼각형, 사각형, 원을 동시에 표현할 수 있는 구조체(공용체 멤버 포함)를 설계하라. 공용체는 삼각형은 밑변과 높이, 사각형은 가로와 세로, 원은 반지름만을 저장하도록 하라. 현재의 공용체가 표현하고 있는 도형의 종 류는 열거형 변수를 사용하여 나타내고 이들 정보를 종합하는 구조체를 선언하여 사용한다. 사용자로부터 도형의 종류와 도형의 데이터를 받아서 구조체(공용체 멤버 포함)변수에 저장한 다음 도형의 면적을 계산하는 프로그램을 작성하라.
*/

#include <stdio.h>
#include <math.h>

// 열거형을 사용하여 도형의 종류를 정의
enum Shapetype {
    TRIANGLE,
    RECTANGLE,
    CIRCLE
};

// 공용체를 사용하여 도형의 데이터를 저장
union Shapedata {
    struct {
        double base;
        double height;
    } triangle;

    struct {
        double width;
        double height;
    } rectangle;

    struct {
        double radius; // 반지름
    } circle;
};

// 구조체를 사용하여 도형을 표현
struct Shape {
    enum Shapetype type;
    union Shapedata data;
};

// 도형의 면적을 계산하는 함수
double calculate(struct Shape *shape) {
    switch (shape->type) {
        case TRIANGLE:
            return 0.5 * shape->data.triangle.base * shape->data.triangle.height;

        case RECTANGLE:
            return shape->data.rectangle.width * shape->data.rectangle.height;

        case CIRCLE:
            return M_PI * pow(shape->data.circle.radius, 2);

        default:
            return 0.0; // 알 수 없는 도형 종류일 경우 0을 반환
    }
}

int main() {
    // 사용자로부터 도형의 종류 입력 받기
    printf("도형의 종류를 선택하세요 (0: 삼각형, 1: 사각형, 2: 원): ");
    int shapetype;
    scanf("%d", &shapetype);

    // 도형의 데이터 입력 받기
    struct Shape shape;
    shape.type = (enum Shapetype)shapetype;

    switch (shape.type) {
        case TRIANGLE:
            printf("삼각형의 밑변과 높이를 입력하세요: ");
            scanf("%lf %lf", &shape.data.triangle.base, &shape.data.triangle.height);
            break;

        case RECTANGLE:
            printf("사각형의 가로와 세로를 입력하세요: ");
            scanf("%lf %lf", &shape.data.rectangle.width, &shape.data.rectangle.height);
            break;

        case CIRCLE:
            printf("원의 반지름을 입력하세요: ");
            scanf("%lf", &shape.data.circle.radius);
            break;

        default:
            printf("잘못된 도형 종류입니다.\n");
            return 1;
    }

    // 도형의 면적 계산 및 출력
    double area = calculate(&shape);
    printf("도형의 면적: %lf\n", area);

    return 0;
}																																									




// cd /workspace/SeowonCProject/assignment/week4/problem/ && gcc ./1.c -o /tmp/a.out -lm && clear && /tmp/a.out