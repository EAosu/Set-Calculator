#include "Set.h"

// Default c-tor.
Set::Set()
{}

// C-tor with size.
Set::Set(const int& size)
{
	this->m_set = initSet(size);
	this->organize();
}

// C-tor with a vector.
Set::Set(const vector<int>& vec)
{
	this->m_set = vec;
	this->organize();
}

vector<int> Set::getVec() const
{
	return this->m_set;
}

// Initiates the set by reading numbers into its vector.
vector<int> Set::initSet(const int& size)
{
	vector<int> tempVec;
	int counter = -1, num;

	while (++counter < size)
	{
		std::cin >> num;
		tempVec.push_back(num);
	}

	return tempVec;
}

// Sorts and deletes repeats.
void Set::organize()
{
	std::ranges::sort(this->m_set); // Sorts
	auto [newEnd, end] = std::ranges::unique(this->m_set); // Deletes repeats
	this->m_set.erase(newEnd, end);
}

// Output operator.
std::ostream& operator<<(std::ostream& ostr, const Set& set)
{
	Set tempSet = set;
	vector<int> vec = tempSet.getVec();

	ostr << "{ ";

	for (int i = 0; i < vec.size(); i++)
	{
		ostr << vec[i];

		if (i != vec.size() - 1)
			ostr << ", ";
	}

	ostr << " }";

	return ostr;
}
