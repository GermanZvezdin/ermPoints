# ermPoints
A program for finding coefficients of the Hermite interpolation polynomial
If cmake doesn't work, try:
- g++ polygon.hpp polygon.cpp utils.cpp utils.hpp main.cpp -O2 -std=c++17 -larmadillo
# To install armadillo:
- http://arma.sourceforge.net/download.html
# HOW TO USE
 - Create a vector of the following type: 
 ```c++
std::vector<solid> = {<some solids>};
 ```
## Objects and thire parameters 
  ### Class octahedron <img src="https://user-images.githubusercontent.com/71877725/142726444-ed51259f-00ee-4c46-af57-e988e810dcc0.jpeg" width="100" height="100" /> 
 ```c++
double octahedron_side = 2.0;
octahedron o(octahedron_side);
 ```
  ### Class cube <img src="https://user-images.githubusercontent.com/71877725/142726598-48c27af1-d93f-4a98-8913-4aa91e3f9f9e.png" width="100" height="100" />
 ```c++
double cube_side = 2.0;
cube c(octahedron_side);
 ```
  ### Class cubeEdgeCenters <img width="117" alt="Снимок экрана 2021-11-20 в 15 42 15" src="https://user-images.githubusercontent.com/71877725/142726694-602d0d24-63fb-4e17-8538-c1a1be7f494c.png">
   ```c++
double cubeEdgeCenters_side = 2.0;
cubeEdgeCenters cc(cubeEdgeCenters_side);
 ```
  ### Class icosahedron <img src="https://user-images.githubusercontent.com/71877725/142726747-d31f2a04-564a-49e0-a61c-395bba6ce906.gif" width="100" height="100" />
 ```c++
double icosahedron_side = 2.0;
icosahedron i(icosahedron_side);
 ```
 ### Class regular polygons <img src="https://user-images.githubusercontent.com/71877725/142726801-1d9a58ef-c53f-41ba-934a-f9690b421feb.png" width="100" height="100" />
 ```c++
double polygons_side = 2.0;
int side_count = 4;
double rotate_angle = 0;
polygon p(polygons_side, side_count, rotate_angle);
 ```
  ### Class regular points  <img width="317" alt="Снимок экрана 2021-11-20 в 15 51 19" src="https://user-images.githubusercontent.com/71877725/142726946-aa5aebc3-a35f-436e-8a50-b8058b104e40.png">
  ```c++
double distance_between_points = 2.0;
line l(distance_between_points);
 ```
 ### Class custom figure  <img src="https://user-images.githubusercontent.com/71877725/142763015-670172ba-980c-4ce5-92ca-8a1d17a17822.png" width="300" height="100" /> <img src="https://user-images.githubusercontent.com/71877725/142763056-0d8284e6-2a7e-4385-8bfc-9f63105bbf75.png" width="200" height="200" />
 ```c++
double a = 1.0;
double b = 2.0;
int vertex_count = 8;
std::vector<arma::vec3> vertex_coords = {
        {-a, -b, 0.0}, {-a, b, 0.0}, {a, -b, 0.0}, {a, b, 0.0},
        {-b, -a, 0.0}, {-b, a, 0.0}, {b, -a, 0.0}, {b, a, 0.0}};
        
customFigure cf(vertex_count, vertex_coords);
 ```
 
## A simple code example for finding quadrature weights in 3D
### Quadrature D3Q39:
 ```c++
double r = 2.0 * sqrt(3.0 / 2.0);
octahedron o1(r), o2(2.0 * r), o3(3.0 * r);
cube c(r);
cubeEdgeCenters cc(2.0 * r);
std::vector<solid> ss = {o1, c, o2, cc, o3};
auto [w, order] = generator<3>(ss);
```
## A simple code example for finding quadrature weights in 2D
 ```c++
auto a = sqrt(2.5 + sqrt(2.5));
auto b = sqrt(2.5 - sqrt(2.5));
std::vector<arma::vec3> data = {
    {-a, -b, 0.0}, {-a, b, 0.0}, {a, -b, 0.0}, {a, b, 0.0},
    {-b, -a, 0.0}, {-b, a, 0.0}, {b, -a, 0.0}, {b, a, 0.0}};

customFigure f1(8, data);
polygon s1(2.0 * a / sqrt(2), 4, 0), s2(2.0 * a, 4, M_PI / 4.0), s3(2.0 * b / sqrt(2), 4, 0),
s4(2.0 * b, 4, M_PI / 4.0);

std::vector<solid> s = {s1, s2, s3, s4, f1};
auto [w, order] = generator<2>(s);
```
## A simple code example for finding quadrature weights in 1D
```c++
line l(1.0);
std::vector<solid> ss = {l};
auto [w, order] = generator<1>(ss);
```
## If you need to use these weights in another code on CUDA, you can automatically generate it
### FOR 3D:
```c++
double r = 2.0 * sqrt(3.0 / 2.0);
octahedron o1(r), o2(2.0 * r), o3(3.0 * r);
cube c(r);
cubeEdgeCenters cc(2.0 * r);
std::vector<solid> ss = {o1, c, o2, cc, o3};
auto [w, order] = generator<3>(ss);
cudaGenerator<3>(w, ss);
```
**The template parameter characterizes the dimension you need!**
#### Output:
```cuda
#define DIM 3
const int Nq = 39, NQ = Nq+1;
__device__ const ftype3 ciq[] = 
{{0.0, 0.0, 0.0},
{1.224744871391589, 0.000000000000000, 0.000000000000000},
{0.000000000000000, 1.224744871391589, 0.000000000000000},
{0.000000000000000, 0.000000000000000, 1.224744871391589},
{-1.224744871391589, 0.000000000000000, 0.000000000000000},
{0.000000000000000, -1.224744871391589, 0.000000000000000},
{0.000000000000000, 0.000000000000000, -1.224744871391589},
{-1.224744871391589, -1.224744871391589, -1.224744871391589},
{-1.224744871391589, 1.224744871391589, -1.224744871391589},
{1.224744871391589, -1.224744871391589, -1.224744871391589},
{1.224744871391589, 1.224744871391589, -1.224744871391589},
{-1.224744871391589, -1.224744871391589, 1.224744871391589},
{-1.224744871391589, 1.224744871391589, 1.224744871391589},
{1.224744871391589, -1.224744871391589, 1.224744871391589},
{1.224744871391589, 1.224744871391589, 1.224744871391589},
{2.449489742783178, 0.000000000000000, 0.000000000000000},
{0.000000000000000, 2.449489742783178, 0.000000000000000},
{0.000000000000000, 0.000000000000000, 2.449489742783178},
{-2.449489742783178, 0.000000000000000, 0.000000000000000},
{0.000000000000000, -2.449489742783178, 0.000000000000000},
{0.000000000000000, 0.000000000000000, -2.449489742783178},
{2.449489742783178, 2.449489742783178, 0.000000000000000},
{2.449489742783178, -2.449489742783178, 0.000000000000000},
{-2.449489742783178, 2.449489742783178, 0.000000000000000},
{-2.449489742783178, -2.449489742783178, 0.000000000000000},
{0.000000000000000, 2.449489742783178, 2.449489742783178},
{0.000000000000000, 2.449489742783178, -2.449489742783178},
{0.000000000000000, -2.449489742783178, 2.449489742783178},
{0.000000000000000, -2.449489742783178, -2.449489742783178},
{2.449489742783178, 0.000000000000000, 2.449489742783178},
{2.449489742783178, 0.000000000000000, -2.449489742783178},
{-2.449489742783178, 0.000000000000000, 2.449489742783178},
{-2.449489742783178, 0.000000000000000, -2.449489742783178},
{3.674234614174767, 0.000000000000000, 0.000000000000000},
{0.000000000000000, 3.674234614174767, 0.000000000000000},
{0.000000000000000, 0.000000000000000, 3.674234614174767},
{-3.674234614174767, 0.000000000000000, 0.000000000000000},
{0.000000000000000, -3.674234614174767, 0.000000000000000},
{0.000000000000000, 0.000000000000000, -3.674234614174767},
};
double w0 = 0.083333333333333;
double w1 = 0.083333333333333;
double w2 = 0.037037037037037;
double w3 = 0.014814814814815;
double w4 = 0.002314814814815;
double w5 = 0.000617283950617;
__device__ const ftype wiq[] = {w0, w1, w1, w1, w1, w1, w1, w2, w2, w2, w2, w2, w2, w2, w2, w3, w3, w3, w3, w3, w3, w4, w4, w4, w4, w4, w4, w4, w4, w4, w4, w4, w4, w5, w5, w5, w5, w5, w5, 
};
```



