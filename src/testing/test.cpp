#define CATCH_CONFIG_MAIN
#include "../../include/towns_game.hpp"
#include <../../Catch2/extras/catch_amalgamated.hpp>

#include <iostream>
#include <vector>


TEST_CASE("Сpp-style overload") {
    SECTION("Finding towns on correct letter") {
        towns_game::load_towns("../resources/tests/finding.txt");
        std::vector<std::string> logs;
        logs.push_back("A");
        std::string res = towns_game::play_towns(logs);
        CHECK(res == std::string("ATOWN"));
        logs.push_back("W");
        res = towns_game::play_towns(logs);
        CHECK(res == "WTOWN");
        logs.push_back("P");
        res = towns_game::play_towns(logs);
        CHECK(res == "PTOWN");
        logs.push_back("W");
        res = towns_game::play_towns(logs);
        CHECK(res == "WTOWN");
        towns_game::forget_all_towns();
    }
    SECTION("Finding towns on penultimate letter") {
        towns_game::load_towns("../resources/tests/finding.txt");
        std::vector<std::string> logs;
        logs.push_back("AZ");
        std::string res = towns_game::play_towns(logs);
        CHECK(res == std::string("ATOWN"));
        logs.push_back("WZ");
        res = towns_game::play_towns(logs);
        CHECK(res == "WTOWN");
        logs.push_back("PZ");
        res = towns_game::play_towns(logs);
        CHECK(res == "PTOWN");
        logs.push_back("WZ");
        res = towns_game::play_towns(logs);
        CHECK(res == "WTOWN");
        towns_game::forget_all_towns();
    }
    SECTION("Throwing an towns_game::no_more_towns exception") {
        towns_game::load_towns("../resources/tests/finding.txt");
        std::vector<std::string> logs;
        logs.push_back("AЫЫ");
        CHECK_THROWS_AS(towns_game::play_towns(logs), towns_game::no_more_towns);
        logs.push_back("ATOWN");
        logs.push_back("A");
        CHECK_THROWS_AS(towns_game::play_towns(logs), towns_game::no_more_towns);
        towns_game::forget_all_towns();
    }
    SECTION("towns_game::user_move function") {
        towns_game::load_towns("../resources/tests/normal_game.txt");
        std::vector<std::string> logs;
        CHECK_THROWS_AS(towns_game::user_move("This town doesnt exist", logs), std::invalid_argument);
        std::string res = towns_game::user_move("Miass", logs);
        CHECK(res == "SAMARA");
        CHECK_THROWS_AS(towns_game::user_move("Samara", logs), std::invalid_argument);
        res = towns_game::user_move("Archangelsk", logs);
        CHECK(res == "KIROV");
        towns_game::forget_all_towns();
    }
}
TEST_CASE("С-style overload") {
    SECTION("Finding towns on correct letter") {
        towns_game::load_towns("../resources/tests/finding.txt");
        const char **logs = nullptr;
        int size = 0;
        towns_game::memorise_town(logs, "A", size);
        const char* res = towns_game::play_towns(logs, size);
        CHECK(strcmp(res, "ATOWN") == 0);
        std::free((void*) res);
        towns_game::memorise_town(logs, "eowkoewkB", size);
        res = towns_game::play_towns(logs, size);
        CHECK(strcmp(res, "BTOWN") == 0);
        std::free((void*) res);
        towns_game::memorise_town(logs, "ekfowkweofkoC", size);
        res = towns_game::play_towns(logs, size);
        CHECK(strcmp(res, "CTOWN") == 0);
        std::free((void*) res);
        for(int i = 0; i < size; i++){
            std::free((void*) logs[i]); 
        }
        std::free(logs);
        towns_game::forget_all_towns();
    }
    SECTION("Finding towns on penultimate letter") {
        towns_game::load_towns("../resources/tests/finding.txt");
        const char **logs = nullptr;
        int size = 0;
        towns_game::memorise_town(logs, "AZ", size);
        const char* res = towns_game::play_towns(logs, size);
        CHECK(strcmp(res, "ATOWN") == 0);
        std::free((void*) res);
        towns_game::memorise_town(logs, "eowkoewkBZ", size);
        res = towns_game::play_towns(logs, size);
        CHECK(strcmp(res, "BTOWN") == 0);
        std::free((void*) res);
        towns_game::memorise_town(logs, "ekfowkweofkoCZ", size);
        res = towns_game::play_towns(logs, size);
        CHECK(strcmp(res, "CTOWN") == 0);
        std::free((void*) res);
        for(int i = 0; i < size; i++){
            std::free((void*) logs[i]); 
        }
        std::free(logs);
        towns_game::forget_all_towns();
    }
    SECTION("Throwing an towns_game::no_more_towns exception") {
        towns_game::load_towns("../resources/tests/finding.txt");
        const char **logs = nullptr;
        int size = 0;
        towns_game::memorise_town(logs, "AZZ", size);
        CHECK_THROWS_AS(towns_game::play_towns(logs, size), towns_game::no_more_towns);
        towns_game::memorise_town(logs, "ATOWN", size);
        towns_game::memorise_town(logs, "A", size);
        for(int i = 0; i < size; i++){
            std::free((void*) logs[i]); 
        }
        std::free(logs);
        towns_game::forget_all_towns();
    }
    SECTION("towns_game::user_move function") {
        towns_game::load_towns("../resources/tests/normal_game.txt");
        const char **logs = nullptr;
        int size = 0;
        CHECK_THROWS_AS(towns_game::user_move("This town doesnt exist", logs, size), std::invalid_argument);
        const char *res = towns_game::user_move("Miass", logs, size);
        CHECK(strcmp(res, "SAMARA") == 0);
        std::free((void*) res);
        CHECK_THROWS_AS(towns_game::user_move("Samara", logs, size), std::invalid_argument);
        res = towns_game::user_move("Archangelsk", logs, size);
        CHECK(strcmp(res, "KIROV") == 0);
        std::free((void*) res);
        for(int i = 0; i < size; i++){
            std::free((void*) logs[i]); 
        }
        std::free(logs);
        towns_game::forget_all_towns();
    }
}