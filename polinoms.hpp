//
// Created by German Zvezdin on 14.10.2021.
//

#ifndef ERMITS_FUNCTION_POLINOMS_HPP
#define ERMITS_FUNCTION_POLINOMS_HPP
#pragma once
#include <array>
#include <functional>
#include <cmath>
#include <iostream>
#include <vector>
#define ARMA_USE_LAPACK
#define ARMA_USE_BLAS
#define ARMA_USE_ARPACK
#define ARMA_USE_SUPERLU
#include <armadillo>
//#define DEBUG


class polinoms {
    std::array<std::function<double(long double x)>, 10> data;

public:
    polinoms();
    template <const int dim>
    long double getValue(const std::array<int, dim> & tens, const std::array<long double, dim> & x) {

        long double ans = 1;

        for (int i = 0; i < dim; i++) {
            ans *= data[tens[i]](x[i]);
        }

        return ans;
    }

};


template<const int dim>
void getComb(int num, std::vector<std::array<int, dim> > & out, int len = 0, int s = 1) {

    static std::vector<int> a;

    if (a.size() <= num) {
        a.resize(num);
    }

    if (num <= 0) {
        std::array<int, dim> ans;

        for (int j = 0; j < len; j++) {
            if (len > dim) {
                return;
            }
            ans[j] = a[j];
        }

        for (int j = len; j < dim; j++) {
            ans[j] = 0;
        }
        out.push_back(ans);

        return;
    }

    for (int i = s; i <= num; i++) {
        a[len] = i;
        getComb<dim>(num - i, out, len + 1, i);
    }
}

constexpr long double delta(const int x) {
    return x == 0 ? 1 : 0;
}




template<const int D, const int Q, const int N>
void cGenerator(std::array<std::array<long double, D>, Q> && inp) {
    polinoms pol;
    std::vector<std::array<long double, Q>> A;
    std::vector<double> F;


    std::vector<std::array<int, D> > out;
    std::array<long double, Q> row;

    for (int i = 0; i < N; i++) {
        getComb<D>(i, out);
        for (auto tens : out) {
            for (int j = 0; j < Q; j++) {
                row[j] = pol.getValue<D>(tens, inp[j]);
            }
#ifdef DEBUG
            printf("----------i = %d-------------\n",i);
            for(int j = 0; j < D; j++) {
                std::cout << tens[j] << " ";
            }
            std::cout << std::endl;
            for (int j = 0; j < Q; j++) {
                std::cout << row[j] << " ";
            }
            std::cout << std::endl;
            for (int j = 0; j < Q; j++) {
                for(int k = 0; k < D; k++) {
                    std::cout << inp[j][k] << " ";
                }
                std::cout << std::endl;
            }

            printf("\n-----------------------\n");
#endif
            A.push_back(row);
            F.push_back(delta(i));
        }
        out.resize(0);
    }
#ifdef DEBUG

    std::cout << A.size() << std::endl;

    for (auto i : A) {
        for (auto j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }

    for(auto i : F) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
#endif

    arma::mat _A(A.size(), Q, arma::fill::zeros);
    arma::vec _F(F.size(), arma::fill::zeros);

    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < Q; j++) {
           _A(i, j) = A[i][j];
        }
        _F(i) = F[i];
    }

    arma::vec X;
    arma::solve(X, _A, _F);

    for(auto i : X) {
        std::cout << i<< std::endl;
    }




}



#endif //ERMITS_FUNCTION_POLINOMS_HPP
