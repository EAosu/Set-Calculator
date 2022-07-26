#include "Comp.h"

// A seperate calculation for a composition of operations.
Set Comp::calculate(vector<Set>& sets)
{
	std::cout << "(";
	Set first = this->getFirst().get()->calculate(sets);
	// Inserts the result from the first operation as the input of the second operation
	sets.insert(sets.begin(), first);
	std::cout << " " << this->getOpChar() << " ";
	Set second = this->getSecond().get()->calculate(sets);
	std::cout << ")";

	return (this->evaluate(first, second));
}

Set Comp::evaluate(const Set& set1, const Set& set2)
{
	return set2; // set2 holds the final result.
}