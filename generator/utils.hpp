//
//  utils.hpp
//  generator
//
//  Created by German Zvezdin on 05.11.2021.
//

#include "polygon.hpp"
template<int dim>
void cudaGenerator(arma::vec &w, std::vector<solid> & objects){
    int vertexCount = 0;
        for(int i = 0; i < objects.size(); i++){
            vertexCount += objects[i]._vertexCount;
        }
        printf("#define DIM %d\n", dim);
        printf("const int Nq = %d, NQ = Nq+1;\n", vertexCount + 1);
        printf("__device__ const ftype3 ciq[] = \n");
        printf("{{0.0, 0.0, 0.0},\n");
        for(int i = 0; i < objects.size(); i++){
            auto objCoords = objects[i].get();
            for(int j = 0; j < objects[i]._vertexCount; j++) {
                printf("{%1.15lf, %1.15lf, %1.15lf},\n", objCoords.row(j)[0], objCoords.row(j)[1], objCoords.row(j)[2]);
            }
        }
        printf("};\n");
        
        for(int i = 0; i < objects.size() + 1; i++) {
            printf("double w%d = %1.15lf;\n", i, w[i]);
        }
        printf("__device__ const ftype wiq[] = {w0, ");
        for(int i = 0; i < objects.size(); i++){
            for(int j = 0; j < objects[i]._vertexCount; j++) {
                printf("w%d, ", i + 1);
            }
        }
        printf("\n};\n");
}

std::vector<arma::vec3> cartesianProduct(std::vector<double> & inp);
