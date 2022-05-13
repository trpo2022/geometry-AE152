#pragma once
//#include <fstream>
//#include <iostream>
//#include <math.h>
//#include <stdlib.h>
//#define _USE_MATH_DEFINES

// using namespace std;

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