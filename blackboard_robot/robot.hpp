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
	//�������Ɋ֌W�Ȃ���ȁc
	//module = modules->back();
	module->setParentModule(this);
	int index;
	//module�̓��͂��Cblackboard�̏o�͂Ɛڑ�
	for(int i = 0; i < module->getNumOfInputs(); i++){
		index = memory->addOutput(module->getInputsTitle()->at(i), 
			module->getInputsVarType()->at(i));
		module->addInputsIndex(index);	//index on memory->outputs
		//�����܂�OK
		std::cout << "inputs(" << i << ") " << *(int *)(memory->outputs->at(module->inputsIndex->at(i))) << std::endl;
	}
	//module�̏o�͂��Cblackboard�̓��͂Ɛڑ�
	for(int i = 0; i < module->getNumOfOutputs(); i++){
		index = memory->addInput(module->getOutputsTitle()->at(i),
			module->getOutputsVarType()->at(i));
		module->addOutputsIndex(index);	//index on memory->inputs
		//�����܂�OK
		std::cout << "outputs(" << i << ") " <<*(int *)(memory->inputs->at(module->outputsIndex->at(i))) << std::endl;
	}
}

inline void robot::Test(){
	for(int i = 0; i < modules->size(); i++){
		//�����ł�������
		for(int j = 0; j < modules->at(i)->inputsIndex->size(); j++){
			std::cout << "inputs:(" << i << ", " << j << ") :" << *(int *)(memory->outputs->at(modules->at(i)->inputsIndex->at(j))) << std::endl;
			//std::cout << j << " - inputsIndex: " << modules->at(i)->inputsIndex->at(j) << std::endl;
			//std::cout << "pointer to inputs:(" << i << ", " << j << ") :" << (memory->outputs->at(modules->at(i)->inputsIndex->at(j))) << std::endl;
		}
		for(int j = 0; j < modules->at(i)->outputsIndex->size(); j++){
			std::cout << "outputs:(" << i << ", " << j << ") :" << *(int *)(memory->inputs->at(modules->at(i)->outputsIndex->at(j))) << std::endl;
			//std::cout << j << " - outputsIndex: " << modules->at(i)->outputsIndex->at(j) << std::endl;
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