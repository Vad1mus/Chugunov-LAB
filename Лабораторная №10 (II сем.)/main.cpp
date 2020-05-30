#include "Template.h"
#include "Point.h"

int main()
{
	const int size = 5;

	cout << "#############################################\n";
	Template<int> ITemp;
	int intArr[size] = { 5, 84, 2, 46, 35 };
	cout << "Array of integers:\n";
	ITemp.ShowArray(intArr, size);
	ITemp.SortArray(intArr, size);
	cout << "\nSorted array:\n";
	ITemp.ShowArray(intArr, size);
	cout << "\nGet index by value: 46 = ";
	printf("intArr[%d]\n", ITemp.GetIndex(intArr, 46, size));
	cout << "Minimal value: " << ITemp.Min(intArr, size) << endl;
	cout << "#############################################\n";

	Template<double> FTemp;
	double doubleArr[size] = { 8.45, 6.16, 7.95, 3.65, 5.72 };
	cout << "Array of real numbers:\n";
	FTemp.ShowArray(doubleArr, size);
	FTemp.SortArray(doubleArr, size);
	cout << "\nSorted array:\n";
	FTemp.ShowArray(doubleArr, size);
	cout << "\nGet index by value: 6.49 = ";
	printf("floatArr[%d]\n", FTemp.GetIndex(doubleArr, 6.49, size));
	cout << "Minimal value: " << FTemp.Min(doubleArr, size) << endl;
	cout << "#############################################\n";

	Template<char> CTemp;
	char charArr[size] = "Hola";
	cout << "Array of chars:\n";
	CTemp.ShowArray(charArr, size);
	CTemp.SortArray(charArr, size);
	cout << "\nSorted array:\n";
	CTemp.ShowArray(charArr, size);
	cout << "\nGet index by value: o = ";
	printf("charArr[%d]\n", CTemp.GetIndex(charArr, 'o', size));
	cout << "Minimal value: " << CTemp.Min(charArr, size) << endl;
	cout << "#############################################\n";

	Template<Point> PTemp;
	Point pointArr[size] = { {0, 1}, {5, 6}, {3, 4}, {2, 1}, {1, 7} };
	cout << "Array of points:\n";
	PTemp.ShowArray(pointArr, size);
	PTemp.SortArray(pointArr, size);
	cout << "\nSorted array:\n";
	PTemp.ShowArray(pointArr, size);
	cout << "\nGet index by value: (3 ; 4) = ";
	printf("pointArr[%d]\n", PTemp.GetIndex(pointArr, {3, 4}, size));
	cout << "Minimal value: " << PTemp.Min(pointArr, size) << endl;
	cout << "#############################################\n";
	system("PAUSE");
	return 0;
}