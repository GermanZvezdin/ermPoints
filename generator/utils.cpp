//
//  utils.cpp
//  generator
//
//  Created by German Zvezdin on 05.11.2021.
//

#include "utils.hpp"

std::vector<std::array<long double, 3>> cartesianProduct(std::vector<long double> & inp) {
    std::vector<std::array<long double, 3>> ans;
    for(int i = 0; i < inp.size(); i++){
        for(int j = 0; j < inp.size(); j++){
            ans.push_back({inp[i], inp[j], 0.0});
        }
    }
    return ans;
}

double distance(std::array<long double, 3> a) {
    return sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
}

std::vector<solid> makeSolid(std::vector<long double> & data) {
    
    auto combine2d = cartesianProduct(data);
    
    std::vector<solid> s = {};
    std::map<long double, std::vector<std::array<long double, 3>>> sCoords;
    
    for(auto i : combine2d) {
        sCoords[distance(i)].push_back(i);
    }
    
    for(auto i = sCoords.begin(); i != sCoords.end(); i++) {
        customFigure cf(i->second.size(), i->second);
        /*std::cout << i->second.size() << std::endl;
        for(int j = 0; j < i->second.size(); j++) {
            std::cout << i->second[j][0] << " " <<  i->second[j][1] << " " <<  i->second[j][2] << std::endl;
        }*/
        s.push_back(cf);
    }
    
    return s;
}

