#include "structures.h"
#include <iostream>
#include <math.h>

#define _USE_MATH_DEFINES

double cr_perimeter(Figure* figure)
{
    return (2 * M_PI * figure->circle.radius);
}

double cr_area(Figure* figure)
{
    return (M_PI * pow(figure->circle.radius, 2));
}

void printing_circle(Figure* figure)
{
    std::cout << "circle(" << figure->circle.point.x << " "
              << figure->circle.point.y << ", " << figure->circle.radius << ")"
              << std::endl;
    std::cout << "perimeter = " << cr_perimeter(figure) << std::endl;
    std::cout << "area = " << cr_area(figure) << std::endl << std::endl;
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
    printing_circle(figure);
}
