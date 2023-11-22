#include <stdio.h>

// x: 들여쓰기, y: 줄바꿈
void gotoxy(int x, int y) {
    printf("\033[%d;%df", y, x);
}

int main() {
    int x, y;
    printf("Enter the coordinates (x, y): ");
    scanf("%d %d", &x, &y);

    gotoxy(x, y);
    printf("Input: ");

    char input[100];
    scanf("%s", input);

    printf("Entered value: %s\n", input);

    return 0;
}
