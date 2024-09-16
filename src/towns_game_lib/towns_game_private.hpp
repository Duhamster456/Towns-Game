#ifndef DUHAMSTER_MEPHI_OOP_LAB1_TOWNS_PRIVATEHPP
#define DUHAMSTER_MEPHI_OOP_LAB1_TOWNS_PRIVATEHPP

#include <string>
#include <vector>

namespace towns_game{
    std::string to_upper_case(const std::string &str);
    bool vector_contains(std::vector<std::string> &strs, const std::string &str);
    bool user_town_name_check(const std::string &name);
    std::string find_town(char letter, std::vector<std::string> &towns);

    const char *to_upper_case(const char *str);
    bool vector_contains(const char **strs, const char *str, int size);
    bool user_town_name_check(const char *name);
    const char* find_town(char letter, const char **towns, int size);
}

#endif