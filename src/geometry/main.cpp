#include "libgeometry/intersection_figures.h"
#include "libgeometry/main_recording.h"
#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc == 1)
        std::cout << "нет входного файла" << std::endl;
    std::string filename = argv[1];
    std::ifstream input(filename);
    if (!input.is_open()) {
        std::cout << "File not found!" << std::endl;
        return 0;
    }
    int amount_figr = amount_of_figures(filename);
    std::string* str_figures = new std::string[amount_figr];
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
    std::cout << std::endl << std::endl;

    return 0;
}