#include "structures.h"
#include <iostream>
#include <math.h>

#define _USE_MATH_DEFINES

double cr_perimeter(Figure figure)
{
    return (2 * M_PI * figure.circle.radius);
}

double cr_area(Figure figure)
{
    return (M_PI * pow(figure.circle.radius, 2));
}

void printing_circle(Figure* figure, int** arr, int amount_figr)
{
    for (int i = 0; i < amount_figr; i++) {
        std::cout << i + 1 << ". circle(" << figure[i].circle.point.x << " "
                  << figure[i].circle.point.y << ", " << figure[i].circle.radius
                  << ")" << std::endl;
        std::cout << "    perimeter = " << cr_perimeter(figure[i]) << std::endl;
        std::cout << "    area = " << cr_area(figure[i]) << std::endl;
        std::cout << "    intersects:" << std::endl;
        for (int j = 0; j < amount_figr; j++) {
            if (i == j)
                continue;
            if (arr[i][j] == 1)
                std::cout << "        " << j + 1 << ".circle" << std::endl;
        }
        std::cout << std::endl;
    }
}

void recording_circle(std::string str_fgr, Figure* figure)
{
    std::string x_tmp = "";
    std::string y_tmp = "";
    std::string radius_tmp = "";
    int i = str_fgr.find("(", 0) + 1;

    while (str_fgr[i] == ' ') //пропускаем пробелы перед первым числом
        i++;

    while (str_fgr[i] != ' ') { //считываем x
        x_tmp += str_fgr[i];
        i++;
    }

    while (str_fgr[i] == ' ') //пропускаем пробелы перед вторым числом
        i++;

    while (str_fgr[i] != ',') { //считываем y
        y_tmp += str_fgr[i];
        i++;
    }

    i++; //пропускаем запятую

    while (str_fgr[i] == ' ') //пропускаем пробелы перед радиусом
        i++;

    while (str_fgr[i] != ')') { //считываем радиус
        radius_tmp += str_fgr[i];
        i++;
    }

    figure->circle.point.x = atof(x_tmp.c_str());
    figure->circle.point.y = atof(y_tmp.c_str());
    figure->circle.radius = atof(radius_tmp.c_str());
}
