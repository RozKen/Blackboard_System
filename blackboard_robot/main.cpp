#include "robot2.hpp"
#include "mod_multiple.hpp";

#include <iostream>

void main(){
	mod_multiple* a = new mod_multiple();
	mod_multiple* b = new mod_multiple();
	mod_multiple* c = new mod_multiple();
	mod_multiple* d = new mod_multiple();
	mod_multiple* e = new mod_multiple();
	
	robot2* robo;
	robo = new robot2();
	
	robo->addModule(a);
	//‚±‚±‚Å‚à‚¤‚¾‚ßD
	robo->Test();
	robo->addModule(b);
	robo->Test();
	robo->addModule(c);
	robo->Test();
	robo->addModule(d);
	robo->Test();
	robo->addModule(e);
	robo->Test();

	blackboard* memory = robo->getMemory();

	char s;

	for(int i = 0; i < 100; i++){
		robo->Run();
		std::cout << "memory-inputs: ";
		for(int j = 0; j < memory->getNumOfInputs(); j++){
			std::cout << memory->getInputs(j) << "\t";
		}
		std::cout << std::endl;

		std::cout << "memory-outputs: ";
		for(int j = 0; j < memory->getNumOfOutputs(); j++){
			std::cout << memory->getOutputs(j) << "\t";
		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "============================" << std::endl;

		std::cin >> s;
	}
}