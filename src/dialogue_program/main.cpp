#include <iostream>
#include "../../include/towns_game.hpp"
#include "../../include/inout.hpp"
#include "../../include/dialogue.hpp"
#include <string>
#include <vector>
#include <stdexcept>

int dialog(std::vector<const char*> &msgs);

int main(){
    std::vector<const char*> msgs = {"Выход", "Загрузить города из текстового файла", "Сделать ход"};
	void (*dialogue_functions[])() = {nullptr, dialogue::load, dialogue::make_a_move};
	void (*on_exit)() = dialogue::on_exit;
    int function_index = 0;
	while((function_index = dialog(msgs))){
		try{
			dialogue_functions[function_index]();
		}
		catch(std::exception &exc){
			std::cout << exc.what() << std::endl;
			break;
		}
	}
	on_exit();
	return 0;
}

int dialog(std::vector<const char*> &msgs){
	int index;
	for(unsigned long long i = 0; i < msgs.size(); ++i){
        std::cout << i << ". " << (msgs[i]) << std::endl;
    }
	puts("Введите номер действия:");
	index = inout::getNum<int>(0, msgs.size() - 1);
	return index;
}
