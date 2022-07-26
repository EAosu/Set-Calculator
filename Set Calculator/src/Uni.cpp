#include "Uni.h"

// Evaluates the union of two sets.
Set Uni::evaluate(const Set& set1, const Set& set2)
{
	auto result = vector<int>();
	std::ranges::set_union(set1.getVec(), set2.getVec(), std::back_inserter(result));

	return Set(result); // Returns a set of the result.
}
