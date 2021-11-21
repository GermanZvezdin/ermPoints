//
//  utils.cpp
//  generator
//
//  Created by German Zvezdin on 05.11.2021.
//

#include "utils.hpp"

std::vector<arma::vec3> сartesianProduct(std::vector<double> & inp) {
    std::vector<arma::vec3> ans;
    for(int i = 0; i < inp.size(); i++){
        for(int j = 0; j < inp.size(); j++){
            ans.push_back({inp[i], inp[j], 0.0});
        }
    }
    return ans;
}

