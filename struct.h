// Copyright 2015 Belkin Dmitriy
#ifndef STRUCT_H
#define STRUCT_H

#include <vector>

// #яХочуКлассы #нужноБольшеИнкапсуляции
// Натуральное число
struct natural {
    // TODO: Добавить других конструкторов
    natural(const natural& number) {
        this->digits = digits;  // vector copy constructor
    }

    // Массив цифр от младших разрядов к старшим
    // Число 9426 будет представленно как { 6, 2, 4, 9 }
    std::vector<int16> digits;

    // Количество разрядов в числе
    // TODO: test it
    int order() { return digits->length(); }

    ~natural() {
        digits->clean();
        delete digits;
    }

    // TODO: переопределить операторы
};

// Посмотреть на это все позже =)
// struct integer //Целое число
// {
// 	bool sign; //Знак числа
// 	natural module; //Модуль целого числа, представленный как натуральное
// };
// struct fraction //Дробь
// {
// 	integer numerator; //Числитель дроби, представленный как целое число
// 	natural denominator; //Знаменатель дроби, представленный как натуральное число
// };
// struct polynom //Многочлен
// {    
//     std::vector<fraction>* coefficients; //Коэффициенты многочлена, представленные дробью

//     //Степень многочлена
//     int degree() { return coefficients->length(); }
// };

#endif  // STRUCT_H
