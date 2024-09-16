#include "../../include/towns_game.hpp"
#include "./towns_game_private.hpp"
#include <cstring>
#include <cstdlib>
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
    std::string to_upper_case(const std::string &str){
        std::string res = str;
        for(unsigned int i = 0; i < str.length(); i++){
            res[i] = std::isalpha(str[i]) ? std::toupper(str[i]) : ' ';
        };
        return res;
    }

    bool vector_contains(std::vector<std::string> &strs, const std::string &str){
        return std::any_of(strs.cbegin(), strs.cend(), [&str](std::string elem) { return elem == str; });
    }

    bool user_town_name_check(const std::string &name){
        if(!name.length()) return false;
        if(!all_towns.contains(to_upper_case(name))) return false;
        return true;
    }

    const char *to_upper_case(const char *str){
        int len = strlen(str);
        char *res = (char*) malloc((len + 1) * sizeof(char));
        std::memcpy(res, str, len + 1);
        for(int i = 0; i < len; i++){
            if(std::isalpha(res[i])){
                res[i] = std::toupper(str[i]);
            }
            else{
                res[i] = ' ';
            }
        }
        return res;
    }

    bool vector_contains(const char **strs, const char *str, int size){
        for(int i = 0; i < size; i++){
            if(std::strcmp(strs[i], str) == 0) return true;
        }
        return false;
    }

    bool user_town_name_check(const char *name){
        if(!strlen(name)) return false;
        if(!all_towns.contains(to_upper_case(std::string(name)))) return false;
        return true;
    }
}