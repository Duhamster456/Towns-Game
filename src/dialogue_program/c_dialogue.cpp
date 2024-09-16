#include "../../include/dialogue.hpp"
#include "../../include/towns_game.hpp"

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>

namespace dialogue{
    const char **logs = nullptr;
    int logs_size = 0;

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
            const char* res = towns_game::user_move(input.c_str(), logs, logs_size);
            std::cout << res << std::endl;
	    std::free((void*) res);
        }
        catch(std::invalid_argument& exc){
            std::cout << exc.what() << std::endl;
            return;
        }
    }

    void on_exit(){
        for(int i = 0; i < logs_size; i++){
            std::free((void*) logs[i]);
        }
        std::free(logs);
    }
} 
