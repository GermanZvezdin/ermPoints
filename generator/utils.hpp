//
//  utils.hpp
//  generator
//
//  Created by German Zvezdin on 05.11.2021.
//

#include "polygon.hpp"
void D3Q39(double r);
void D3Q27(double r = 2.0 * sqrt(3), double s = 2.0 * sqrt(3), double t = 2.0 * sqrt(3));
void D3Q15(double r);
template<int dim>
void cudaGenerator(arma::vec &w, std::vector<std::tuple<int, double, std::optional<int>>> &p){
    int vertexCount = 0;
    for(int i = 0; i < p.size(); i++){
        auto obj = solidFabric(std::get<0>(p[i]), std::get<1>(p[i]), std::get<2>(p[i]));
        vertexCount += obj->_vertexCount;
    }
    printf("#define DIM %d\n", dim);
    printf("const int Nq = %d, NQ = Nq+1;\n", vertexCount + 1);
    if(dim != 1) {
        printf("__device__ const ftype%d ciq[] = \n", dim);
        printf("{{");
        for(int i = 0; i < dim - 1; i++){
            printf("0.0, ");
        }
        printf("0.0},\n");
        for(int i = 0; i < p.size(); i++){
            auto obj = solidFabric(std::get<0>(p[i]), std::get<1>(p[i]), std::get<2>(p[i]));
            auto objCoords = obj->get();
            for(int j = 0; j < obj->_vertexCount; j++) {
                printf("{");
                for(int k = 0; k < dim - 1; k++){
                    printf("%1.15lf, ", objCoords.row(j)[k]);
                }
                printf("%1.15lf},\n", objCoords.row(j)[dim - 1]);
            }
        }
        printf("};\n");
    } else {
        printf("__device__ const ftype ciq[] = \n");
        printf("{");
        for(int i = 0; i < dim; i++){
            printf("0.0, ");
        }
        for(int i = 0; i < p.size(); i++){
            auto obj = solidFabric(std::get<0>(p[i]), std::get<1>(p[i]), std::get<2>(p[i]));
            auto objCoords = obj->get();
            for(int j = 0; j < obj->_vertexCount; j++) {
                for(int k = 0; k < dim; k++){
                    printf("%1.15lf, ", objCoords.row(j)[k]);
                }
            }
        }
        printf("};\n");
    }
    for(int i = 0; i < p.size() + 1; i++) {
        printf("double w%d = %1.15lf;\n", i, w[i]);
    }
    printf("__device__ const ftype wiq[] = {w0, ");
    for(int i = 0; i < p.size(); i++){
        auto obj = solidFabric(std::get<0>(p[i]), std::get<1>(p[i]), std::get<2>(p[i]));
        for(int j = 0; j < obj->_vertexCount; j++) {
            printf("w%d, ", i + 1);
        }
    }
    printf("\n};\n");
}
