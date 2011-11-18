#ifndef robot2_HPP_
#define robot2_HPP_

#include "robot.hpp"

class robot2 : public robot{
public:
	void Run();
};

inline void robot2::Run(){
	robot::Run();
	for(int i = 0; i < memory->inputs->size(); i++){
		std::cout << *(int *) memory->inputs->at(i) << "\t";
	}
	std::cout << std::endl;
	for(int i = 0; i < memory->outputs->size(); i++){
		std::cout << *(int *) memory->outputs->at(i) << "\t";
	}
	std::cout << std::endl;
	*(int*)memory->outputs->at(0) = *(int *)memory->inputs->at(0);
	*(int *)memory->outputs->at(2) = *(int *)memory->inputs->at(0);
	*(int *)memory->outputs->at(1) = *(int *)memory->inputs->at(1);
	*(int *)memory->outputs->at(4) = *(int *)memory->inputs->at(1);
	*(int *)memory->outputs->at(3) = *(int *)memory->inputs->at(2);
	*(int *)memory->outputs->at(5) = *(int *)memory->inputs->at(2);
	for(int i = 0; i < memory->inputs->size(); i++){
		std::cout << *(int *) memory->inputs->at(i) << "\t";
	}
	std::cout << std::endl;
	for(int i = 0; i < memory->outputs->size(); i++){
		std::cout << *(int *) memory->outputs->at(i) << "\t";
	}
	std::cout << std::endl;
}

#endif	//robot2_HPP_