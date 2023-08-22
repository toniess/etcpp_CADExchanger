#include <circle.h>

Circle::Circle(double r) : radius_(abs(r)) {}

double Circle::radius() const
{
    return this->radius_;
}

Point Circle::point(double t) const
{
    return {this->radius_ * cos(t),
                this->radius_ * sin(t),
                0}; // circle is flat
}

Direction Circle::derivative(double t) const
{
    return {-sin(t),
                cos(t),
                0};
}
