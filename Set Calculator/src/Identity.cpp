#include "Identity.h"

// C-tor.
Identity::Identity()
{
	this->setNumofSets(1);
}

// Returns the set itself, f(x) = x.
Set Identity::calculate(vector<Set>& sets)
{
	Set tempSet = sets.front(); // Copies the first set.
	std::cout << tempSet; // Prints it.
	sets.erase(sets.begin()); // Removes it from the vector.
	return tempSet; // Returns it.
}

// Prints the alphabetic index of the set.
void Identity::print(int& index)
{
	char setChar = 'A' + char(index++);

	if (setChar > 'Z')
		setChar = 'X';

	std::cout << setChar;
}
