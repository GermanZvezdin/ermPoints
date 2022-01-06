//
//  utils.hpp
//  generator
//
//  Created by German Zvezdin on 05.11.2021.
//

#include "polygon.hpp"

template<int dim>
void cudaGenerator(arma::vec &w, std::vector<solid> & objects, int order, std::string fileName = ""){
    int vertexCount = 0;
        for(int i = 0; i < objects.size(); i++){
            vertexCount += objects[i]._vertexCount;
        }
        if (fileName == "") {
            fileName = "CudaTempalte.D" + std::to_string(dim) + "Q" + std::to_string(vertexCount + 1) + ".dat";
        }
        FILE *out;
        FILE *graph;
        std::string graphName = fileName + "graph";
        out = fopen(fileName.c_str(), "w");
        graph = fopen(graphName.c_str(), "w");

        fprintf(out, "//ORDER-%d\n", order);
        fprintf(out, "#define DIM %d\n", dim);
        fprintf(out, "const int Nq = %d, NQ = Nq+1;\n", vertexCount + 1);
        fprintf(out, "__device__ const ftype3 ciq[] = \n");
        fprintf(out, "{{0.0, 0.0, 0.0},\n");
        fprintf(graph, "0.0 0.0 0.0\n");
        for(int i = 0; i < objects.size(); i++){
            auto objCoords = objects[i].get();
            for(int j = 0; j < objects[i]._vertexCount; j++) {
                fprintf(out, "{%1.18lf, %1.18lf, %1.18lf},\n", objCoords.row(j)[0], objCoords.row(j)[1], objCoords.row(j)[2]);
                fprintf(graph, "%1.18lf %1.18lf %1.18lf\n", objCoords.row(j)[0], objCoords.row(j)[1], objCoords.row(j)[2]);
            }
        }
        fprintf(out, "};\n");
        
        for(int i = 0; i < objects.size() + 1; i++) {
            fprintf(out, "double w%d = %1.18lf;\n", i, w[i]);
        }
        fprintf(out, "__device__ const ftype wiq[] = {w0, ");
        for(int i = 0; i < objects.size(); i++){
            for(int j = 0; j < objects[i]._vertexCount; j++) {
                fprintf(out, "w%d, ", i + 1);
            }
        }
        fprintf(out, "\n};\n");
        
        fclose(out);
        fclose(graph);
}

std::vector<std::array<long double, 3>> cartesianProduct(std::vector<long double> & inp);
std::vector<solid> makeSolid(std::vector<long double> & data);

