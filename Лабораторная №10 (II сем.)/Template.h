#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template<typename T>
class Template
{
public:
	Template();

	void ShowArray(const T *arr, const int size);
	void SortArray(T * arr, const int size);
	int GetIndex(const T *arr, const T elem, const int size);
	T Min(const T *arr, const int size);
};

template<typename T>
inline Template<T>::Template()
{
}

template<typename T>
void Template<T>::ShowArray(const T * arr, const int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << '\t';
}

template<typename T>
void Template<T>::SortArray(T * arr, const int size)
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

template<typename T>
int Template<T>::GetIndex(const T * arr, const T elem, const int size)
{
	for (int i = 0; i < size; i++)
		if (arr[i] == elem)
			return i;
	return -1;
}

template<typename T>
inline T Template<T>::Min(const T * arr, const int size)
{
	T min = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] < min)
			min = arr[i];
	return min;
}

