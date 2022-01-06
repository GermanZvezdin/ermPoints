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
    
    long double a = 1.154405394739968127239597758837986484573544294214371756;
    long double b = 2.366759410734541288618856468559933327175413119647585579;
    long double c = 3.750439717725742256303922025712380803838774169741958576;
    
    line l1(a), l2(b), l3(c);
    customFigure zero;

    std::vector<solid> s = {zero, l1, l2, l3};
    
    auto [w, order] = generator<1>(s);
    
    
    cudaGenerator<2>(w,s, order, "FileNameWithOutExtension");
    
    return 0;
}
