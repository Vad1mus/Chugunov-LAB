#pragma once
#include "Works.h"

// Класс "РГЗ" - наследник класса "Работа студента"
class RGZ : public Work
{
public:
	/* Конструкторы, деструктор */
	// Конструктор по-умолчанию
	RGZ();
	// Конмтруктор с параметрами
	RGZ(string sub, string a, string tName, int m, string task, int diff);
	// Деструктор
	~RGZ();

	/* Получение доступа */
	/* Геттеры */
	// Переопределённое получение задания РГЗ
	inline const string& get_task() const override { return this->task; };
	// Переопределённое получение сложности РГЗ
	inline const int& get_diff() const override { return this->difficulty; };
	// Переопределённое получение темы теста
	inline const string& get_theme() const override { return ""; };
	// Переопределённое получение варианта студента
	inline const int& get_variant() const override { return 0; };

	/* Сеттеры */
	// Сеттер для задания РГЗ
	inline const void set_task(const string &t) { this->task = t; };
	// Сеттер для сложносты РГЗ
	inline const void set_diff(const int &d) { this->difficulty = d; };

	/* Операторы */
	// Переопределение оператора "<"
	const bool& operator< (const RGZ& obj) const;
	// Переопределение оператора ">"
	const bool& operator> (const RGZ& obj) const;
	// Переопределение оператора "=="
	const bool& operator== (const RGZ& obj) const;
	// Переопределение оператора "<="
	const bool& operator<= (const RGZ& obj) const;
	// Переопределение оператора ">="
	const bool& operator>= (const RGZ& obj) const;
	// Переопределение оператора "<<"
	ostream& operator<< (const Work* obj) override;
	// Переопределение оператора ">>"
	friend istream& operator>> (istream& is, RGZ& obj);

private:
	/* Описание */
	// Задание РГЗ
	string task;
	// Сложносит РГЗ
	int difficulty;

	/* Идентификаторы */
	// Идентификатор типа
	static string Type;
};

/* Операторы */
// Переопределение оператора >>
istream& operator>> (istream& is, RGZ& obj);