#include "structures.h"
#include <algorithm>
#include <math.h>

//окружности пересекаются, если расстояние между центрами меньше суммы радиусов
int** intersect_circle(Figure* figure, int amount_figr)
{
    double d = 0; //расстояние между центрами окружностей
    int** arr = new int* [amount_figr] { 0 }; //массив для записи пересечений
    for (int m = 0; m < amount_figr; m++) {
        arr[m] = new int[amount_figr]{0};
    }
    for (int i = 0; i < amount_figr; i++) {
        for (int j = 0; j < amount_figr; j++) {
            if (i == j)
                continue;
            d = sqrt(
                    pow(figure[i].circle.point.x - figure[j].circle.point.x, 2)
                    + pow(figure[i].circle.point.y - figure[j].circle.point.y,
                          2));
            if (d < (figure[i].circle.radius + figure[j].circle.radius)) {
                arr[i][j] = 1;
            }
            d = 0;
        }
    }
    return arr;
}
