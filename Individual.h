//
// Created by Ionic on 3/4/17.
//

#ifndef CEC13CCODE_2_INDIVIDUAL_H
#define CEC13CCODE_2_INDIVIDUAL_H

#include <vector>

using namespace std;

struct Individual {

    vector<double> value;
    double fitness;

    Individual() = default;
    Individual(const vector<double> &value, double fitness);

    bool operator<(const Individual &rhs) const;
    bool operator>(const Individual &rhs) const;
};

Individual operator+(const Individual &lhs, const Individual &rhs);

Individual operator-(const Individual &lhs, const Individual &rhs);

Individual operator*(const Individual &lhs, const double rhs);

Individual operator*(const double lhs, const Individual &rhs);

#endif //CEC13CCODE_2_INDIVIDUAL_H
