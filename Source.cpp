#include <iostream>
#include <windows.h>
#include <vector>
#include <list>
#include <fstream>
#include <algorithm>
#include <string>
#include <deque>
#include <algorithm>
#include <iterator>
using namespace std;
template <typename Container>

void input(Container& container)
{
	int size;
	cout << "Введите длину: ";
	cin >> size;
	cout << "Введите элементы: ";
	for (int i = 0; i < size; ++i)
	{
		int element;
		cin >> element;
		container.push_back(element);
	}
}

template <typename Container>
void print(const Container& container)
{
	for (const auto& element : container)
	{
		cout << element << " ";
	}
	cout << endl;
}

void rearrangeVector(vector<int> V) 
{
	int n = V.size();
	if (n == 0) return;
	vector<int> result;
	int mid = n / 2;
	for (int i = mid; i < n; i++) {
		result.push_back(V[i]);
	}
	for (int i = 0; i < mid; i++) {
		result.push_back(V[i]);
	}
	print(result);
}

void insertmid(list<int>& L1, list<int>& L2)
{
	auto mid = L1.begin();
	advance(mid, L1.size() / 2);
	L2.splice(L2.end(), L1, mid);
}

void remove_last_zero(deque<int>& d) 
{
	auto it = find(d.rbegin(), d.rend(), 0);
	if (it != d.rend()) 
	{
		d.erase((++it).base());
	}
}

void copy_and_reverse_half(list<int>& L) 
{
	if (L.size() % 2 != 0) 
	{
		cout << "Список должен содержать ЧЕТНОЕ количество элементов";
	}
	auto mid = next(L.begin(), L.size() / 2);
	list<int> temp;
	replace_copy_if(L.begin(), mid, back_inserter(temp), [](int n) { return n < 0; }, 0);
	for (auto it = temp.rbegin(); it != temp.rend(); ++it) 
	{
		L.push_back(*it);
	}
}

void rearrange_list(std::list<int>& L) 
{
	// Убедимся, что список четный
	if (L.size() % 2 != 0) 
	{
		cout << "Список должен содержать ЧЕТНОЕ количество элементов.\n";
	}

	// Находим середину списка
	auto mid = next(L.begin(), L.size() / 2);

	// Сначала перегруппируем четные и нечетные элементы первой половины
	list<int> first_half(L.begin(), mid);
	stable_partition(first_half.begin(), first_half.end(),
		[](int n) { return n % 2 == 0; });

	// Затем перегруппируем четные и нечетные элементы второй половины
	list<int> second_half(mid, L.end());
	stable_partition(second_half.begin(), second_half.end(),
		[](int n) { return n % 2 == 0; });

	// Очищаем оригинальный список и добавляем элементы в нужном порядке
	L.clear();
	L.insert(L.end(), first_half.begin(), first_half.end());
	L.insert(L.end(), second_half.begin(), second_half.end());
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<int> V;
	list<int> L;
	list<int> L1;
	list<int> L2;
	deque<int> d;
	int a;
	cout << "Номера заданий:\n1 2 3 4 5 6 7 8 9 10 \nВыберите номер задания:";
	cin >> a;
	switch (a)
	{
	case 1:
	{
		cout << "Введите вектор с ЧЕТНЫМ количеством символов!" << endl;
		input(V);
		if ((V.size() % 2 != 0) || (V.size() < 0))
		{
			cout << "Вектор должен содержать четное количество элементов";
			break;
		}
		rearrangeVector(V);
		break;
	}
	case 2:
	{
		input(V);
		for (auto i = V.begin(); i != V.end(); ++i)
		{
			i = V.insert(++i, -1);
		}
		print(V);
		break;
	}
	case 3:
	{
		cout << "Введите список с НЕЧЕТНЫМ колличеством элементов!" << endl;
		input(L1);
		if ((L1.size() % 2 == 0) || (L1.size() < 0))
		{
			cout << "Колличество элементов списка должно быть нечетно!";
			break;
		}
		input(L2);
		insertmid(L1, L2);
		print(L2);
		break;
	}
	case 4:
	{
		string name = "name";
		int K;
		cout << "Введите К:";
		cin >> K;
		ofstream outFile(name);
		if (outFile.is_open()) 
		{
			string stars(K, '*');
			fill_n(stars.begin(), K, '*');
			outFile << stars; 
			outFile.close(); 
			cout << "Записано " << K << " символов '*' в файл " << name << endl;
		}
		else 
		{
			cout << "Не удалось открыть файл для записи." << endl;
		}
		break;
	}
	case 5:
	{
		input(d);
		remove_last_zero(d);
		print(d);
		break;
	}
	case 6:
	{
		cout << "Введите список с ЧЕТНЫМ колличеством элементов" << endl;
		input(L);
		copy_and_reverse_half(L);
		print(L);
		break;
	}
	case 7:
	{
		cout << "Введите список с ЧЕТНЫМ колличеством элементов" << endl;
		input(L);
		rearrange_list(L);
		print(L);
		break;
	}
	}
}
