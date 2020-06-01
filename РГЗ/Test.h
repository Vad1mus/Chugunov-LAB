#pragma once
#include "Works.h"

// Класс "Тест" - наследник класса "Работа студента"
class Test : public Work
{
public:
	/* Конструкторы, деструктор */
	// Конструктор по-умолчанию
	Test();
	// Конструктор с параметрами
	Test(string sub, string a, string tName, int m, string theme, int var);
	// Деструктор
	~Test();

	/* Получение доступа */
	/* Геттеры */
	// Переопределённое получение темы теста
	inline const string& get_theme() const override { return this->theme; };
	// Переопределённое получение варианта студента
	inline const int& get_variant() const override { return this->variant; };
	// Переопределённое получение задания РГЗ
	inline const string& get_task() const override { return ""; };
	// Переопределённое получение сложности РГЗ
	inline const int& get_diff() const override { return 0; };

	/* Сеттеры */
	// Сеттер для темы теста
	inline const void set_theme(const string &th) { this->theme = th; };
	// Сеттер для варианта
	inline const void set_variant(const int &var) { this->variant = var; };

	/* Операторы */
	// Переопределение оператора ">"
	const bool& operator< (const Test& obj) const;
	// Переопределение оператора "<"
	const bool& operator> (const Test& obj) const;
	// Переопределение оператора "=="
	const bool& operator== (const Test& obj) const;
	// Переопределение оператора "<="
	const bool& operator<= (const Test& obj) const;
	// Переопределение оператора ">="
	const bool& operator>= (const Test& obj) const;
	// Переопределение оператора "<<"
	ostream& operator<< (const Work* obj) override;
	// Переопределение оператора ">>"
	friend istream& operator>> (istream& is, Test& obj);

private:
	/* Описание */
	// Тема теста
	string theme;
	// Вариант теста
	int variant;
	
	/* Идентификаторы */
	// Идентификатор типа
	static string Type;
};

/* Операторы */
// Переопределение оператора ">>"
istream& operator>> (istream& is, Test& obj);