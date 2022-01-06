//
//  main.cpp
//  generator
//
//  Created by German Zvezdin on 30.10.2021.
//
#include "polygon.hpp"
#include "utils.hpp"

int main() {
    /*
    double r = sqrt((125 + 5.0 * sqrt(193)) / 72);
    
    std::vector<arma::vec3> _vertex = {{r, 0.0, 0.0}, {-r, 0.0, 0.0},
        {0.0, r, 0.0}, {0.0, -r, 0.0}};
    customFigure a(4, _vertex);
    _vertex = {{-r, r, 0.0}, {r, -r, 0.0}, {r, r, 0.0}, {-r, -r, 0.0}};
    customFigure b(4, _vertex);
    _vertex = {{-2.0 * r, 2.0 * r, 0.0}, {2.0 * r, -2.0 * r, 0.0}, {2.0 * r, 2.0 * r, 0.0}, {-2.0 * r, -2.0 * r, 0.0}};
    customFigure c(4, _vertex);
    _vertex = {{3.0 * r, 0.0, 0.0}, {-3.0 * r, 0.0, 0.0},
        {0.0, 3.0 * r, 0.0}, {0.0, -3.0 * r, 0.0}};
    customFigure d(4, _vertex);
    
    customFigure zero;
    
    std::vector<solid> s = {zero, a, b, c, d};
    auto [w, order] = generator<2>(s);
    
    for(int i = 0; i < w.size(); i++) {
        std::cout << w[i] << std::endl;
    }
    std::cout << order << std::endl;
    */
    
    double r = 2.0 * sqrt(3.0 / 2.0);
    octahedron o1(r), o2(2.0 * r), o3(3.0 * r);
    cube c(r);
    cubeEdgeCenters cc(2.0 * r);
    customFigure zero;
    std::vector<solid> ss = {zero, o1, c, o2, cc, o3};
    auto [w, order] = generator<3>(ss);


    cudaGenerator<3>(w, ss, order, "/Users/germanzvezdin/Desktop/Git/ermPoints/res2.dat");
    
    return 0;
}
