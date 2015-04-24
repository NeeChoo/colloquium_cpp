// Copyright 2015 Belkin Dmitriy
#ifndef ADD_NN_N_CPP
#define ADD_NN_N_CPP

// #include <algorithm>

#include "../../structs/struct.h"
#include "COM_NN_D.cpp"

natural ADD_NN_N(const natural& a, const natural& b) {
    natural ltNum, gtNum;  // gtNum имеет больший порядок

    if (COM_NN_D(a, b) == ordinal::LT) {
        ltNum = a;
        gtNum = b;
    } else {
        ltNum = b;
        gtNum = a;
    }

    natural res(gtNum);

    bool overflowFlag = false;
    // Проходим по разрядам числа с меньшим порядком
    for (int i = 0; i <= ltNum.order(); i++) {
        res[i] = add(res[i], ltNum[i], overflowFlag);
    }

    // прибавили все разряды меньшего к большему,
    // смотрим на переполнение последнего разряда
    int i = ltNum.order();
    while (overflowFlag) {
        // пока можем, избавляемся от переполнения (для сумм вида "99999 + 1")
        // Обнуляем флаг переполнения чтобы инкремент не увеличил число на два
        overflowFlag = false;
        inc(res[i + 1], overflowFlag);
        i++;
    }
    return res;
}

natural natural::operator+(const natural& other) {
    return ADD_NN_N(*this, other);
}

const natural n_one = natural({ _1 });
const natural n_zero = natural({ _0 });

#endif  // ADD_NN_N_CPP
