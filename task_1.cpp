//
// Created by james on 30/03/2020.
//

#include <iostream>
#include <fstream>
#include "Constituency.h"

std::istream& operator >> (std::istream &in, Constituency &constituency){
    unsigned int len;
    in >> len;
    std::string name;
    std::vector<int> neighbours;
    unsigned int next_num;

    for(unsigned int i = 0; i < len; i++) {
        in >> next_num;
        neighbours.push_back(next_num);
    }

    if (neighbours.size() != len){
        throw std::logic_error("Missing neighbours for that constituency");
    }

    in >> name;

    if (name.empty()){
        throw std::logic_error("Name not present for that constituency");
    }

    constituency = Constituency(name, neighbours);
    return in;
}

int main(int argc, char *argv[]){
    std::ifstream inputFile("wales.graph");
    if (!inputFile.is_open()){
        return 1;
    }

    int expected_constituencies;
    inputFile >> expected_constituencies;

    std::cout << "expected_constituencies = "
              << expected_constituencies << std::endl;

    Constituency constituency;
    inputFile >> constituency;

    std::cout << constituency.get_name();
    for (auto &neighbour : constituency.get_neighbours()){
        std::cout << ", " << neighbour;
    }
    std::cout << std::endl;

    return 0;
}
