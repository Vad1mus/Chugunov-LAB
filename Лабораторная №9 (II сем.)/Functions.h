#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//���� �������� �������� �����
string SetInFilePath();
//���� �������� ��������� �����
string SetOutFilePath();
//������ �������� �����
int ReadFromFile(int** &in, int* &s, string path);
int max(int* &arr, int size);
//����� ������������ ��������
void FindMaxValues(int** &in, int* &out, int* &s, int size);
//������ ����������� � �������� ����
void WriteResults(int* &out, int size, string filename);
//��������� �������� ������� �� �������
int GetElem(int index, int** &arr, int* &s, int size);
//����� ����������� ������� �� �����
void Print(int** &arr, int* &s, int size);
