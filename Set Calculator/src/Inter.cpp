#include "Inter.h"

// Evaluates the intersection of two sets.
Set Inter::evaluate(const Set& set1, const Set& set2)
{
	auto result = vector<int>();
	std::ranges::set_intersection(set1.getVec(), set2.getVec(), std::back_inserter(result));

	return Set(result);
}