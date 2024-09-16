#ifndef DUHAMSTER_MEPHI_OOP_LAB1_INOUTHPP
#define DUHAMSTER_MEPHI_OOP_LAB1_INOUTHPP

#include <cstring>
#include <string>
#include <iostream>
#include <limits>
#include <cstring>

//!Библиотека для ввода и вывода
namespace inout{
    //! Шаблонная функция для ввода числа
    template<class T>
    T getNum(T min = std::numeric_limits<T>::lowest(), T max = std::numeric_limits<T>::max()) {
        T a;
        while(true) {
            std::cin >> a;
            if(std::cin.eof())
                throw std::runtime_error("Failed to read number: EOF");
            else if(std::cin.bad())
                throw std::runtime_error(std::string("Failed to read number: ") + strerror(errno));

            else if(std::cin.fail() || a < min || a > max) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "You are wrong; repeat please!" << std::endl;
            }
            else
            return a;
        }
    }
}

#endif