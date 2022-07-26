#include "AccOperation.h"

// Constructor.
AccOperation::AccOperation(const std::shared_ptr<Operation> op1, const std::shared_ptr<Operation> op2, const std::string& opChar)
	: m_first(op1), m_second(op2), m_opChar(opChar)
{
	if (opChar == COMP)
		this->setNumofSets(op1.get()->getNumofSets() + op2.get()->getNumofSets() - 1);
	else
		this->setNumofSets(op1.get()->getNumofSets() + op2.get()->getNumofSets());
}

// Recursively calculates an accumulated operation.
Set AccOperation::calculate(vector<Set>& sets)
{
	std::cout << "(";
	Set first = this->getFirst().get()->calculate(sets); // Left
	std::cout << " " << m_opChar << " ";
	Set second = this->getSecond().get()->calculate(sets); // Right
	std::cout << ")";

	return (this->evaluate(first, second));
}

// Recursively prints the calculation.
void AccOperation::print(int& index)
{
	std::cout << "(";
	this->getFirst().get()->print(index); // Left

	std::cout << " " << m_opChar << " ";

	this->getSecond().get()->print(index); // Right
	std::cout << ")";
}