#include <iostream>
#include <vector>
#include <iomanip>

#include <curve.h>
#include <circle.h>
#include <ellipse.h>
#include <spiral.h>

#pragma omp parallel for


void fillAtRandom(std::vector<std::shared_ptr<Curve>>& curves) {
    srand(time(nullptr));
    int size = rand()%20;
    auto randDouble = []() -> double {
        return (rand()%1839)/17;
    };
    while(size--){
        int choice = rand()%3;
        if(choice == 0){
            curves.push_back(std::make_shared<Circle>   (randDouble()) );
        }else if(choice == 1){
            curves.push_back(std::make_shared<Ellipse>  (randDouble(), randDouble())  );
        }else if(choice == 2){
            curves.push_back(std::make_shared<Spiral>   (randDouble(), randDouble())   );
        }
    }
}

int main() {

    std::vector<std::shared_ptr<Curve>> curves;
    fillAtRandom(curves);

    int num = 1;
    auto t = M_2_PI;
    for(auto curve : curves){
        auto [x, y, z] = curve->point(t);
        auto [i, j, k] = curve->derivative(t);
        std::cout << "Figure №" << num++
                  << "\tpoint (" << x << ", " << y << ", " << z << ")"
                  << "\tderevative {" << i << ", " << j << ", " << k << "}\n";
    }

    std::cout << "\nSORTED CIRCLES:\n";

    std::vector<std::shared_ptr<Circle>> circles;
    for(auto curve : curves) {
        auto ptr = dynamic_pointer_cast<Circle>(curve);
        if(ptr){
            circles.push_back(ptr);
        }
    }
    std::sort(circles.begin(), circles.end(),
              [](const auto& a, const auto& b) {
                    return a->radius() < b->radius();
    });

    num = 1;
    for(auto circle : circles){
        std::cout << "Circle №" << num++
                  << "\tradius " << circle->radius() << '\n';
    }
}

