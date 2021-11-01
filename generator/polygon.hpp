//
//  polygon.hpp
//  generator
//
//  Created by German Zvezdin on 30.10.2021.
//

#ifndef polygon_hpp
#define polygon_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <array>
#include <armadillo>
#include <memory>

double length(arma::vec3 vec);

class solid{
public:
    std::shared_ptr<arma::vec3[]> _vertex;
    int _vertexCount;
    int _lvlCount;
    friend std::ostream& operator <<(std::ostream & out, solid & t) {
        out << "#define DIM 3 \nconst int Nq = 18, NQ = Nq+1;\n";
        out << "device const ftype3 ciq[] = {";
        for(int i = 0; i < t._vertexCount; i++) {
            out << "{";
            for(int j = 0; j < 3; j++){
                out << t._vertex[i][j] << ",";
            }
            out << "},\n";
        }
        out << "};\n";
        
        return out;
    }
    arma::Mat<double> get();
};

class tetrahedron: public solid {
public:
    tetrahedron();
    explicit tetrahedron(double a);
};

class cube: public solid {
public:
    explicit cube(double a);
    cube();
};

class octahedron: public solid {
public:
    octahedron();
    explicit octahedron(double a);
};

class icosahedron: public solid {
public:
    icosahedron();
    explicit icosahedron(double S);
};

class polinoms {
    std::array<std::function<double(long double x)>, 10> data;

public:
    polinoms();
    double getValue(const std::array<int, 3> & tens, const arma::rowvec & x);

};


std::vector<std::array<int, 3>> combineProduct(int N);

arma::vec generator(cube & s);
arma::vec generator(tetrahedron & s);
arma::vec generator(octahedron & s);
arma::vec generator(icosahedron & s);



unsigned long long bcl(int n,int k);

#endif /* polygon_hpp */
