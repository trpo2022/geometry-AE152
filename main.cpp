#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Point {
    double x;
    double y;
};

struct Circle {
    Point point;
    double radius;
};

struct Triangle {
    Point point[4];
};

struct Figure {
    Circle circle;
    Triangle triangle;
};

int amount_of_figures(string filename) //считает количество фигур
{
    ifstream input(filename);
    if (!input.is_open()) {
        cout << "File not found!" << endl;
        return 0;
    }
    int amount_strok = 1;
    bool flag = true;
    while (flag) {
        if (input.eof()) {
            flag = false;
            break;
        }

        if (input.get() == '\n') {
            amount_strok++;
        }
    }
    return amount_strok;
}

int check_input(string* str_figures, int amount_figr)
{
    int balance_skobok = 0;
    for (int i = 0; i < amount_figr; i++) {
        //цикл по каждому символу в строке
        for (int j = 0; j < (int)str_figures[i].length(); j++) {
            if (str_figures[i][j] == '(')
                balance_skobok++;
            if (str_figures[i][j] == ')')
                balance_skobok--;
        }
        if (balance_skobok != 0) {
            cout << "Check brackets: " << str_figures[i] << endl;
            return -1;
        } else
            balance_skobok = 0;
    }
    return 0;
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

void printing_circle(Figure* figure)
{
    cout << "circle(" << figure->circle.point.x << " " << figure->circle.point.y
         << ", " << figure->circle.radius << ")" << endl;
}

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

int data_recording(string* str_figures, int amount_figr, Figure* figure)
{
    string name_figure = "";
    for (int i = 0; i < amount_figr; i++) {
        //цикл по каждому символу в строке
        for (int j = 0; j < (int)str_figures[i].length(); j++) {
            if (str_figures[i][j] != '(')
                name_figure += tolower(str_figures[i][j]);
            else {
                if (name_figure == "triangle")
                    recording_triangle(str_figures[i], &figure[i]);
                else if (name_figure == "circle")
                    recording_circle(str_figures[i], &figure[i]);
                else {
                    cout << "Wrong figure name: " << str_figures[i] << endl;
                    return -1;
                }
                name_figure = "";
                break;
            }
        }
    }
    return 0;
}

int main(int argc, char* argv[])
{
    string filename = argv[1];
    ifstream input(filename);
    if (!input.is_open()) {
        cout << "File not found!" << endl;
        return 0;
    }
    int amount_figr = amount_of_figures(filename);
    string* str_figures = new string[amount_figr];
    for (int i = 0; i < amount_figr; i++) {
        getline(input, str_figures[i]);
    }
    if (check_input(str_figures, amount_figr) != 0) {
        return -1;
    }
    Figure* figure = new Figure[amount_figr];
    if (data_recording(str_figures, amount_figr, figure) != 0) {
        return -1;
    }
    return 0;
}