#pragma once
#include <curve.h>
#include <cmath>

class Circle : public Curve
{
public:
    Circle(double r);

    double radius() const;

    Point point(double t) const override;

    Direction derivative(double t) const override;

private:
    double radius_;
};
