#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Set
{
private:
	vector<bool> set;
public:
	Set(int size, bool val);
	Set(vector<bool>& val);
	Set(vector<int>& val);
	Set(const Set& val);

	void add(int val);
	void del(int val);
	bool is_here(int val);
	bool is_empty();
};

