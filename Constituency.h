//
// Created by james on 30/03/2020.
//

#ifndef LAB7_CONSTITUENCY_H
#define LAB7_CONSTITUENCY_H
#include <vector>


class Constituency {
private:
    std::vector<int> neighbours;
    std::string name;

public:
    Constituency() = default;
    Constituency(const std::string &name, const std::vector<int> &neighbours);

    const std::string& get_name() const;
    const std::vector<int>& get_neighbours() const;
};

#endif //LAB7_CONSTITUENCY_H
