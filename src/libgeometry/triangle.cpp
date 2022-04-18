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

void printing_traingle(Figure* figure)
{
    cout << "triangle((";
    for (int j = 0; j < 3; j++) {
        cout << figure->triangle.point[j].x << " "
             << figure->triangle.point[j].y << ", ";
    }
    cout << figure->triangle.point[3].x << " " << figure->triangle.point[3].y
         << "))" << endl;
}