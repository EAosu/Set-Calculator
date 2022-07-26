#pragma once
#include "AccOperation.h"

// Class Diff overseas the evaluation of (A - B) and (OP1 - OP2).
class Diff : public AccOperation
{
public:
	using AccOperation::AccOperation; // C-tor
	virtual Set evaluate(const Set& set1, const Set& set2) override;
};