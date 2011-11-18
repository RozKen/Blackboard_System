#include "robot.hpp"
#include "blackboard.hpp"
#include "module.hpp"

module::module(): numOfInputs(0), numOfOutputs(0){
	inputsIndex = new std::vector<int>();
	outputsIndex = new std::vector<int>();
	inputsTitle = new std::vector<std::string>();
	outputsTitle = new std::vector<std::string>();
}

module::~module(){
	delete(inputsIndex);
	delete(outputsIndex);
	delete(inputsTitle);
	delete(outputsTitle);
}

void module::setParentModule(robot* parent){
	this->parent = parent;
	this->memory = parent->getMemory();
}

void module::addInput(std::string title, int varType){
	inputsTitle->push_back(title);
	numOfInputs = inputsTitle->size();
}
void module::addOutput(std::string title, int varType){
	outputsTitle->push_back(title);
	numOfOutputs = outputsTitle->size();
}

void module::addInputsIndex(int index){
	//robot�ɂ����āCblackboard�֓o�^���ꂽ�Ƃ��Ɏ��s�����D
	inputsIndex->push_back(index);
}
void module::addOutputsIndex(int index){
	//robot�ɂ����āCblackboard�֓o�^���ꂽ�Ƃ��Ɏ��s�����D
	outputsIndex->push_back(index);
}

int module::getNumOfInputs() const{
	return numOfInputs;
}
int module::getNumOfOutputs() const{
	return numOfOutputs;
}

std::vector<std::string>* module::getInputsTitle() const{
	return inputsTitle;
}
std::vector<std::string>* module::getOutputsTitle() const{
	return outputsTitle;
}

float module::getInput(int index) const{
	//module�ւ̓��͂�memory�̏o�͂������
	int result = memory->getOutputs(index);
	std::cout << result << std::endl;
	return result;
}

void module::setOutput(int index, float signal){
	//module����̏o�͂�memory�̓��֑͂��M
	memory->setInputs(index, signal);
	int result = memory->getInputs(index);
	std::cout << result << std::endl;
}