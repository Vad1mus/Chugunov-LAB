#include "Functions.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	string filename = SetInFilePath();					// ���������� �������� �������� �����
	int **InArray = { 0 };								// ������� ������
	int *sizes = { 0 };									// ���-�� ��-��� �������� �������
	int size = ReadFromFile(InArray, sizes, filename);	// ������ ������ ��� ������� �� �����
	Print(InArray, sizes, size);						// ����� ������� �� �����
	int *OutArray = { 0 };								// �������� ������
	FindMaxValues(InArray, OutArray, sizes, size);		// ����� ������������ ��������
	filename = SetOutFilePath();						// ���������� �������� ��������� �����
	WriteResults(OutArray, size, filename);				// ���������� ������ ��������� ������� � ����
	cout << "������� ������: ";
	int index;
	cin >> index;
	cout << GetElem(index, InArray, sizes, size);		// ��������� �������� �� �������

	delete[]OutArray;
	delete[]sizes;
	for (int i = 0; i < size; i++)
		delete[]InArray[i];
	delete[]InArray;
	cout << "\n��������� ��������� ���� ������.\n��������� ���������� �����: " << filename << endl << endl;
	system("PAUSE");
	return 0;
}