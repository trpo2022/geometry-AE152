#include <main_recording.h>

int main(int argc, char* argv[])
{
    if (argc == 1)
        cout << "нет входного файла" << endl;
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