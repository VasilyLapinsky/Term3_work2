#include "Set.h"

Set::Set(int size, bool val)
{
	set = vector<bool>(size, val );
}

Set::Set(vector<bool>& val)
{
	set.reserve(val.size());
	for (int i = 0; i < val.size(); ++i)
		set.push_back(val[i]);
}

Set::Set(vector<int>& val)
{
	if (val.size() == 0) return;

	int max = val[0];
	for (int i = 1; i < val.size(); ++i)
		if (val[i] > max) max = val[i];
	set = vector<bool>(max + 1, false);
	for (int i = 0; i < val.size(); ++i)
		set[val[i]] = true;
}

Set::Set(const Set& val)
{
	set = vector<bool>(val.set);
}

void Set::add(int val)
{
	if (val > (set.size() - 1))
	{
		set.resize(val + 1, false);
	}
	set[val] = true;
}

void Set::del(int val)
{
	if (val < set.size())
	{
		set[val] = false;
	}
}

bool Set::is_here(int val)
{
	if (val > (set.size() - 1))
	{
		return false;
	}
	return set[val];
}

bool Set::is_empty()
{
	return find(set.begin(), set.end(), true) != set.end();
}

