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
    polygon s1(2.0 * a / sqrt(2), 4, 0), s2(2.0 * a, 4, M_PI / 4.0), s3(2.0 * b / sqrt(2), 4, 0),
    s4(2.0 * b, 4, M_PI / 4.0);
    

    std::vector<solid> s = {s1, s2, s3, s4};
    //auto w = generator<2>(s);
    
    
    double r = 2.0 * sqrt(3.0 / 2.0);
    
    octahedron o1(r), o2(2.0 * r), o3(3.0 * r);
    cube c(r);
    cubeEdgeCenters cc(2.0 * r);
    
    std::vector<solid> ss = {o1, c, o2, cc, o3};
    
    auto [w, order] = generator<3>(ss);
    
    std::cout << order << std::endl;
    
    return 0;
}
