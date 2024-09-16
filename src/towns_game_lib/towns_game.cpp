#include "../../include/towns_game.hpp"
#include "./towns_game_private.hpp"
#include <cstring>
#include <string>
#include <iostream>
#include <limits>
#include <cstring>
#include <cctype>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <stdexcept>

namespace towns_game{
    std::unordered_set<std::string> all_towns;

    void memorise_town(std::vector<std::string> &logs, const std::string &town){
        std::string to_add = to_upper_case(town);
        logs.push_back(to_add);
    }

    void memorise_town(const char **&logs, const char *town, int &size){
        const char *to_add = to_upper_case(town);
        logs = (const char **)std::realloc(logs, ++size * sizeof(char *));
        logs[size - 1] = to_add;
    }

    void load_towns(const char *all_towns_txt){
        std::ifstream inputFile(all_towns_txt);
        if (!inputFile.is_open()) {
            throw std::runtime_error("Не удалось открыть файл");
        }
        std::string input;
        do{
            std::getline(inputFile, input);
            if(!input.length()) continue;
            input = to_upper_case(input);
            all_towns.insert(input);
        }
        while(!inputFile.eof());
        inputFile.close();
    }

    void load_towns(const std::string &all_files_txt){
        load_towns(all_files_txt.c_str());
    }

    void forget_all_towns(){
        all_towns.clear();
    }

    std::string find_town(char letter, std::vector<std::string> &towns){
        for(std::string town : all_towns){
            if(town.at(0) == letter && !vector_contains(towns, town)){
                return town;
            }
        }
        throw no_more_towns();
    }

    const char* find_town(char letter, const char **towns, int size){
        for(std::string town : all_towns){
            const char *town_cstr = town.c_str();
            if(town.at(0) == letter && !vector_contains(towns, town_cstr, size)){
                int len = std::strlen(town_cstr) + 1;
                char *res = (char*) malloc(len * sizeof(char));
                memcpy(res, town_cstr, len);
                return res;
            }
        }
        throw no_more_towns();
    }

    const char* play_towns(const char** towns, int size){
        const char* last = to_upper_case(towns[size - 1]);
        int last_len = std::strlen(last);
        char letter = last[last_len - 1];
        try{
            const char* res = find_town(letter, towns, size);
            std::free((void*) last);
            return res;
        }
        catch(no_more_towns &exc){
            if(last_len == 1) throw no_more_towns();
            letter = last[last_len - 2];
            const char* res = find_town(letter, towns, size);
            std::free((void*) last);
            return res;
        }
    }

    std::string play_towns(std::vector<std::string> &towns){
        std::string last = towns.back();
        last = to_upper_case(last);
        int last_len = last.length();
        char letter = last.back();
        try{
            return find_town(letter, towns);
        }
        catch(no_more_towns &exc){
            if(last_len <= 1) throw no_more_towns();
            letter = last.at(last_len - 2);
            return find_town(letter, towns);
        }
    }

    std::string user_move(const std::string &town, std::vector<std::string> &logs){
        if(!user_town_name_check(town)) throw std::invalid_argument("Неизвестное название города");
        if(logs.size()){
            std::string &last = logs.back();
            if(std::toupper(town.at(0)) != std::toupper(last.back())) throw std::invalid_argument("Не та буква");
        }
        if(vector_contains(logs, town)) throw std::invalid_argument("Такой город уже был");
        memorise_town(logs, town);
        std::string res = play_towns(logs);
        logs.push_back(res);
        return res;
    }

    const char *user_move(const char *town, const char **&logs, int &size){
        if(!user_town_name_check(town)) throw std::invalid_argument("Неизвестное название города");
        if(size){
            const char *last = logs[size - 1];
            if(std::toupper(town[0]) != std::toupper(last[std::strlen(last) - 1])) throw std::invalid_argument("Не та буква");
        }
        if(vector_contains(logs, town, size)) throw std::invalid_argument("Такой город уже был");
        memorise_town(logs, town, size);
        const char *res = play_towns(logs, size);
        memorise_town(logs, res, size);
        return res;
    }
}
