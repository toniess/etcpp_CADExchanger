#include <ellipse.h>
#include <cmath>

Ellipse::Ellipse(double rx, double ry) : radiusX_(abs(rx)), radiusY_(abs(ry)) {}

Point Ellipse::point(double t) const
{
    return {this->radiusX_ * cos(t),
                this->radiusY_ * sin(t),
                0}; // ellipse is flat
}

Direction Ellipse::derivative(double t) const
{
    return {-radiusX_*sin(t),
                radiusY_*cos(t),
                0};
}
