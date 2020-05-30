#include "Functions.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	string filename = SetInFilePath();					// Записываем название входного файла
	int **InArray = { 0 };								// Входной массив
	int *sizes = { 0 };									// Кол-во эл-тов входного массива
	int size = ReadFromFile(InArray, sizes, filename);	// Чтение данных для массива из файла
	Print(InArray, sizes, size);						// Вывод массива на экран
	int *OutArray = { 0 };								// Выходной массив
	FindMaxValues(InArray, OutArray, sizes, size);		// Поиск максимальных значений
	filename = SetOutFilePath();						// Записываем название выходного файла
	WriteResults(OutArray, size, filename);				// Записываем данные выходного массива в файл
	cout << "Введите индекс: ";
	int index;
	cin >> index;
	cout << GetElem(index, InArray, sizes, size);		// Получение элемента по индексу

	delete[]OutArray;
	delete[]sizes;
	for (int i = 0; i < size; i++)
		delete[]InArray[i];
	delete[]InArray;
	cout << "\nПрограмма завершила свою работу.\nПроверьте содержимое файла: " << filename << endl << endl;
	system("PAUSE");
	return 0;
}