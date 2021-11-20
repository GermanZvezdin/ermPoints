//
//  main.cpp
//  generator
//
//  Created by German Zvezdin on 30.10.2021.
//

#include "utils.hpp"
#include "polygon.hpp"
int main() {
    double r = 2.0 * sqrt(3.0 / 2.0);
    //MARK: 0 - octahedron 1 - cube 2 - cubeEdgeCenters 3 - icosahedron, 4 - polygon, 5 - 1D polygon
    //MARK: An example of D3Q39 solution
    std::vector<std::tuple<int, double, std::optional<int>>> p1 = {{0, r, std::nullopt}, {1, r, std::nullopt}, {0, 2.0 * r, std::nullopt}, {2, 2.0 * r, std::nullopt}, {0, 3.0 * r, std::nullopt}};
    auto w = customGenerator(p1);
    cudaGenerator<3>(w, p1);
    //MARK: An example of 2D solution
    
    std::vector<std::tuple<int, double, std::optional<int>>> p2 = {{4, 1.0, 4}, {4, r, 10}};
    
    w = customGenerator(p2);
    cudaGenerator<2>(w, p2);
    
    //MARK: An example of 1D solution
    std::vector<std::tuple<int, double, std::optional<int>>> p3 = {{5, 1.0, 4}, {5, r, 10}};
    
    w = customGenerator(p3);
    cudaGenerator<1>(w, p3);
    
    return 0;
}
