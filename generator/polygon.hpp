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
#include <algorithm>
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

class polygon: public solid {
public:
    explicit polygon(int N);
    polygon(double a, double angle, int N);
};

class customFigure: public solid {
public:
    customFigure(int vertexCount, std::vector<arma::vec3> &inp);
    customFigure(int vertexCount, std::vector<std::array<long double, 3>> &inp);
    explicit customFigure(arma::vec3 inp);
    customFigure();
    
};

class line: public solid {
public:
    line(double a);
};

class polinoms {
    std::array<std::function<double(long double x)>, 12> data;

public:
    polinoms();
    int get();
    template<int dim>
    double getValue(const std::vector<int> & tens, const arma::rowvec & x) {
        double ans = 1.0;
        for (int i = 0; i < dim; i++) {
            ans *= data[tens[i]](x[i]);
        }
        return ans;
    }

};

template <int dim>
std::vector<std::vector<int>> combineProduct(int n) {
    std::vector<std::vector<int>> res;
    switch (dim) {
        case 1:
            res = {{n}};
            break;
        case 2: {
            std::vector<int> curRes;
            for (int i = 0; i <= n; i++) {
                curRes = {i, n - i};
                res.push_back(curRes);
            }
            break;
        }
        case 3: {
            std::vector<int> curRes;
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    int p = n - j - i;
                    if (p >= 0) {
                        curRes = {i, j, p};
                        res.push_back(curRes);
                    }
                }

            }
            break;
        }

    }
    return res;
}

template<const int dim>
std::tuple<arma::vec, int> generator(std::vector<solid> & objects){
    polinoms pol;
    std::vector<std::vector<double>> tmpA;
    for(int i = 0; i < pol.get(); i++) {
        std::vector<std::vector<int>> outComb = combineProduct<dim>(i);
        for (auto tens : outComb) {
            std::vector<double> w;
            w.resize(objects.size());
            std::fill(w.begin(), w.end(), 0.0);
            for(int k = 0; k < objects.size(); k++) {
                arma::Mat<double> objCoords = objects[k].get();
                for(int l = 0; l < objects[k]._vertexCount; l++) {
                    w[k] += pol.getValue<dim>(tens, objCoords.row(l));
                }
            }
            tmpA.push_back(w);
        }
    }
    int rank = 0;
    arma::Mat<double> A(tmpA.size(), objects.size(), arma::fill::zeros);
    for(int i = 0; i < tmpA.size(); i++) {
        arma::rowvec curRow(objects.size(), arma::fill::zeros);
        for(int j = 0; j < objects.size(); j++) {
            curRow[j] = tmpA[i][j];
        }
        A.row(rank) = curRow;
        if(arma::rank(A) > rank) {
            rank++;
        }
    }
    A.resize(rank, objects.size());
    arma::vec F(rank, arma::fill::zeros);
    F[0] = 1.0;
    arma::vec w = arma::solve(A, F);
    
    int order = 0;
    
    for(int i = 0; i < pol.get(); i++) {
        std::vector<int> tens = {i, 0, 0};
        std::vector<double> c;
        c.resize(objects.size());
        std::fill(c.begin(), c.end(), 0.0);
        for(int k = 0; k < objects.size(); k++) {
            arma::Mat<double> objCoords = objects[k].get();
            for(int l = 0; l < objects[k]._vertexCount; l++) {
                c[k] += pol.getValue<dim>(tens, objCoords.row(l));
            }
        }
        double check = 0.0;
        for(int k = 0; k < objects.size(); k++) {
            check += c[k] * w[k];
        }
        if(i == 0){
            if(check == 1.0){
                order = 1;
            }
        } else {
            if(abs(check) < 0.001){
                order = i;
            } else {
                break;
            }
        }
        
    }
    
    return std::tuple<arma::vec, int>(w, order);
}
unsigned long long bcl(int n,int k);

template<int dim>
inline std::tuple<arma::vec, int> newGenerator(std::vector<solid> & objects) {
    static polinoms pol;
    std::vector<std::vector<double>> tmpA;
    
    
}




#endif /* polygon_hpp */
