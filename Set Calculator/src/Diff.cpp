#include "Diff.h"

// Evaluates the difference between two sets.
Set Diff::evaluate(const Set& set1, const Set& set2)
{
	auto result = vector<int>();
	std::ranges::set_difference(set1.getVec(), set2.getVec(), std::back_inserter(result));

	return Set(result);
}
