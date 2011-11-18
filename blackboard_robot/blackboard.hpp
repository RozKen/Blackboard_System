#ifndef blackboard_HPP_
#define blackboard_HPP_

#define NO_SIGNAL	2.0f	//0.0f

#include <vector>
#include <iostream>

class blackboard{
public:
	//int add(int* pointer);
	//int add(float* pointer);
	blackboard();
	~blackboard();
	int addInput(std::string title);
	int addOutput(std::string title);

	void Run();
	
	//Setters and Getters
	float getInputs(int index) const;
	void setInputs(int index, float signal);
	float getOutputs(int index) const;
	void setOutputs(int index, float signal);
	int getNumOfInputs() const;
	int getNumOfOutputs() const;

protected:
	std::vector<float>* inputs;
	std::vector<float>* outputs;
	int numOfInputs;
	int numOfOutputs;
};

inline blackboard::blackboard(): numOfInputs(0), numOfOutputs(0){
	inputs = new std::vector<float>();
	outputs = new std::vector<float>();
}

inline blackboard::~blackboard(){
	delete(inputs);
	delete(outputs);
}

inline int blackboard::addInput(std::string title){
	inputs->push_back(NO_SIGNAL);
	int index = inputs->size() - 1;
	numOfInputs++;
	return index;
}

inline int blackboard::addOutput(std::string title){
	outputs->push_back(NO_SIGNAL);
	int index = outputs->size() - 1;
	numOfOutputs++;
	return index;
}

inline void blackboard::Run(){
	std::cout << "inputs" << std::endl;
	for(int i = 0; i < inputs->size(); i++){
		std::cout << inputs->at(i) << "\t";
	}
	std::cout << "outputs" << std::endl;
	for(int i = 0; i < outputs->size(); i++){
		std::cout << outputs->at(i) << "\t";
	}
}

inline float blackboard::getInputs(int index) const{
	return inputs->at(index);
}
inline void blackboard::setInputs(int index, float signal){
	inputs->at(index) = signal;
}
inline float blackboard::getOutputs(int index) const{
	return outputs->at(index);
}
inline void blackboard::setOutputs(int index, float signal){
	outputs->at(index) = signal;
}

inline int blackboard::getNumOfInputs() const{
	return numOfInputs;
}
inline int blackboard::getNumOfOutputs() const{
	return numOfOutputs;
}

#endif	//blackboard_HPP_