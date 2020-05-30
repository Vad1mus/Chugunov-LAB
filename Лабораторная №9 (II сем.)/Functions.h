#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Ввод названия входного файла
string SetInFilePath();
//Ввод названия выходного файла
string SetOutFilePath();
//Чтение входного файла
int ReadFromFile(int** &in, int* &s, string path);
int max(int* &arr, int size);
//Поиск максимальных значений
void FindMaxValues(int** &in, int* &out, int* &s, int size);
//Запись результатов в выходной файл
void WriteResults(int* &out, int size, string filename);
//Получение значения массива по индексу
int GetElem(int index, int** &arr, int* &s, int size);
//Вывод содержимого массива на экран
void Print(int** &arr, int* &s, int size);
