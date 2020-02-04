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
	
	void insert(list* pos,const T& val);// �������� val � ���� �������
	void erase(list* pos); // ������� ������� � ��������� �������
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
