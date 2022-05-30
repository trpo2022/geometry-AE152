#pragma once

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