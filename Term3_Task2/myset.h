#pragma once
#include <vector>
using namespace std;

template<typename T>
class myset
{
private:
	struct list
	{
		T data;
		list* next;
	};
	list* data;
	
	void insert(list* pos,const T& val);// вставлет val в след позицию
	void erase(list* pos); // удаляет элемент в следующей позиции
public:
	myset();
	myset(const myset& val);

	void add(const T& val);
	void del(const T& val);
	bool find(const T& val);
	bool is_empty();

	vector<T> get_data();

	void clear();

	~myset();
};
