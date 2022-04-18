#include "main_recording.h"

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