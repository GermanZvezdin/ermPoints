//
//  polygon.cpp
//  generator
//
//  Created by German Zvezdin on 30.10.2021.
//

#include "polygon.hpp"
#include <cmath>


double length(arma::vec3 vec){
    return sqrt(arma::dot(vec, vec));
}
arma::Mat<double> solid::get(){
    arma::Mat<double> m(_vertexCount, 3);
    for(int i = 0; i < _vertexCount; i++) {
        m.row(i) = arma::trans(_vertex[i]);
    }
    return m;
}
tetrahedron::tetrahedron(){
    _lvlCount = 2;
    _vertex = std::shared_ptr<arma::vec3[]>(new arma::vec3[4]);
    _vertexCount = 4;
    _vertex[0] = arma::vec3({-1.0 / 2.0, -1.0 / (2.0 * sqrt(3)), 0.0});
    _vertex[1] = arma::vec3({1.0 / 2, -1.0 / (2 * sqrt(3)), 0.0});
    _vertex[2] = arma::vec3({0.0, 1.0 / sqrt(3), 0.0});
    _vertex[3] = arma::vec3({0.0, 0.0, 1.0 * sqrt(2.0 / 3.0)});
}

tetrahedron::tetrahedron(double a){
    _lvlCount = 2;
    _vertex = std::shared_ptr<arma::vec3[]>(new arma::vec3[4]);
    _vertexCount = 4;
    _vertex[0] = arma::vec3({-a / 2.0, -a / (2.0 * sqrt(3)), 0.0});
    _vertex[1] = arma::vec3({a / 2, -a / (2 * sqrt(3)), 0.0});
    _vertex[2] = arma::vec3({0.0, a / sqrt(3), 0.0});
    _vertex[3] = arma::vec3({0.0, 0.0, a * sqrt(2.0 / 3.0)});
}

cube::cube(double a) {
    _lvlCount = 2;
    _vertex = std::shared_ptr<arma::vec3[]>(new arma::vec3[8]);
    a /= 2.0;
    _vertexCount = 8;
    _vertex[0] = arma::vec3({-a, -a, -a});
    _vertex[1] = arma::vec3({-a, a, -a});
    _vertex[2] = arma::vec3({a, -a, -a});
    _vertex[3] = arma::vec3({a, a, -a});
    _vertex[4] = arma::vec3({-a, -a, a});
    _vertex[5] = arma::vec3({-a, a, a});
    _vertex[6] = arma::vec3({a, -a, a});
    _vertex[7] = arma::vec3({a, a, a});
}
cube::cube() {
    _lvlCount = 2;
    _vertex = std::shared_ptr<arma::vec3[]>(new arma::vec3[8]);
    _vertexCount = 8;
    _vertex[0] = arma::vec3({-1, -1, -1});
    _vertex[1] = arma::vec3({-1, 1, -1});
    _vertex[2] = arma::vec3({1, -1, -1});
    _vertex[3] = arma::vec3({1, 1, -1});
    _vertex[4] = arma::vec3({-1, -1, 1});
    _vertex[5] = arma::vec3({-1, 1, 1});
    _vertex[6] = arma::vec3({1, -1, 1});
    _vertex[7] = arma::vec3({1, 1, 1});
}

cubeEdgeCenters::cubeEdgeCenters(double a) {
    _lvlCount = 1;
    _vertexCount = 12;
    _vertex = std::shared_ptr<arma::vec3[]>(new arma::vec3[12]);
    a /= 2.0;
    _vertex[0] = arma::vec3({a, a, 0.0});
    _vertex[1] = arma::vec3({a, -a, 0.0});
    _vertex[2] = arma::vec3({-a, a, 0.0});
    _vertex[3] = arma::vec3({-a, -a, 0.0});
    _vertex[4] = arma::vec3({0.0, a, a});
    _vertex[5] = arma::vec3({0.0, a, -a});
    _vertex[6] = arma::vec3({0.0, -a, a});
    _vertex[7] = arma::vec3({0.0, -a, -a});
    _vertex[8] = arma::vec3({a, 0.0, a});
    _vertex[9] = arma::vec3({a, 0.0, -a});
    _vertex[10] = arma::vec3({-a, 0.0, a});
    _vertex[11] = arma::vec3({-a, 0.0, -a});
}

cubeCenters::cubeCenters(double a) {
    _lvlCount = 1;
    _vertex = std::shared_ptr<arma::vec3[]>(new arma::vec3[6]);
    a /= 2.0;
    _vertex[0] = arma::vec3({0.0, 0.0, a});
    _vertex[1] = arma::vec3({a, 0.0, 0.0});
    _vertex[2] = arma::vec3({0.0, -a, 0.0});
    _vertex[3] = arma::vec3({-a, 0.0, 0.0});
    _vertex[4] = arma::vec3({0.0, a, 0.0});
    _vertex[5] = arma::vec3({0.0, 0.0, -a});
}

octahedron::octahedron(){
    _lvlCount = 3;
    _vertex = std::shared_ptr<arma::vec3[]>(new arma::vec3[6]);
    _vertexCount = 6;
    _vertex[0] = arma::vec3({ 1,  0,  0});
    _vertex[1] = arma::vec3({ 0,  1,  });
    _vertex[2] = arma::vec3({ 0,  0,  1});
    _vertex[3] = arma::vec3({-1,  0,  0});
    _vertex[4] = arma::vec3({ 0, -1,  0});
    _vertex[5] = arma::vec3({0,  0, -1});
}
octahedron::octahedron(double a){
    _lvlCount = 3;
    _vertex = std::shared_ptr<arma::vec3[]>(new arma::vec3[6]);
    _vertexCount = 6;
    a /= 2.0;
    _vertex[0] = arma::vec3({ a,  0,  0});
    _vertex[1] = arma::vec3({ 0,  a,  });
    _vertex[2] = arma::vec3({ 0,  0,  a});
    _vertex[3] = arma::vec3({-a,  0,  0});
    _vertex[4] = arma::vec3({ 0, -a,  0});
    _vertex[5] = arma::vec3({0,  0, -a});
}

icosahedron::icosahedron(){
    _lvlCount = 4;
    _vertex = std::shared_ptr<arma::vec3[]>(new arma::vec3[12]);
    _vertexCount = 12;
    double S = 1.0;
    double t2 = M_PI / 10.0;
    double t4 = M_PI / 5.0;
    double R = (S / 2.0) / sin(t4);
    double H = cos(t4) * R;
    double Cx = R * cos(t2);
    double Cy = R * sin(t2);
    double H1 = sqrt(S * S - R * R);
    double H2 = sqrt((H + R) * (H + R) - H * H);
    double Z2 = (H2 - H1) / 2.0;
    double Z1 = Z2 + H1;
    
    _vertex[0] = arma::vec3({0.0, 0.0, Z1});
    _vertex[1] = arma::vec3({0.0, R, Z2});
    _vertex[2] = arma::vec3({Cx, Cy, Z2});
    _vertex[3] = arma::vec3({S / 2.0, -H, Z2});
    _vertex[4] = arma::vec3({-S / 2.0, -H, Z2});
    _vertex[5] = arma::vec3({-Cx,  Cy,  Z2});
    _vertex[6] = arma::vec3({0.0, -R, -Z2});
    _vertex[7] = arma::vec3({-Cx, -Cy, -Z2});
    _vertex[8] = arma::vec3({-S / 2.0, H, -Z2});
    _vertex[9] = arma::vec3({S / 2.0, H, -Z2});
    _vertex[10] = arma::vec3({Cx, -Cy, -Z2});
    _vertex[11] = arma::vec3({0.0, 0.0, -Z1});
}

icosahedron::icosahedron(double S){
    _lvlCount = 4;
    _vertex = std::shared_ptr<arma::vec3[]>(new arma::vec3[12]);
    _vertexCount = 12;
    double t2 = M_PI / 10.0;
    double t4 = M_PI / 5.0;
    double R = (S / 2.0) / sin(t4);
    double H = cos(t4) * R;
    double Cx = R * cos(t2);
    double Cy = R * sin(t2);
    double H1 = sqrt(S * S - R * R);
    double H2 = sqrt((H + R) * (H + R) - H * H);
    double Z2 = (H2 - H1) / 2.0;
    double Z1 = Z2 + H1;
    
    _vertex[0] = arma::vec3({0.0, 0.0, Z1});
    _vertex[1] = arma::vec3({0.0, R, Z2});
    _vertex[2] = arma::vec3({Cx, Cy, Z2});
    _vertex[3] = arma::vec3({S / 2.0, -H, Z2});
    _vertex[4] = arma::vec3({-S / 2.0, -H, Z2});
    _vertex[5] = arma::vec3({-Cx,  Cy,  Z2});
    _vertex[6] = arma::vec3({0.0, -R, -Z2});
    _vertex[7] = arma::vec3({-Cx, -Cy, -Z2});
    _vertex[8] = arma::vec3({-S / 2.0, H, -Z2});
    _vertex[9] = arma::vec3({S / 2.0, H, -Z2});
    _vertex[10] = arma::vec3({Cx, -Cy, -Z2});
    _vertex[11] = arma::vec3({0.0, 0.0, -Z1});
}

polinoms::polinoms() {
    data[0] = [](long double x) {return 1;};
    data[1] = [](long double x) {return x;};
    data[2] = [](long double x) {return x * x - 1;};
    data[3] = [](long double x) {return x * x * x - 3 * x;};
    data[4] = [](long double x) {return pow(x, 4) - 6 * pow(x, 2) + 3;};
    data[5] = [](long double x) {return pow(x, 5) - 10 * pow(x, 3) + 15 * x;};
    data[6] = [](long double x) {return pow(x, 6) - 15 * pow(x, 4) + 45 * pow(x, 2) - 15;};
    data[7] = [](long double x) {return pow(x, 7) - 21 * pow(x, 5) + 105 * pow(x, 3) - 105 * x;};
    data[8] = [](long double x) {return pow(x, 8) - 28 * pow(x, 6) + 210 * pow(x, 4) - 420 * pow(x, 2) + 105;};
    data[9] = [](long double x) {return pow(x, 9) - 36 * pow(x, 7) + 378 * pow(x, 5) - 1260 * pow(x, 3) +  945 * x;};
}
double polinoms::getValue(const std::array<int, 3> & tens, const arma::rowvec & x) {
    double ans = 1;
    for (int i = 0; i < 3; i++) {
        ans *= data[tens[i]](x[i]);
    }
    return ans;
}

std::vector<std::array<int, 3>> combineProduct(int N) {
    std::vector<std::array<int, 3>> combinations;
    for (int i = 0; i <= N; i++){
        for (int j = 0; j <= N; j++){
            int k = N - i - j;
            if (k >= 0){
                combinations.push_back({i, j, k});
            }
        }
    }
    return combinations;
}

arma::vec generator(cube & s){
    polinoms p;
    std::vector<std::vector<double>> tmpA;
    auto sCoords = s.get();
    for(int i = 0; i < 10; i++) {
        auto outComb = combineProduct(i);
        for (auto tens : outComb) {
            std::vector<double> a;
            a.resize(s._lvlCount + 1);
            std::fill(a.begin(), a.end(), 0.0);
            for(int k = 0; k < s._lvlCount; k++) {
                for(int l = 4 * k; l < 8 * k + 4 * (1 - k); l++){
                    a[k] += p.getValue(tens, sCoords.row(l));
                }
            }
            a[2] = p.getValue(tens, arma::rowvec3({0.0 ,0.0, 0.0}));
            tmpA.push_back(a);
        }
    }
    int rank = 0;
    
    arma::Mat<double> A(tmpA.size(), s._lvlCount + 1, arma::fill::zeros);
    arma::Mat<double> B(tmpA.size(), s._lvlCount + 1, arma::fill::zeros);
    
    for(int i = 0; i< tmpA.size(); i++) {
        B.row(i) = arma::trans(arma::vec3({tmpA[i][0], tmpA[i][1], tmpA[i][2]}));
        if(arma::rank(B) > arma::rank(A)) {
            A.row(rank) = arma::trans(arma::vec3({tmpA[i][0], tmpA[i][1], tmpA[i][2]}));
            rank++;
        }
    }
    A.resize(rank, s._lvlCount + 1);
    arma::vec F(rank, arma::fill::zeros);
    F[0] = 1.0;
    
    auto w = arma::solve(A, F);
    return w;
    
}
arma::vec generator(tetrahedron & s) {
    polinoms p;
    std::vector<std::vector<double>> tmpA;
    auto sCoords = s.get();
    for(int i = 0; i < 10; i++) {
        auto outComb = combineProduct(i);
        for (auto tens : outComb) {
            std::vector<double> a;
            a.resize(s._lvlCount + 1);
            std::fill(a.begin(), a.end(), 0.0);
            a[0] = p.getValue(tens, sCoords.row(3));
            for(int l = 0; l < 3; l++){
                a[1] += p.getValue(tens, sCoords.row(l));
            }
            a[2] = p.getValue(tens, arma::rowvec3({0.0 ,0.0, 0.0}));
            tmpA.push_back(a);
        }
    }
    int rank = 0;
    arma::Mat<double> A(tmpA.size(), s._lvlCount + 1, arma::fill::zeros);
    arma::Mat<double> B(tmpA.size(), s._lvlCount + 1, arma::fill::zeros);
    
    for(int i = 0; i< tmpA.size(); i++) {
        B.row(i) = arma::trans(arma::vec3({tmpA[i][0], tmpA[i][1], tmpA[i][2]}));
        if(arma::rank(B) > arma::rank(A)) {
            A.row(rank) = arma::trans(arma::vec3({tmpA[i][0], tmpA[i][1], tmpA[i][2]}));
            rank++;
        }
    }
    A.resize(rank, s._lvlCount + 1);
    arma::vec F(rank, arma::fill::zeros);
    F[0] = 1.0;
    
    auto w = arma::solve(A, F);
    
    return w;
}

arma::vec generator(octahedron & s) {
    polinoms p;
    std::vector<std::vector<double>> tmpA;
    auto sCoords = s.get();
    for(int i = 0; i < 10; i++) {
        auto outComb = combineProduct(i);
        for (auto tens : outComb) {
            std::vector<double> a;
            a.resize(s._lvlCount + 1);
            std::fill(a.begin(), a.end(), 0.0);
            for(int l = 0; l < 2; l++) {
                a[0] += p.getValue(tens, sCoords.row(l));
            }
            for(int l = 3; l < 5; l++){
                a[0] += p.getValue(tens, sCoords.row(l));
            }
            a[1] = p.getValue(tens, sCoords.row(2));
            a[2] = p.getValue(tens, sCoords.row(5));
            a[3] = p.getValue(tens, arma::rowvec3({0.0, 0.0, 0.0}));
            
            tmpA.push_back(a);
        }
    }
    int rank = 0;
    arma::Mat<double> A(tmpA.size(), s._lvlCount + 1, arma::fill::zeros);
    arma::Mat<double> B(tmpA.size(), s._lvlCount + 1, arma::fill::zeros);
    
    for(int i = 0; i< tmpA.size(); i++) {
        B.row(i) = arma::trans(arma::vec4({tmpA[i][0], tmpA[i][1], tmpA[i][2], tmpA[i][3]}));
        if(arma::rank(B) > arma::rank(A)) {
            A.row(rank) = arma::trans(arma::vec4({tmpA[i][0], tmpA[i][1], tmpA[i][2], tmpA[i][3]}));
            rank++;
        }
    }
    A.resize(rank, s._lvlCount + 1);
    arma::vec F(rank, arma::fill::zeros);
    F[0] = 1.0;
    
    auto w = arma::solve(A, F);
    
    return w;
}

arma::vec generator(icosahedron & s) {
    polinoms p;
    std::vector<std::vector<double>> tmpA;
    auto sCoords = s.get();
    for(int i = 0; i < 10; i++) {
        auto outComb = combineProduct(i);
        for (auto tens : outComb) {
            std::vector<double> a;
            a.resize(s._lvlCount + 1);
            std::fill(a.begin(), a.end(), 0.0);
            a[0] = p.getValue(tens, sCoords.row(0));
            for(int l = 1; l < 6; l++) {
                a[1] += p.getValue(tens, sCoords.row(l));
            }
            for(int l = 6; l < 11; l++){
                a[2] += p.getValue(tens, sCoords.row(l));
            }
            a[3] = p.getValue(tens, sCoords.row(11));
            a[4] = p.getValue(tens, arma::rowvec3({0.0, 0.0, 0.0}));
            
            tmpA.push_back(a);
        }
    }
    int rank = 0;
    arma::Mat<double> A(tmpA.size(), s._lvlCount + 1, arma::fill::zeros);
    arma::Mat<double> B(tmpA.size(), s._lvlCount + 1, arma::fill::zeros);
    
    for(int i = 0; i< tmpA.size(); i++) {
        B.row(i) = arma::trans(arma::vec5({tmpA[i][0], tmpA[i][1], tmpA[i][2], tmpA[i][3], tmpA[i][4]}));
        if(arma::rank(B) > arma::rank(A)) {
            A.row(rank) = arma::trans(arma::vec5({tmpA[i][0], tmpA[i][1], tmpA[i][2], tmpA[i][3], tmpA[i][4]}));
            rank++;
        }
    }
    A.resize(rank, s._lvlCount + 1);
    arma::vec F(rank, arma::fill::zeros);
    F[0] = 1.0;
    
    auto w = arma::solve(A, F);
    
    return w;
}
//D3Q27
arma::vec D3Q27Generator(cube & c, octahedron & o, cubeEdgeCenters & cc) {
    polinoms p;
    std::vector<std::vector<double>> tmpA;
    auto cubeCoords = c.get();
    auto octCoords = o.get();
    auto cenCubeCoords = cc.get();
    for(int i = 0; i < 10; i++) {
        auto outComb = combineProduct(i);
        for (auto tens : outComb) {
            std::vector<double> a;
            a.resize(4);
            std::fill(a.begin(), a.end(), 0.0);
            for(int l = 0; l < c._vertexCount; l++){
                a[0] += p.getValue(tens, cubeCoords.row(l));
            }
            for(int l = 0; l < o._vertexCount; l++) {
                a[1] += p.getValue(tens, octCoords.row(l));
            }
            for(int l = 0; l < cc._vertexCount; l++) {
                a[2] += p.getValue(tens, cenCubeCoords.row(l));
            }
            a[3] = p.getValue(tens, arma::rowvec3({0.0, 0.0, 0.0}));
            
            tmpA.push_back(a);
        }
    }
    
    int rank = 0;
    arma::Mat<double> A(tmpA.size(), 4, arma::fill::zeros);
    for(int i = 0; i < tmpA.size(); i++) {
        A.row(rank) = arma::rowvec4({tmpA[i][0], tmpA[i][1], tmpA[i][2], tmpA[i][3]});
        if(arma::rank(A) > rank) {
            rank++;
        }
    }
    A.resize(rank, 4);
    arma::vec F(rank, arma::fill::zeros);
    F[0] = 1.0;
    auto w = arma::solve(A, F);
    
    return w;
}
//D3Q19
arma::vec D3Q19Generator(octahedron & o, cubeEdgeCenters & cc) {
    polinoms p;
    std::vector<std::vector<double>> tmpA;
    auto octCoords = o.get();
    auto cenCubeCoords = cc.get();
    for(int i = 0; i < 5; i++) {
        auto outComb = combineProduct(i);
        for (auto tens : outComb) {
            std::vector<double> a;
            a.resize(3);
            std::fill(a.begin(), a.end(), 0.0);
            for(int l = 0; l < o._vertexCount; l++) {
                a[0] += p.getValue(tens, octCoords.row(l));
            }
            for(int l = 0; l < cc._vertexCount; l++) {
                a[1] += p.getValue(tens, cenCubeCoords.row(l));
            }
            a[2] = p.getValue(tens, arma::rowvec3({0.0, 0.0, 0.0}));
            tmpA.push_back(a);
        }
    }
    
    int rank = 0;
    int k = 0;
    arma::Mat<double> A(tmpA.size(), 3, arma::fill::zeros);
    arma::Mat<double> B(tmpA.size(), 3, arma::fill::zeros);
    for(int i = 0; i < tmpA.size(); i++) {
        if((tmpA[i][0] == tmpA[i][1]) && (tmpA[i][2] == tmpA[i][1]) && (tmpA[i][0] == 0.0)){
            continue;
        } else {
            B.row(k) = arma::rowvec3({tmpA[i][0], tmpA[i][1], tmpA[i][2]});
            A.row(rank) = arma::rowvec3({tmpA[i][0], tmpA[i][1], tmpA[i][2]});
            if(arma::rank(A) > rank) {
                rank++;
            }
            k++;
        }
    }
    B.resize(k, 3);
    A.resize(rank, 3);
    arma::vec F(rank, arma::fill::zeros);
    F[0] = 1.0;
    auto w = arma::solve(A, F);
    
    return w;
}
//D3Q15
arma::vec D3Q15Generator(cube & c, octahedron & o) {
    polinoms p;
    std::vector<std::vector<double>> tmpA;
    auto octCoords = o.get();
    auto cubeCoords = c.get();
    for(int i = 0; i < 5; i++) {
        auto outComb = combineProduct(i);
        for (auto tens : outComb) {
            std::vector<double> a;
            a.resize(3);
            std::fill(a.begin(), a.end(), 0.0);
            for(int l = 0; l < o._vertexCount; l++) {
                a[0] += p.getValue(tens, octCoords.row(l));
            }
            for(int l = 0; l < c._vertexCount; l++) {
                a[1] += p.getValue(tens, cubeCoords.row(l));
            }
            a[2] = p.getValue(tens, arma::rowvec3({0.0, 0.0, 0.0}));
            tmpA.push_back(a);
        }
    }
    int rank = 0;
    int k = 0;
    arma::Mat<double> A(tmpA.size(), 3, arma::fill::zeros);
    arma::Mat<double> B(tmpA.size(), 3, arma::fill::zeros);
    for(int i = 0; i < tmpA.size(); i++) {
        if((tmpA[i][0] == tmpA[i][1]) && (tmpA[i][2] == tmpA[i][1]) && (tmpA[i][0] == 0.0)){
            continue;
        } else {
            B.row(k) = arma::rowvec3({tmpA[i][0], tmpA[i][1], tmpA[i][2]});
            A.row(rank) = arma::rowvec3({tmpA[i][0], tmpA[i][1], tmpA[i][2]});
            if(arma::rank(A) > rank) {
                rank++;
            }
            k++;
        }
    }
    B.resize(k, 3);
    A.resize(rank, 3);
    arma::vec F(rank, arma::fill::zeros);
    F[0] = 1.0;
    auto w = arma::solve(A, F);
    
    return w;
    
}
//D3Q39
arma::vec D3Q39Generator(octahedron & o1, cube & c, octahedron & o2, cubeEdgeCenters & cc, octahedron & o3){
    polinoms p;
    std::vector<std::vector<double>> tmpA;
    auto oct1Coords = o1.get();
    auto cubeCoords = c.get();
    auto oct2Coords = o2.get();
    auto ccCoords = cc.get();
    auto oct3Coords = o3.get();
    for(int i = 0; i < 10; i++) {
        auto outComb = combineProduct(i);
        for (auto tens : outComb) {
            std::vector<double> a;
            a.resize(6);
            std::fill(a.begin(), a.end(), 0.0);
            a[0] = p.getValue(tens, arma::rowvec3({0.0, 0.0, 0.0}));
            for(int l = 0; l < o1._vertexCount; l++) {
                a[1] += p.getValue(tens, oct1Coords.row(l));
            }
            for(int l = 0; l < c._vertexCount; l++) {
                a[2] += p.getValue(tens, cubeCoords.row(l));
            }
            for(int l = 0; l < o2._vertexCount; l++) {
                a[3] += p.getValue(tens, oct2Coords.row(l));
            }
            for(int l = 0; l < cc._vertexCount; l++) {
                a[4] += p.getValue(tens, ccCoords.row(l));
            }
            for(int l = 0; l < o3._vertexCount; l++) {
                a[5] += p.getValue(tens, oct3Coords.row(l));
            }
            tmpA.push_back(a);
        }
    }
    int rank = 0;
    int k = 0;
    arma::Mat<double> A(tmpA.size(), 6, arma::fill::zeros);
    arma::Mat<double> B(tmpA.size(), 6, arma::fill::zeros);
    for(int i = 0; i < tmpA.size(); i++) {
        A.row(rank) = arma::rowvec({tmpA[i][0], tmpA[i][1], tmpA[i][2], tmpA[i][3], tmpA[i][4], tmpA[i][5]});
        if(arma::rank(A) > rank) {
            rank++;
        }
    }
    B.resize(k, 6);
    A.resize(rank, 6);
    arma::vec F(rank, arma::fill::zeros);
    F[0] = 1.0;
    auto w = arma::solve(A, F);
    return w;
}


unsigned long long bcl(int n, int k) {
    if (k>n/2) k=n-k;
    if (k==1)  return n;
    if (k==0)  return 1;
    unsigned long long r;
    if (n+k>=90) {
        r=bcl(n-1,k);
        r+=+bcl(n-1,k-1);
    }
    else {
        r=1;
        for (int i=1; i<=k;++i) {
            r*=n-k+i;
            r/=i;
        }
    }
    return r;
}



std::shared_ptr<solid> solidFabric(int type, double p){
    switch (type) {
        case 0:
            return std::shared_ptr<octahedron>(new octahedron(p));
        case 1:
            return std::shared_ptr<cube>(new cube(p));
        case 2:
            return std::shared_ptr<cubeEdgeCenters>(new cubeEdgeCenters(p));
        case 3:
            return std::shared_ptr<icosahedron>(new icosahedron(p));
    }
    return nullptr;
}
 //0 - octahedron

arma::vec customGenerator(std::vector<std::tuple<int, double>> &p) {
    polinoms pol;
    std::vector<std::vector<double>> tmpA;
    for(int i = 0; i < 10; i++) {
        auto outComb = combineProduct(i);
        for (auto tens : outComb) {
            std::vector<double> w;
            w.resize(p.size() + 1);
            std::fill(w.begin(), w.end(), 0.0);
            w[0] = pol.getValue(tens, arma::rowvec3(arma::fill::zeros));
            for(int k = 0; k < p.size(); k++) {
                auto obj = solidFabric(std::get<0>(p[k]), std::get<1>(p[k]));
                auto objCoords = obj->get();
                for(int l = 0; l < obj->_vertexCount; l++) {
                    w[k + 1] += pol.getValue(tens, objCoords.row(l));
                }
            }
            tmpA.push_back(w);
        }
    }
    int rank = 0;
    arma::Mat<double> A(tmpA.size(), p.size() + 1, arma::fill::zeros);
    for(int i = 0; i < tmpA.size(); i++) {
        arma::rowvec curRow(p.size() + 1, arma::fill::zeros);
        for(int j = 0; j < p.size() + 1; j++) {
            curRow[j] = tmpA[i][j];
        }
        A.row(rank) = curRow;
        if(arma::rank(A) > rank) {
            rank++;
        }
    }
    A.resize(rank, p.size() + 1);
    arma::vec F(rank, arma::fill::zeros);
    F[0] = 1.0;
    auto w = arma::solve(A, F);
    return w;
}

