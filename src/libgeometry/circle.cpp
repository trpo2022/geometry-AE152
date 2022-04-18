#include "structures.h"

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
    cout << "circle(" << figure->circle.point.x << " " << figure->circle.point.y
         << ", " << figure->circle.radius << ")" << endl;
    cout << "perimeter = " << cr_perimeter(figure) << endl;
    cout << "area = " << cr_area(figure) << endl << endl;
}

void recording_circle(string str_fgr, Figure* figure)
{
    string x_tmp = "";
    string y_tmp = "";
    string radius_tmp = "";
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