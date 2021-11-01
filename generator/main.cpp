//
//  main.cpp
//  generator
//
//  Created by German Zvezdin on 30.10.2021.
//

#include <iostream>
#include "polygon.hpp"

int main() {
    icosahedron i(1);
    auto w = generator(i);
    std::cout << i << std::endl;
    std::cout << "device const ftype wiq[] = {" << std::endl;
    std::cout << w[0] << "," << std::endl;
    for(int i = 0; i < 5; i++){
        std::cout << w[1] << "," << std::endl;
    }
    for(int i = 0; i < 5; i++){
        std::cout << w[2] << "," << std::endl;
    }
    std::cout << w[3] << "};" << std::endl;
    std::cout << "const ftype w0 = " << w[4] << ";" <<std::endl;
    return 0;
}
