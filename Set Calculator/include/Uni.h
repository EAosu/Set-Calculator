#pragma once
#include "AccOperation.h"

// Class Uni oversees the operation (A U B) or (OP1 U OP2).
class Uni : public AccOperation
{
public:
	using AccOperation::AccOperation; // C-tor
	virtual Set evaluate(const Set& set1, const Set& set2) override;
};