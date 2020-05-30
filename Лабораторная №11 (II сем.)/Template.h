#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template<typename T, int size>
class Template
{
public:
	Template();
	Template(const T *a);
	~Template();

	void ShowArray();
	void SortArray();
	int GetIndex(const T elem);
	T Min();
private:
	T *arr;
};

template<typename T, int size>
inline Template<T, size>::Template()
{
	arr = new T[size];
}

template<typename T, int size>
inline Template<T, size>::Template(const T *a)
{
	arr = new T[size];
	for (int i = 0; i < size; i++)
		arr[i] = a[i];
}

template<typename T, int size>
void Template<T, size>::ShowArray()
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << '\t';
}

template<typename T, int size>
void Template<T, size>::SortArray()
{
	T temp;
	for (int i = 1, j; i < size; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = temp;
	}
}

template<typename T, int size>
int Template<T, size>::GetIndex(const T elem)
{
	for (int i = 0; i < size; i++)
		if (arr[i] == elem)
			return i;
	return -1;
}

template<typename T, int size>
inline T Template<T, size>::Min()
{
	T min = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] < min)
			min = arr[i];
	return min;
}

template<typename T, int size>
inline Template<T, size>::~Template()
{
	delete[] arr;
}
