//
// Created by james on 30/03/2020.
//

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
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

    in >> name;

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

    typedef std::istream_iterator<Constituency> istream_iterator;
    std::vector<Constituency> constituencies(expected_constituencies);
    std::copy(istream_iterator(inputFile), istream_iterator(), std::back_inserter(constituencies));

    for (auto & constituency : constituencies){
        std::cout << constituency.get_name();
        for (auto &neighbour : constituency.get_neighbours()){
            std::cout << ", " << neighbour;
        }
        std::cout << std::endl;
    }

    return 0;
}