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
#include <map>

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

class cubeEdgeCenters: public solid {
public:
    explicit cubeEdgeCenters(double a);
};

class cubeCenters: public solid {
public:
    explicit cubeCenters(double a);
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
arma::vec D3Q27Generator(cube & c, octahedron & o, cubeEdgeCenters & cc);
arma::vec D3Q19Generator(octahedron & o, cubeEdgeCenters & cc);
arma::vec D3Q15Generator(cube & c, octahedron & o);
arma::vec D3Q39Generator(octahedron & o1, cube & c1, octahedron & o2, cubeEdgeCenters & cc, octahedron & o3);

std::shared_ptr<solid> solidFabric(int type, double p);
arma::vec customGenerator(std::vector<std::tuple<int, double> > &p);
unsigned long long bcl(int n,int k);

#endif /* polygon_hpp */
