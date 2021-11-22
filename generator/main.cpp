//
//  main.cpp
//  generator
//
//  Created by German Zvezdin on 30.10.2021.
//

#include "utils.hpp"
#include "polygon.hpp"
int main() {
    
    auto a = sqrt(2.5 + sqrt(2.5));
    auto b = sqrt(2.5 - sqrt(2.5));
    std::vector<arma::vec3> data = {
        {-a, -b, 0.0}, {-a, b, 0.0}, {a, -b, 0.0}, {a, b, 0.0},
        {-b, -a, 0.0}, {-b, a, 0.0}, {b, -a, 0.0}, {b, a, 0.0}};
    
    customFigure f1(8, data);
    polygon s1(2.0 * a / sqrt(2), 0, 4), s2(2.0 * a, M_PI / 4.0, 4), s3(2.0 * b / sqrt(2), 0, 4),
    s4(2.0 * b, M_PI / 4.0, 4);
    

    std::vector<solid> s = {f1, s1, s2, s3, s4};
    
    auto [w, order] = generator<3>(s);
    std::cout << order << std::endl;
    
    cudaGenerator<2>(w, s);
    
    return 0;
}
