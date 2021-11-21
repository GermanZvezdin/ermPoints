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

polygon::polygon(int N){
    double R = 1.0 / (2.0 * sin(M_PI / N));
    _lvlCount = 1;
    _vertex = std::shared_ptr<arma::vec3[]>(new arma::vec3[N]);
    _vertexCount = N;
    
    for (int i = 0; i < N; i++) {
        _vertex[i] = {R * cos(2.0 * M_PI * i / N), R * sin(2.0 * M_PI * i / N), 0.0};
    }
}

polygon::polygon(double a, double angle, int N){
    double R = a / (2.0 * sin(M_PI / N));
    _lvlCount = 1;
    _vertex = std::shared_ptr<arma::vec3[]>(new arma::vec3[N]);
    _vertexCount = N;
    
    for (int i = 0; i < N; i++) {
        _vertex[i] = {R * cos(angle + 2.0 * M_PI * i / N),
                      R * sin(angle + 2.0 * M_PI * i / N),
                      0.0};
    }
}
customFigure::customFigure(int vertexCount, std::vector<arma::vec3> &inp) {
    _lvlCount = 1;
    _vertex = std::shared_ptr<arma::vec3[]>(new arma::vec3[vertexCount]);
    _vertexCount = vertexCount;
    
    for(int i = 0; i < vertexCount; i++) {
        _vertex[i] = inp[i];
    }
}


line::line(double a){
    _lvlCount = 1;
    _vertex = std::shared_ptr<arma::vec3[]>(new arma::vec3[2]);
    _vertexCount = 2;
    
    _vertex[0] = {a, 0.0 ,0.0};
    _vertex[1] = {-a, 0.0 ,0.0};
}

int polinoms::get() {
    return data.size();
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
    data[10] = [](long double x){return 1024 * pow(x, 10) - 23040 * pow(x, 8) + 161280 * pow(x, 6) - 403200 * pow(x, 4) + 302400 * pow(x, 2) - 30240;};
    data[11] = [](long double x){return 2048 * pow(x, 11) - 56320 * pow(x, 9) + 506880 * pow(x, 7) - 1774080 * pow(x, 5) + 2217600 * pow(x, 3) - 665280 * x;};
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


std::shared_ptr<solid> solidFabric(int type, double p, std::optional<int> N, std::optional<double> angle){
    switch (type) {
        case 0:
            return std::shared_ptr<octahedron>(new octahedron(p));
        case 1:
            return std::shared_ptr<cube>(new cube(p));
        case 2:
            return std::shared_ptr<cubeEdgeCenters>(new cubeEdgeCenters(p));
        case 3:
            return std::shared_ptr<icosahedron>(new icosahedron(p));
        case 4:
            if (N && angle) {
                return std::shared_ptr<polygon>(new polygon(p, N.value(), angle.value()));
            } else {
                throw std::invalid_argument( "received 2D solid without N" );
                return nullptr;
            }
        case 5:
            return std::shared_ptr<line>(new line(p));
    }
    throw std::invalid_argument("received non-valid object id");
    return nullptr;
}


