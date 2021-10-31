//
//  main.cpp
//  generator
//
//  Created by German Zvezdin on 30.10.2021.
//

#include <iostream>
#include "polygon.hpp"
//286
int main() {
    cube c(10.0);
    auto w = generator(c);
    std::cout << w;
    return 0;
}
