#ifndef robot_HPP_
#define robot_HPP_

#include "blackboard.hpp"
#include "module.hpp"

class robot{
public:
	robot();
	~robot();
	void addModule(module* module);
	virtual void Run();
	blackboard* getMemory() const;
	void Test();
protected:
	blackboard* memory;
	std::vector<module *> *modules;
};

inline robot::robot(){
	memory = new blackboard();
	modules = new std::vector<module *>();
}

inline robot::~robot(){
	delete(modules);
	delete(memory);
}

inline blackboard* robot::getMemory() const{
	return this->memory;
}

inline void robot::addModule(module* module){
	//module��robot�ɓo�^
	modules->push_back(module);
	module->setParentModule(this);
	int index;
	//module�̓��͂��Cblackboard�̏o�͂Ɛڑ�
	for(int i = 0; i < module->getNumOfInputs(); i++){
		index = memory->addOutput(module->getInputsTitle()->at(i));
		module->addInputsIndex(index);	//index on memory->outputs
	}
	//module�̏o�͂��Cblackboard�̓��͂Ɛڑ�
	for(int i = 0; i < module->getNumOfOutputs(); i++){
		index = memory->addInput(module->getOutputsTitle()->at(i));
		module->addOutputsIndex(index);	//index on memory->inputs
	}
}

inline void robot::Test(){
	for(int i = 0; i < modules->size(); i++){
		for(int j = 0; j < modules->at(i)->inputsIndex->size(); j++){
			std::cout << "inputs:(" << i << ", " << j << ") :" << memory->getOutputs(modules->at(i)->inputsIndex->at(j)) << std::endl;
		}
		for(int j = 0; j < modules->at(i)->outputsIndex->size(); j++){
			std::cout << "outputs:(" << i << ", " << j << ") :" << memory->getInputs(modules->at(i)->outputsIndex->at(j)) << std::endl;
		}
	}
}

inline void robot::Run(){
	for(int i = 0; i < modules->size(); i++){
			modules->at(i)->Run();
	}
	memory->Run();
}

#endif	//robot_HPP_