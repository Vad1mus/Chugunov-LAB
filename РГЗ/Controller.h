#pragma once
#include <algorithm>
#include <vector>
#include <Windows.h>
#include "RGZ.h"
#include "Test.h"

using std::vector;
using std::sort;
using std::copy_if;
using std::back_inserter;

// Класс "Контроллер"
class Controller
{
public:
	/* Конструкторы, деструктор */
	// Конструктор по-умолчанию
	Controller();
	// Деструктор
	~Controller();

	/* Методы */
	// Добавление РГЗ
	void AddRGZ();
	// Добавление Теста
	void AddTest();
	// Удаление работы
	void DeleteWork();
	// Вывод работ на экран
	void ShowAll();
	// Сортировка набора
	void Sorting(int ch);
	// Поиск работ
	void Search(int ch);
	// Выполнение задания
	void Task();

private:
	/* Описание */
	// Вектор, состоящий из работ
	vector<Work*> works;
};

// Предикатор сортировки по предмету мин-макс 
class SortingMinMaxSubject
{
public:
	bool operator() (const Work *a, const Work *b) { return a->get_subject() < b->get_subject(); };
};

// Предикатор сортировки по предмету макс-мин
class SortingMaxMinSubject
{
public:
	bool operator() (const Work *a, const Work *b) { return a->get_subject() > b->get_subject(); };
};

// Предикатор сортировки по автору мин-макс 
class SortingMinMaxAutor
{
public:
	bool operator() (const Work *a, const Work *b) { return a->get_autor() < b->get_autor(); };
};

// Предикатор сортировки по автору макс-мин
class SortingMaxMinAutor
{
public:
	bool operator() (const Work *a, const Work *b) { return a->get_autor() > b->get_autor(); };
};

// Предикатор сортировки по оценке мин-макс 
class SortingMinMaxMark
{
public:
	bool operator() (const Work *a, const Work *b) { return a->get_mark() < b->get_mark(); };
};

// Предикатор сортировки по оценке макс-мин
class SortingMaxMinMark
{
public:
	bool operator() (const Work *a, const Work *b) { return a->get_mark() > b->get_mark(); };
};

// Функция смены цвета консоли
void SetColor(int text, int background);
// Проверка выбора варианта
bool CheckSelect(int b, int e, int i);
// Уведомление об успешной операции
void OperationPass();
// Уведомление об отмене операции
void OperationCancel();
// Информация о работе
void Info();