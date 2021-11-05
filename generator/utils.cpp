//
//  utils.cpp
//  generator
//
//  Created by German Zvezdin on 05.11.2021.
//

#include "utils.hpp"
void D3Q39(double r){
    r *= 2.0;
    cube c(r);
    cubeEdgeCenters cc(2.0 * r);
    octahedron o1(r), o2(2.0 * r), o3(3.0 * r);
    auto w = D3Q39Generator(o1, c, o2, cc, o3);
    printf("#define DIM 3\n");
    printf("const int Nq = 38, NQ = Nq+1;\n");
    printf("device const ftype3 ciq[] = \n");
    printf("{{0.0, 0.0, 0.0},\n");
    for(int i = 0; i < 6; i++) {
        printf("{%1.15lf, %1.15lf, %1.15lf},\n",o1.get().row(i)[0], o1.get().row(i)[1], o1.get().row(i)[2]);
    }
    for(int i = 0; i < 8; i++) {
        printf("{%1.15lf, %1.15lf, %1.15lf},\n",c.get().row(i)[0], c.get().row(i)[1], c.get().row(i)[2]);
    }
    for(int i = 0; i < 6; i++) {
        printf("{%1.15lf, %1.15lf, %1.15lf},\n",o2.get().row(i)[0], o2.get().row(i)[1], o2.get().row(i)[2]);
    }
    for(int i = 0; i < 12; i++) {
        printf("{%1.15lf, %1.15lf, %1.15lf},\n",cc.get().row(i)[0], cc.get().row(i)[1], cc.get().row(i)[2]);
    }
    for(int i = 0; i < 6; i++) {
        printf("{%1.15lf, %1.15lf, %1.15lf},\n",o3.get().row(i)[0], o3.get().row(i)[1], o3.get().row(i)[2]);
    }
    printf("};\n");
    for(int i = 0; i < w.size(); i++) {
        printf("double w%d = %1.15lf;\n",i, w[i]);
    }
    printf("device const ftype wiq[] = {w0, ");
    for(int i = 0; i < 6; i++) {
        printf("w1, ");
    }
    for(int i = 0; i < 8; i++) {
        printf("w2, ");
    }
    for(int i = 0; i < 6; i++) {
        printf("w3, ");
    }
    for(int i = 0; i < 12; i++) {
        printf("w4, ");
    }
    for(int i = 0; i < 6; i++) {
        printf("w5, ");
    }
    printf("\n};\n");
}
void D3Q27(double r, double s, double t) {
    cube c(t);
    octahedron o(r);
    cubeEdgeCenters cc(s);
    auto w = D3Q27Generator(c, o, cc);
    printf("#define DIM 3\n");
    printf("const int Nq = 26, NQ = Nq+1;\n");
    printf("device const ftype3 ciq[] = \n");
    printf("{{0.0, 0.0, 0.0},\n");
    for(int i = 0; i < 6; i++) {
        printf("{%1.15lf, %1.15lf, %1.15lf},\n",o.get().row(i)[0], o.get().row(i)[1], o.get().row(i)[2]);
    }
    for(int i = 0; i < 12; i++) {
        printf("{%1.15lf, %1.15lf, %1.15lf},\n",cc.get().row(i)[0], cc.get().row(i)[1], cc.get().row(i)[2]);
    }
    for(int i = 0; i < 8; i++) {
        printf("{%1.15lf, %1.15lf, %1.15lf},\n",c.get().row(i)[0], c.get().row(i)[1], c.get().row(i)[2]);
    }
    printf("};\n");
    
    printf("double w0 = %1.15lf;\n",w[3]); //0 0 0
    printf("double w1 = %1.15lf;\n",w[1]); // oct
    printf("double w2 = %1.15lf;\n",w[2]); // cc
    printf("double w3 = %1.15lf;\n",w[0]); // c
    
    printf("device const ftype wiq[] = {w0, ");
    for(int i = 0; i < 6; i++) {
        printf("w1, ");
    }
    for(int i = 0; i < 12; i++) {
        printf("w2, ");
    }
    for(int i = 0; i < 8; i++) {
        printf("w3, ");
    }
    printf("\n};\n");
}
void D3Q15(double r) {
    r *= 2.0;
    octahedron o(r);
    cube c(r);
    
    auto w = D3Q15Generator(c, o);
    printf("#define DIM 3\n");
    printf("const int Nq = 26, NQ = Nq+1;\n");
    printf("device const ftype3 ciq[] = \n");
    printf("{{0.0, 0.0, 0.0},\n");
    for(int i = 0; i < 6; i++) {
        printf("{%1.15lf, %1.15lf, %1.15lf},\n", o.get().row(i)[0], o.get().row(i)[1], o.get().row(i)[2]);
    }
    for(int i = 0; i < 8; i++) {
        printf("{%1.15lf, %1.15lf, %1.15lf},\n",c.get().row(i)[0], c.get().row(i)[1], c.get().row(i)[2]);
    }
    printf("};\n");
    
    printf("double w0 = %1.15lf;\n",w[2]); //0 0 0
    printf("double w1 = %1.15lf;\n",w[0]); // oct
    printf("double w2 = %1.15lf;\n",w[1]); // c
    
    printf("device const ftype wiq[] = {w0, ");
    for(int i = 0; i < 6; i++) {
        printf("w1, ");
    }
    for(int i = 0; i < 8; i++) {
        printf("w2, ");
    }
    printf("\n};\n");
    
}
