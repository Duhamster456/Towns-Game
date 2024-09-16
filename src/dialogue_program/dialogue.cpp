#include "../../include/dialogue.hpp"
#include "../../include/towns_game.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <limits>

namespace dialogue{
    std::vector<std::string> *logs = new std::vector<std::string>();

    void load(){
        std::string input;
        std::cout << "Введите название файла с названиями городов" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, input);
        towns_game::load_towns(input);
    }

    void make_a_move(){
        std::string input;
        std::cout << "Введите название города" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, input);
        try{
            std::string res = towns_game::user_move(input, *logs);
            std::cout << res << std::endl;
        }
        catch(std::invalid_argument& exc){
            std::cout << exc.what() << std::endl;
            return;
        }
    }

    void on_exit(){
        delete logs;
    }
} 