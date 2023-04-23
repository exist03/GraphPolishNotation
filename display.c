#include <math.h>
#include <stdio.h>
#define scene_x 80
#define scene_y 25
#include "value.h"

void display();

void display(char *exit) {
    char scene[scene_y][scene_x];
    double step = 4 * M_PI / 79;
    double dot[scene_x];
    double X = 0;
    int flag = 1;
    int i = 0;
    while (i < 80) {
        dot[i] = value(exit, X, &flag);
        if (!flag) dot[i] = 10;
        X += step;
        i++;
    }
    for (i = 0; i < scene_y; i++) {
        for (int j = 0; j < scene_x; j++) {
            scene[i][j] = '.';
        }
    }
    double stp = 2.0 / 24.0;
    for (i = 0; i < scene_x; i++) {
        double n = -1.0;
        for (int j = 0; j < scene_y; j++) {
            if (dot[i] >= n - stp / 2 && dot[i] <= n + stp / 2) {
                scene[j][i] = '*';
            }
            n += stp;
        }
    }
    for (i = 0; i < scene_y; i++) {
        for (int j = 0; j < scene_x; j++) {
            printf("%c", scene[i][j]);
        }
        printf("\n");
    }
}
