#pragma once
#include "Operation.h"

// Class AccOperation oversees operations between two or more sets.
class AccOperation : public Operation
{
public:
	// C-tors and d-tor
	AccOperation() = default;
	~AccOperation() = default;
	AccOperation(const std::shared_ptr<Operation> op1, const std::shared_ptr<Operation> op2, const std::string& opChar);

	// Virtual functions
	virtual Set calculate(vector<Set>& sets) override;
	virtual Set evaluate(const Set& set1, const Set& set2) = 0;
	virtual void print(int& index) override;

	// Getters
	std::shared_ptr<Operation> getFirst() const { return this->m_first; }
	std::shared_ptr<Operation> getSecond() const { return this->m_second; }
	std::string getOpChar() const { return this->m_opChar; }

	// Setters
	void setFirst(std::shared_ptr<Operation> first) { this->m_first = first; }
	void setSecond(std::shared_ptr<Operation> second) { this->m_second = second; }
	
private:
	std::shared_ptr<Operation> m_first; // Left
	std::shared_ptr<Operation> m_second; // Right
	std::string m_opChar; // List of operations chars in "Operation.h"
};