#pragma once
#include "Operation.h"

// Class Identity oversees the base of the program. 
// It handles a single set and maintains the vector of sets. 
class Identity : public Operation
{
public:
	Identity(); // C-tor

	// Virtuals
	virtual Set calculate(vector<Set>& sets) override;
	virtual void print(int& index) override;
};