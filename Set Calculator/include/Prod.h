#pragma once
#include "AccOperation.h"

// Class Prod oversees the operation (OP1 * OP2).
class Prod : public AccOperation
{
public:
	using AccOperation::AccOperation; // C-tor
	virtual Set evaluate(const Set& set1, const Set& set2) override;
};