#include <spiral.h>
#include <cmath>

Spiral::Spiral(double r, double step) : radius_(abs(r)), step_(step) {}

Point Spiral::point(double t) const
{
    return {this->radius_ * cos(t),
                this->radius_ * sin(t),
                this->step_ * t/M_PI_2};
}

Direction Spiral::derivative(double t) const
{
    return {sin(t),
                cos(t),
                this->step_/M_PI_2};
}
