// Term3_Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include "Set.h"
#include "myset.h"
#include "myset.cpp"
using namespace std;

void print_prime(ostream& os, int k)
{
	if (k < 0) return;
	Set s(k + 1, true);
	for (int i = 2; i <= k; ++i)
	{
		if (s.is_here(i))
		{
			for (int j = i * i; j <= k; j += i)
				s.del(j);

			os << i << ' ';
		}
	}
	os << endl;
}

void print_prime_myset(ostream& os, int k)
{
	if (k < 0) return;
	myset<int> s;
	for (int i = 1; i <= k; ++i) s.add(i);
	for (int i = 2; i <= k; ++i)
	{
		if (s.find(i))
		{
			for (int j = i * i; j <= k; j += i)
				s.del(j);

			os << i << ' ';
		}
	}
	os << endl;
}

int main()
{
	ofstream out("out.txt");
	int k = 0;
	cout << "Please enter k:";
	cin >> k;
	print_prime(out, k);
	
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
