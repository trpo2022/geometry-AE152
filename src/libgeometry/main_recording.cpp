#include "main_recording.h"
#include "intersection_figures.h"
#include <fstream>

int amount_of_figures(std::string filename) //считает количество фигур
{
    std::ifstream input(filename);
    if (!input.is_open()) {
        std::cout << "File not found!" << std::endl;
        return 0;
    }
    int amount_strok = 0;
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

int check_input(std::string* str_figures, int amount_figr)
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
            std::cout << "Check brackets: " << str_figures[i] << std::endl;
            return -1;
        } else
            balance_skobok = 0;
    }
    return 0;
}

int data_recording(std::string* str_figures, int amount_figr, Figure* figure)
{
    std::string name_figure = "";
    for (int i = 0; i < amount_figr; i++) {
        //цикл по каждому символу в строке
        for (int j = 0; j < (int)str_figures[i].length(); j++) {
            if (str_figures[i][j] != '(')
                name_figure += tolower(str_figures[i][j]);
            else {
                if (name_figure == "triangle") {
                    recording_triangle(str_figures[i], &figure[i]);
                } else if (name_figure == "circle") {
                    recording_circle(str_figures[i], &figure[i]);
                } else {
                    std::cout << "Wrong figure name: " << str_figures[i]
                              << std::endl;
                    return -1;
                }
                name_figure = "";
                break;
            }
        }
    }
    int** arr = intersect_circle(figure, amount_figr);
    printing_circle(figure, arr, amount_figr);
    return 0;
}