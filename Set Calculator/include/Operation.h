#pragma once

// Includes
#include <algorithm>
#include <iterator>
#include "Set.h"
#include <string>

// Chars of operations - tried to move it to Macros.h but it caused problems.
const std::string INTER = { "^" }, UNION = { "U" }, DIFF = { "-" }, PROD = { "*" }, COMP = { "->" };

// Class Operation is the base class of the operations available in the program.
class Operation
{
public:
	Operation() { numofSets = 0; } // C-tor

	// Virtual funcs.
	virtual ~Operation() = default;
	virtual Set calculate(vector<Set>& sets) = 0;
	virtual void print(int& index) = 0;
	virtual int getNumofSets() const { return numofSets; };

	void setNumofSets(const int& setsNum) { this->numofSets = setsNum; } // Setter

private:
	int numofSets; // Holds the number of sets needed for the operation.
};
