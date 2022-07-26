#include "Prod.h"

// Evaluates the production of two sets.
Set Prod::evaluate(const Set& set1, const Set& set2)
{
	auto result = vector<int>();
	
	for (int i = 0; i < set1.getVec().size(); i++)
		for (int j = 0; j < set2.getVec().size(); j++)
			result.push_back(set1.getVec().at(i) * set2.getVec().at(j));

	return Set(result);
}
