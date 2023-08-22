#pragma once
#include <curve.h>

class Ellipse : public Curve
{
public:
    Ellipse(double rx, double ry);

    Point point(double t) const override;

    Direction derivative(double t) const override;
private:
    double radiusX_;
    double radiusY_;
};
