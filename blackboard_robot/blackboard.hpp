#ifndef blackboard_HPP_
#define blackboard_HPP_

#define NO_SIGNAL	2//0.0f

#include <vector>
#include <iostream>

class blackboard{
public:
	//int add(int* pointer);
	//int add(float* pointer);
	blackboard();
	~blackboard();
	int addInput(std::string title, int varType);
	int addOutput(std::string title, int varType);

	void Run();
	/**
		@brief �ێ�����Ă���l�ɃA�N�Z�X���邽�߂̕ϐ� : ���͗p
		inputs->at(i) == intValues(or floatValues)->at(j)�ւ̃|�C���^
	 */
	std::vector<void *> *inputs;
	std::vector<int>	*inputTypes;
	/**
		@brief �ێ�����Ă���l�ɃA�N�Z�X���邽�߂̕ϐ� : ���͗p
		outputs->at(i) == intValues(or floatValues)->at(j)�ւ̃|�C���^
	 */
	std::vector<void *>	*outputs;
	std::vector<int>	*outputTypes;
	///���ۂɒl��ێ����Ă���ϐ�: int�^
	std::vector<int>* intValues;
protected:
	///���ۂɒl��ێ����Ă���ϐ�: float�^
	std::vector<float>* floatValues;
};

inline blackboard::blackboard(){
	inputs = new std::vector<void*>();
	inputTypes = new std::vector<int>();
	outputs = new std::vector<void*>();
	outputTypes = new std::vector<int>();
	intValues = new std::vector<int>();
	floatValues = new std::vector<float>();
}

inline blackboard::~blackboard(){
	delete(inputs);
	delete(inputTypes);
	delete(outputs);
	delete(outputTypes);
	delete(intValues);
	delete(floatValues);
}

inline int blackboard::addInput(std::string title, int varType){
	if(varType == 0){	//varType : int
		intValues->push_back((int)NO_SIGNAL);
		inputs->push_back(&(intValues->back()));
		std::cout << title.c_str() << ": " << *(int *)(inputs->back()) << std::endl;
	}else if(varType == 1){		//varType : float
		floatValues->push_back((float)NO_SIGNAL);
		inputs->push_back(&(floatValues->back()));
	}
	int index = inputs->size() - 1;
	inputTypes->push_back(varType);
	return index;
}

inline int blackboard::addOutput(std::string title, int varType){
	if(varType == 0){	//varType : int
		intValues->push_back((int)NO_SIGNAL);
		outputs->push_back(&(intValues->back()));
		std::cout << title.c_str() << ": " << *(int *)(outputs->back()) << std::endl;
/*		//�����ł͓����l������
		std::cout << "int" << intValues->back() << "\t" << &(intValues->back()) << std::endl;
		std::cout << "output" << *(int *)(outputs->back()) << "\t" << outputs->back() << std::endl;
*/
	}else if(varType == 1){		//varType : float
		floatValues->push_back((float)NO_SIGNAL);
		outputs->push_back(&(floatValues->back()));
	}
	int index = outputs->size() - 1;
	outputTypes->push_back(varType);
	return index;
}

inline void blackboard::Run(){
	std::cout << "outputs" << std::endl;
	for(int i = 0; i < outputs->size(); i++){
		std::cout << *(int *)outputs->at(i) << "\t";
	}
}

#endif	//blackboard_HPP_