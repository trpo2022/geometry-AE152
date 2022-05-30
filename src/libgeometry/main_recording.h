#pragma once
#include "circle.h"
#include "triangle.h"
#include <iostream>

int data_recording(std::string* str_figures, int amount_figr, Figure* figure);
int check_input(std::string* str_figures, int amount_figr);
int amount_of_figures(std::string filename);