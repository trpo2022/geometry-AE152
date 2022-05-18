#include <ctest.h>
#include <intersection_figures.h>
#include <iostream>
#include <main_recording.h>
#include <stdlib.h>

// basic test without setup/teardown
CTEST(amount_of_figures_suite, test1)
{
    // Given
    std::string filename = "in.txt";

    // When
    int result = amount_of_figures(filename);

    // Then
    int expected = 3;
    ASSERT_EQUAL(expected, result);
}

// there are many different ASSERT macro's (see ctest.h)
CTEST(recording_circle_suite, test2)
{
    // Given
    std::string str_fgr = "circle(0 1, 2)";
    Figure* figure = new Figure;

    // When
    recording_circle(str_fgr, figure);

    // Then
    int expected_x = 0;
    int expected_y = 1;
    int expected_radius = 2;
    ASSERT_EQUAL(expected_x, figure->circle.point.x);
    ASSERT_EQUAL(expected_y, figure->circle.point.y);
    ASSERT_EQUAL(expected_radius, figure->circle.radius);
}

CTEST(intersect_circle_suite, test3)
{
    // Given
    Figure* figure = new Figure[2];
    figure[0].circle.point.x = 0;
    figure[0].circle.point.y = 0;
    figure[0].circle.radius = 2;
    figure[1].circle.point.x = 0;
    figure[1].circle.point.y = 1;
    figure[1].circle.radius = 2;
    int amount_figure = 2;

    // When
    int** result = intersect_circle(figure, amount_figure);

    // Then
    ASSERT_EQUAL(0, result[0][0]);
    ASSERT_EQUAL(1, result[0][1]);
    ASSERT_EQUAL(1, result[1][0]);
    ASSERT_EQUAL(0, result[1][1]);
}

CTEST(perimetr_circle_suite, test4)
{
    // Given
    Figure figure;
    figure.circle.point.x = 0;
    figure.circle.point.y = 0;
    figure.circle.radius = 2;

    // When
    double res = cr_perimeter(figure);

    // Then
    double expected_perimetr = 12.566370614;
    ASSERT_DBL_NEAR_TOL(expected_perimetr, res, 0.00001);
}

CTEST(area_circle_suite, test5)
{
    // Given
    Figure figure;
    figure.circle.point.x = 0;
    figure.circle.point.y = 0;
    figure.circle.radius = 2;

    // When
    double res = cr_area(figure);

    // Then
    double expected_area = 12.566370614;
    ASSERT_DBL_NEAR_TOL(expected_area, res, 0.00001);
}
