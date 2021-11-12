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
    //0 - octahedron 1 - cube 2 - cubeEdgeCenters 3 - icosahedron
    std::vector<std::tuple<int, double>> p = {{0, r}, {1, r}, {0, 2.0 * r}, {2, 2.0 * r}, {0, 3.0 * r}};
    auto w = customGenerator(p);
    cudaGenerator(w, p);
    return 0;
}
