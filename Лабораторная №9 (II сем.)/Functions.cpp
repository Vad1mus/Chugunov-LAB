#include "Functions.h"

string SetInFilePath()
{
	string path;
	cout << "¬ведите путь ко входному файлу: ";
	getline(cin, path);
	return path;
}

string SetOutFilePath()
{
	string path;
	cout << "¬ведите путь к выходному файлу: ";
	getline(cin, path);
	return path;
}

int ReadFromFile(int** &in, int* &s, string path)
{
	ifstream file;
	file.exceptions(ifstream::badbit | ifstream::failbit);
	try 
	{
		file.open(path);
	}
	catch(const ifstream::failure& err)
	{
		cout << "ќшибка открыти€ файла.\n"; 
		cout << err.what() << endl;
		cout << err.code() << endl;
	}
	int size = 0;
	file >> size;
	in = new int* [size];
	s = new int[size];
	int temp = 0;
	int i = 0;
	while (i < size)
	{
		file >> temp;
		s[i] = temp;
		in[i] = new int[temp];
		for (int j = 0; j < temp; j++)
		{
			file >> in[i][j];
		}
		i++;
	}
	file.close();
	return size;
}

int max(int* &arr, int size)
{
	int max = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void FindMaxValues(int** &in, int* &out, int* &s, int size)
{
	out = new int[size];
	for (int i = 0; i < size; i++)
	{
		out[i] = max(in[i], s[i]);
	}
}

void WriteResults(int *& out, int size, string filename)
{
	ofstream file(filename);
	for (int i = 0; i < size; i++)
	{
		file << out[i] << " ";
	}
	file.close();
}

int GetElem(int index, int **& arr, int *& s, int size)
{
	int Size = 0;
	for (int i = 0; i < size; i++)
		Size += s[i];
	try
	{
		if (index < 0 && index >= Size)
			throw "Bad index.";
	}
	catch (char* Msg)
	{
		cout << "Error: " << Msg << endl;
	}
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		if (index < s[i] + temp)
			return arr[i][index-temp];
		else
			temp += s[i];
	}
}

void Print(int** &arr, int* &s, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < s[i]; j++)
		{
			cout << arr[i][j] << " ";
		}
	}
	cout << endl;
}