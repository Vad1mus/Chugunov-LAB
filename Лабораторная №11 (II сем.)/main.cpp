#include "Template.h"
#include "Point.h"

int main()
{
	const int size = 5;

	cout << "#############################################\n";
	int intArr[size] = { 5, 84, 2, 46, 35 };
	Template<int, size> ITemp = intArr;
	cout << "Array of integers:\n";
	ITemp.ShowArray();
	ITemp.SortArray();
	cout << "\nSorted array:\n";
	ITemp.ShowArray();
	cout << "\nGet index by value: 46 = ";
	printf("intArr[%d]\n", ITemp.GetIndex(46));
	cout << "Minimal value: " << ITemp.Min() << endl;
	cout << "#############################################\n";

	double doubleArr[size] = { 8.45, 6.16, 7.95, 3.65, 5.72 };
	Template<double, size> FTemp = doubleArr;
	cout << "Array of real numbers:\n";
	FTemp.ShowArray();
	FTemp.SortArray();
	cout << "\nSorted array:\n";
	FTemp.ShowArray();
	cout << "\nGet index by value: 6.49 = ";
	printf("floatArr[%d]\n", FTemp.GetIndex(6.49));
	cout << "Minimal value: " << FTemp.Min() << endl;
	cout << "#############################################\n";

	char charArr[size] = "Hola";
	Template<char, size> CTemp = charArr;
	cout << "Array of chars:\n";
	CTemp.ShowArray();
	CTemp.SortArray();
	cout << "\nSorted array:\n";
	CTemp.ShowArray();
	cout << "\nGet index by value: o = ";
	printf("charArr[%d]\n", CTemp.GetIndex('o'));
	cout << "Minimal value: " << CTemp.Min() << endl;
	cout << "#############################################\n";

	Point pointArr[size] = { {0, 1}, {5, 6}, {3, 4}, {2, 1}, {1, 7} };
	Template<Point, size> PTemp = pointArr;
	cout << "Array of points:\n";
	PTemp.ShowArray();
	PTemp.SortArray();
	cout << "\nSorted array:\n";
	PTemp.ShowArray();
	cout << "\nGet index by value: (3 ; 4) = ";
	printf("pointArr[%d]\n", PTemp.GetIndex({3, 4}));
	cout << "Minimal value: " << PTemp.Min() << endl;
	cout << "#############################################\n";
	system("PAUSE");
	return 0;
}