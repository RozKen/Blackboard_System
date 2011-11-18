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
	//robotにおいて，blackboardへ登録されたときに実行される．
	inputsIndex->push_back(index);
}
void module::addOutputsIndex(int index){
	//robotにおいて，blackboardへ登録されたときに実行される．
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
	//moduleへの入力はmemoryの出力から入手
	int result = memory->getOutputs(index);
	std::cout << result << std::endl;
	return result;
}

void module::setOutput(int index, float signal){
	//moduleからの出力はmemoryの入力へ送信
	memory->setInputs(index, signal);
	int result = memory->getInputs(index);
	std::cout << result << std::endl;
}