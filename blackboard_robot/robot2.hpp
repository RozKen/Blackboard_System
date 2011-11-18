#ifndef robot2_HPP_
#define robot2_HPP_

#include "robot.hpp"

class robot2 : public robot{
public:
	void Run();
};

inline void robot2::Run(){
	robot::Run();
	
	std::cout << std::endl;
	memory->setOutputs(0, memory->getInputs(0));
	memory->setOutputs(2, memory->getInputs(0));
	memory->setOutputs(1, memory->getInputs(1));
	memory->setOutputs(4, memory->getInputs(1));
	memory->setOutputs(3, memory->getInputs(2));
	memory->setOutputs(5, memory->getInputs(2));
}

#endif	//robot2_HPP_