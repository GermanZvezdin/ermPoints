//
// Created by German Zvezdin on 14.10.2021.
//

#include "polinoms.hpp"


polinoms::polinoms() {
    data[0] = [](long double x) {return 1;};
    data[1] = [](long double x) {return x;};
    data[2] = [](long double x) {return x * x - 1;};
    data[3] = [](long double x) {return x * x * x - 3 * x;};
    data[4] = [](long double x) {return pow(x, 4) - 6 * pow(x, 2) + 3;};
    data[5] = [](long double x) {return pow(x, 5) - 10 * pow(x, 3) + 15 * x;};
    data[6] = [](long double x) {return pow(x, 6) - 15 * pow(x, 4) + 45 * pow(x, 2) - 15;};
    data[7] = [](long double x) {return pow(x, 7) - 21 * pow(x, 5) + 105 * pow(x, 3) - 105 * x;};
    data[8] = [](long double x) {return pow(x, 8) - 28 * pow(x, 6) + 210 * pow(x, 4) - 420 * pow(x, 2) + 105;};
    data[9] = [](long double x) {return pow(x, 9) - 36 * pow(x, 7) + 378 * pow(x, 5) - 1260 * pow(x, 3) +  945 * x;};
    std::cout << "polinom has been initialized" << std::endl;
}












