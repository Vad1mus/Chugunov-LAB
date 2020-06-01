#pragma once
#include "Controller.h"

// Класс "Диалоговое меню"
class Dialog
{
public:
	/* Конструкторы, деструктор */
	// Конструктор по-умолчанию
	Dialog();
	// Деструктор
	~Dialog();

	// Запуск диалогового меню
	void Run();

private:
	/* Описание */
	// Переменная, виполняющая действия над иерархией классов
	Controller Cller;

	// Главное меню
	int MainMenu();
	// Выбор критерия сортировки
	int SortingSelect();
	// Выбор критерия поиска
	int SearchSelect();
};