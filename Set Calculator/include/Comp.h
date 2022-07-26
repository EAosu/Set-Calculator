#pragma once

// Includes
#include "AccOperation.h"
#include "Uni.h"
#include "Inter.h"
#include "Diff.h"
#include "Prod.h"

// Class Comp overseas compositions of operations.
class Comp : public AccOperation
{
public:
	using AccOperation::AccOperation; // C-tor

	// Virtual funcs
	virtual Set calculate(vector<Set>& sets) override;
	virtual Set evaluate(const Set& set1, const Set& set2) override;
};