#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;

class Set
{
public:
	// C-tors
	Set();
	Set(const int& size);
	Set(const vector<int>& vec);

	vector<int> getVec() const; // Getter

private:
	vector<int> m_set; // Holds the integers of the set.

	// Private funcs
	vector<int> initSet(const int& vec);
	void organize();
};

// Output operation
std::ostream& operator<<(std::ostream&, const Set& set);
