#ifndef DUHAMSTER_MEPHI_OOP_LAB1_TOWNSHPP
#define DUHAMSTER_MEPHI_OOP_LAB1_TOWNSHPP

#include <exception>
#include <string>
#include <vector>
#include <unordered_set>

#define HOW_MANY_TOWNS 3

//!Библиотека для игры в города
namespace towns_game {
    //! unordered_set, содержащий все известные программе города
    extern std::unordered_set<std::string> all_towns;

    //! Загружает названия городов из текстового файла в towns_game::all_towns
    /*!
    Формат входного файла: все названия, разделенные переходом на следующую строку.
    Все символы в названиях, не являющиеся буквами, заменяются на пробелы в all_towns и, таким образом, равносильны для программы
    \param[in] dest Название файла с именами городов
    \throw std::runtime_error Если указанный файл не найден
    */
    void load_towns(const std::string &all_files_txt);

    //! Очищает towns_game::all_towns
    void forget_all_towns();

    //! Возвращает название города, содержащееся в all_towns и не содержащщеся в logs, начинающееся на последнюю букву последнего элемента logs
    /*!
    \param[in] std::vector<std::string> &logs Вектор с именами ранее названных городов
    \throw towns_game::no_more_towns Если подходящий город не найден
    */
    std::string play_towns(std::vector<std::string> &logs);

    //! Добавляет копию названия города в logs, переводя слово в верхний регистр и заменяя все символы, не являющиеся буквами, на пробелы
    /*!
    \param[in,out] std::vector<std::string> &logs Вектор с именами ранее названных городов
    \param[in] std::string &towns Имя города
    */
    void memorise_town(std::vector<std::string> &logs, const std::string &town);

    //! Ход пользователя в игре в города
    /*!
    Вызывает towns_game::memorise_town(), затем towns_game::play_towns()
    Добавляет город в logs, возвращает название города, содержащееся в all_towns и не содержащщеся в logs, начинающееся на последнюю букву последнего элемента logs.
    \param[in,out] std::vector<std::string> &logs Вектор с именами ранее названных городов
    \param[in] std::string &towns Имя города
    \throw towns_game::no_more_towns Если подходящий город не найден
    */
    std::string user_move(const std::string &town, std::vector<std::string> &logs);




    //!Возвращает название города, содержащееся в all_towns и не содержащщеся в logs, начинающееся на последнюю букву последнего элемента logs
    /*!
    \overload
    */
    void load_towns(const char *all_towns_txt);

    //! Возвращает название города, содержащееся в all_towns и не содержащщеся в logs, начинающееся на последнюю букву последнего элемента logs
    /*!
    Динамически выделяет память в куче, необходимо использовать std::free
    \param[in] char** logs Указатель на вектор с именами ранее названных городов, в виде си-строк
    \param[in] int size Размер вектора logs
    \throw towns_game::no_more_towns Если подходящий город не найден
    */
    const char* play_towns(const char** logs, int size);

    //! Добавляет копию названия города в logs, переводя слово в верхний регистр и заменяя все символы, не являющиеся буквами, на пробелы
    /*!
    \param[in,out] char **&logs Ссылка на вектор с именами ранее названных городов
    \param[in] char *town Имя города
    \param[in,out] int &size Ссылка на размер вектора logs
    */
    void memorise_town(const char **&logs, const char *town, int &size);

    //! Ход пользователя в игре в города
    /*!
    Вызывает towns_game::memorise_town(), затем towns_game::play_towns()
    Добавляет город в logs, возвращает название города, содержащееся в all_towns и не содержащщеся в logs, начинающееся на последнюю букву последнего элемента logs.
    Динамически выделяет память в куче, необходимо использовать std::free
    \param[in] char *town Имя города
    \param[in,out] char **&logs Вектор с именами ранее названных городов
    \param[in,out] int &size Ссылка на размер вектора logs
    \throw towns_game::no_more_towns Если подходящий город не найден
    */
    const char* user_move(const char *town, const char **&logs, int &size);

    //! Исключение, означающее невозможность назвать город на нужную букву, ранее не встреченный в списке
    class no_more_towns : public std::exception {
        public:
        const char* what () {
            return "Подходящих городов больше не осталось";
        }
    };
}

#endif