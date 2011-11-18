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
	float a = getInput(inputsIndex->at(0));
	float b = getInput(inputsIndex->at(1));
	//Process
	float c = a * b;
	std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
	//Deliver Data
	setOutput(outputsIndex->at(0), c);
}

#endif	//mod_multiple_HPP_