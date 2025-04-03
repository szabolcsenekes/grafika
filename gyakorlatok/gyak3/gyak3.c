#include <stdio.h>

typedef struct {
    unsigned char r;  
    unsigned char g;  
    unsigned char b;  
} Color;

typedef struct {
    int x1, y1; 
    int x2, y2;  
    Color color; 
} Line;

void printLine(const Line *line) {
    printf("Line from (%d, %d) to (%d, %d)\n", line->x1, line->y1, line->x2, line->y2);
    printf("Color: R=%d, G=%d, B=%d\n", line->color.r, line->color.g, line->color.b);
}

int main() {
    Line line = {
        .x1 = 0,
        .y1 = 0,
        .x2 = 100,
        .y2 = 100,
        .color = {255, 0, 0}
    };

    printLine(&line);

    return 0;
}
