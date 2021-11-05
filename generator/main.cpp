//
//  main.cpp
//  generator
//
//  Created by German Zvezdin on 30.10.2021.
//

#include "utils.hpp"

int main() {
    double r = sqrt(3.0 / 2.0);
    //D3Q15(r);
    //D3Q27();
    D3Q39(r);
    return 0;
}
