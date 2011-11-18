#ifndef module_HPP_
#define module_HPP_

class robot;
class blackboard;

class module{
public:
	module();
	~module();
	virtual void Run() = 0;
	void addInput(std::string title, int varType);
	void addOutput(std::string title, int varType);

	//Setters
	void setParentModule(robot* parent);
	void addInputsIndex(int index);
	void addOutputsIndex(int index);
	//Getters
	int getNumOfInputs() const;
	int getNumOfOutputs() const;
	std::vector<std::string>* getInputsTitle() const;
	std::vector<std::string>* getOutputsTitle() const;
	std::vector<int>* getInputsVarType() const;
	std::vector<int>* getOutputsVarType() const;

	int getInput(int index) const;
	void setOutput(int index, int output);
	std::vector<int> *inputsIndex;
	std::vector<int> *outputsIndex;
protected:
	std::vector<std::string> *inputsTitle;
	std::vector<std::string> *outputsTitle;
	std::vector<int> *inputsVarType;
	std::vector<int> *outputsVarType;
	int numOfInputs;
	int numOfOutputs;

	robot* parent;
	blackboard* memory;
};

#endif	//module_HPP_