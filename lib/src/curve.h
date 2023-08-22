#pragma once
#pragma omp parallel for
#include <iostream>
#include <array>

using Point = std::array<double, 3>;
using Direction = std::array<double, 3>;

class Curve
{
public:
    virtual ~Curve() {}

    virtual Point point(double t) const = 0;
    virtual Direction derivative(double t) const = 0;
};
