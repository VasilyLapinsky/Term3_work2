#include "myset.h"
// private Методы
template<typename T>
void myset<T>::insert(list* pos, const T& val)
{
	pos->next = new list{ val, pos->next };
}

template<typename T>
void myset<T>::erase(list* pos)
{
	if (pos->next == nullptr) return;
	if (pos->next == data)
	{
		list* deleted = data;
		data = data->next;
		delete deleted;
	}
	else
	{
		list* deleted = pos->next;
		pos->next = pos->next->next;
		delete deleted;
	}

}

// Конструкторы
template<typename T>
myset<T>::myset() : data{ nullptr } { }
template<typename T>
myset<T>::myset(const myset& val) 
{
	if (val.data == nullptr)
	{
		data = nullptr;
		return;
	}
	data = new list{ val.data->data, nullptr };
	list* l = data;
	list* r = val.data->next;
	while (r)
	{
		l->next = new list(r->data, nullptr);
		l = l->next;
		r = r->next;
	}
}

// public Методы
template<typename T>
void myset<T>::add(const T& val)
{
	if (data == nullptr || val < data->data)
	{
		data = new list{ val,data };
		return;
	}
	list* x = data;
	while (x->next != nullptr)
	{
		if (!(val > x->next->data))
		{
			if (val != x->next->data) insert(x, val);
			break;
		}
		x = x->next;
	}
	if (x->next == nullptr)
	{
		x->next = new list{ val, nullptr };
	}
}
template<typename T>
void myset<T>::del(const T& val)
{
	if (is_empty()) return;
	if (val == data->data)
	{
		list* deleted = data;
		data = data->next;
		delete deleted;
	}
	auto x = data;
	while (x->next != nullptr)
	{
		if (!(val > x->next->data))
		{
			if (val == x->next->data) erase(x);
			break;
		}
		x = x->next;
	}
}
template<typename T>
bool myset<T>::find(const T& val)
{
	list* x = data;
	while (x != nullptr && val > x->data)
		x = x->next;
	return !(x == nullptr || val != x->data);
}
template<typename T>
bool myset<T>::is_empty()
{
	return data == nullptr;
}

template<typename T>
vector<T> myset<T>::get_data()
{
	vector<T> res;
	list* p = data;
	while (p)
	{
		res.push_back(p->data);
		p = p->next;
	}
	return res;
}

template<typename T>
void myset<T>::clear()
{
	while (data)
	{
		list* deleted = data;
		data = data->next;
		delete deleted;
	}
}

// деструктор
template<typename T>
myset<T>::~myset()
{
	clear();
}