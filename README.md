# ermPoints
A program for finding coefficients of the Hermite interpolation polynomial
If cmake doesn't work, try:
- g++ polygon.hpp polygon.cpp utils.cpp utils.hpp main.cpp -O2 -std=c++17 -larmadillo
# To install armadillo:
- http://arma.sourceforge.net/download.html
# HOW TO USE
 - Create a vector of the following type: 
 ```c++
std::vector<std::tuple<int, double, std::optional<int>>> p1 = {{0, 1.0, std::nullopt}}; 
 ```
 **Inside this vector are tuples containing the object id and its main parameters.**
 - All 3D objects must have std::nullopt as the third parameter, since they do not parametrize the number of vertices
 - All 2D objects as the third parameter must have a non-negative integer describing the number of vertices.
## Objects id
  - 0 - octahedron <img src="https://user-images.githubusercontent.com/71877725/142726444-ed51259f-00ee-4c46-af57-e988e810dcc0.jpeg" width="100" height="100" /> 
  - 1 - cube <img src="https://user-images.githubusercontent.com/71877725/142726598-48c27af1-d93f-4a98-8913-4aa91e3f9f9e.png" width="100" height="100" />
  - 2 - cubeEdgeCenters <img width="117" alt="Снимок экрана 2021-11-20 в 15 42 15" src="https://user-images.githubusercontent.com/71877725/142726694-602d0d24-63fb-4e17-8538-c1a1be7f494c.png">
  - 3 - icosahedron <img src="https://user-images.githubusercontent.com/71877725/142726747-d31f2a04-564a-49e0-a61c-395bba6ce906.gif" width="100" height="100" />
  - 4 - regular polygons <img src="https://user-images.githubusercontent.com/71877725/142726801-1d9a58ef-c53f-41ba-934a-f9690b421feb.png" width="100" height="100" />
  - 5 - regular points  <img width="317" alt="Снимок экрана 2021-11-20 в 15 51 19" src="https://user-images.githubusercontent.com/71877725/142726946-aa5aebc3-a35f-436e-8a50-b8058b104e40.png">
 
## A simple code example for finding quadrature weights in 3D
### Quadrature D3Q39:
 ```c++
double r = 2.0 * sqrt(3.0 / 2.0);
std::vector<std::tuple<int, double, std::optional<int>>> p1 = {{0, r, std::nullopt}, {1, r, std::nullopt}, {0, 2.0 * r, std::nullopt}, {2, 2.0 * r, std::nullopt}, {0, 3.0 * r, std::nullopt}};
auto w = customGenerator(p1);
```
## A simple code example for finding quadrature weights in 2D
 ```c++
std::vector<std::tuple<int, double, std::optional<int>>> p2 = {{4, 1.0, 4}, {4, 1.0, 10}};
w = customGenerator(p2);
```
## A simple code example for finding quadrature weights in 1D
```c++
std::vector<std::tuple<int, double, std::optional<int>>> p2 = {{5, 1.0, 4}, {5, 1.0, 10}};
w = customGenerator(p2);
```
## If you need to use these weights in another code on CUDA, you can automatically generate it
### FOR 3D:
```c++
std::vector<std::tuple<int, double, std::optional<int>>> p1 = {{0, r, std::nullopt}, {1, r, std::nullopt}, {0, 2.0 * r, std::nullopt}, {2, 2.0 * r, std::nullopt}, {0, 3.0 * r, std::nullopt}};
auto w = customGenerator(p1);
cudaGenerator<3>(w, p1);
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



