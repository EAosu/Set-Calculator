#pragma once
#include "AccOperation.h"

// Class Inter oversees the operation (A ^ B) or (OP1 ^ OP2).
class Inter : public AccOperation
{
public:
	using AccOperation::AccOperation; // C-tor
	virtual Set evaluate(const Set& set1, const Set& set2) override;
};