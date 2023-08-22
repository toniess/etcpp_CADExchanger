#pragma once
#include <curve.h>

class Spiral : public Curve
{
public:
    Spiral(double r, double step);

    Point point(double t) const override;

    Direction derivative(double t) const override;

private:
    double radius_;
    double step_;
};
