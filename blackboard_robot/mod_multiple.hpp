#ifndef mod_multiple_HPP_
#define mod_multiple_HPP_

#include "module.hpp"
#include <iostream>

class mod_multiple : public module{
public:
	mod_multiple();
	void Run();
};

inline mod_multiple::mod_multiple(){
	addInput(std::string("add_left"), 0);
	addInput(std::string("add_right"), 0);
	addOutput(std::string("add_result"), 0);
}

inline void mod_multiple::Run(){
	///////////////////ここで間違ったメモリアクセスが発生中//////////
	//Acquire Data
	int a = getInput(0);
	std::cout << "inputsIndex->at(0): " << inputsIndex->at(0) << std::endl;
	std::cout << *(int *)(memory->outputs->at(inputsIndex->at(0))) << std::endl;
	std::cout << memory->intValues->at(inputsIndex->at(0)) << std::endl;
	int b = getInput(1);
	std::cout << "inputsIndex->at(1): " << inputsIndex->at(1) << std::endl;
	std::cout << memory->intValues->at(inputsIndex->at(1)) << std::endl;
	//Process
	int c = a * b;
	std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
	//Deliver Data
	setOutput(0, c);
	std::cout << "outputsIndex->at(0): " << outputsIndex->at(0) << std::endl;
}

#endif	//mod_multiple_HPP_