#include "triangle.h"

void recording_triangle(string str_fgr, Figure* figure)
{
    string x_tmp = "";
    string y_tmp = "";
    int i = str_fgr.find("((", 0) + 2;

    for (int j = 0; j < 4; j++) { //цикл по всем x и y
        while (str_fgr[i] == ' ') //пропускаем пробелы перед первым числом
            i++;

        while (str_fgr[i] != ' ') { //считываем x
            x_tmp += str_fgr[i];
            i++;
        }

        while (str_fgr[i] == ' ') //пропускаем пробелы перед вторым числом
            i++;

        while (str_fgr[i] != ',' && str_fgr[i] != ')') { //считываем y
            y_tmp += str_fgr[i];
            i++;
        }
        i++; //пропускаем запятую
        figure->triangle.point[j].x = atof(x_tmp.c_str());
        figure->triangle.point[j].y = atof(y_tmp.c_str());
        x_tmp = y_tmp = "";
    }
    printing_traingle(figure);
}

double tr_perimeter(Figure* figure)
{
    double perimeter = 0;
    double* x = new double[4];
    double* y = new double[4];
    for (int i = 0; i <= 3; i++) {
        x[i] = figure->triangle.point[i].x;
        y[i] = figure->triangle.point[i].y;
    }
    for (int j = 0; j < 3; j++) {
        perimeter += sqrt(pow(x[j + 1] - x[j], 2) + pow(y[j + 1] - y[j], 2));
    }
    return perimeter;
}

double tr_area(Figure* figure)
{
    double area = 0;
    double* x = new double[4];
    double* y = new double[4];
    for (int i = 0; i <= 3; i++) {
        x[i] = figure->triangle.point[i].x;
        y[i] = figure->triangle.point[i].y;
    }
    area = 0.5
            * abs((x[1] - x[0]) * (y[2] - y[0])
                  - (x[2] - x[0]) * (y[1] - y[0]));
    return area;
}

void printing_traingle(Figure* figure)
{
    cout << "triangle((";
    for (int j = 0; j < 3; j++) {
        cout << figure->triangle.point[j].x << " "
             << figure->triangle.point[j].y << ", ";
    }
    cout << figure->triangle.point[3].x << " " << figure->triangle.point[3].y
         << "))" << endl;
    cout << "perimeter = " << tr_perimeter(figure) << endl;
    cout << "area = " << tr_area(figure) << endl << endl;
}
