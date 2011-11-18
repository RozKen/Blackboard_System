#include "robot.hpp"
#include "blackboard.hpp"
#include "module.hpp"

module::module(): numOfInputs(0), numOfOutputs(0){
	inputsIndex = new std::vector<int>();
	outputsIndex = new std::vector<int>();
	inputsTitle = new std::vector<std::string>();
	outputsTitle = new std::vector<std::string>();
	inputsVarType = new std::vector<int>();
	outputsVarType = new std::vector<int>();
}

module::~module(){
	delete(inputsIndex);
	delete(outputsIndex);
	delete(inputsTitle);
	delete(outputsTitle);
	delete(inputsVarType);
	delete(outputsVarType);
}

void module::setParentModule(robot* parent){
	this->parent = parent;
	this->memory = parent->getMemory();
}

void module::addInput(std::string title, int varType){
	inputsTitle->push_back(title);
	inputsVarType->push_back(varType);
	numOfInputs = inputsTitle->size();
}
void module::addOutput(std::string title, int varType){
	outputsTitle->push_back(title);
	outputsVarType->push_back(varType);
	numOfOutputs = outputsTitle->size();
}

void module::addInputsIndex(int index){
	inputsIndex->push_back(index);
}
void module::addOutputsIndex(int index){
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
std::vector<int>* module::getInputsVarType() const{
	return inputsVarType;
}
std::vector<int>* module::getOutputsVarType() const{
	return outputsVarType;
}

int module::getInput(int index) const{
	int result;
	//return *(int *)(memory->outputs->at(this->inputsIndex->at(index)));
	result = *(int *)(memory->outputs->at(index));
	std::cout << result << std::endl;
	return result;
}
void module::setOutput(int index, int output){
	int result;
	//*(int *)(memory->inputs->at(this->outputsIndex->at(index))) = output;
	*(int *)(memory->inputs->at(index)) = output;
	result = *(int *)(memory->inputs->at(index));
	std::cout << result << std::endl;
}