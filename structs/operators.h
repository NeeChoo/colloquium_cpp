// Copyright 2015 Vadim Bertysh
#ifndef OPERATORS_H
#define OPERATORS_H

#include <iostream>

#include "./struct.h"

std::ostream& operator<<(std::ostream &os, natural &natural) {
    if (natural.order() == 0) {
        os << 0;
    } else {
        int end = natural.order() - 1;
        while (end >= 0) {
            os << (natural[end]);
            end--;
        }
    }
    return os;
}

std::ostream& operator<<(std::ostream &os, integer &integer) {
    if (integer.module.order() == 0) {
        os << 0;
    } else {
        if (!integer.isPositive) os << "-";
        os << integer.module;
    }
    return os;
}

std::ostream& operator<<(std::ostream &os, fraction &fraction) {
    if (fraction.numerator.module.order() == 0) {
        os << 0;
    } else {
        os << fraction.numerator << '/' << fraction.denominator;
    }
    return os;
}

#endif  // OPERATORS_H
