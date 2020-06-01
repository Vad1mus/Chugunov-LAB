#pragma once

#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::ostream;
using std::istream;
using std::stringstream;
using std::cout;
using std::cin;
using std::endl;

// Базовый абстрактный класс "Работа студента"
class Work
{
public:
	/* Конструкторы, деструктор */
	// Конструктор по-умолчанию
	Work();
	// Конструктор с параметрами
	Work(string sub, string a, string tName, int m);
	// Деструктор
	~Work();

	/* Получене доступа */
	// Получение ID
	inline const int& get_id() const { return this->id; };
	// Получение типа
	inline const string& get_type() const { return this->type; };
	
	/* Геттеры */
	// Получение названия предмета
	inline const string& get_subject() const { return this->subjec; };
	// Получение имени автора
	inline const string& get_autor() const { return this->author; };
	// Получение фамилии преподователя
	inline const string& get_teacherName() const { return this->teachName; };
	// Получение оценки
	inline const int& get_mark() const { return this->mark; };

	/* Виртуальные методы */
	// Получение темы теста
	virtual const string& get_theme() const = 0;
	// Получение заданий РГЗ
	virtual const string& get_task() const = 0;
	// Получение варианта теста
	virtual const int& get_variant() const = 0;
	// Получение сложности РГЗ
	virtual const int& get_diff() const = 0;

	/* Сеттеры */
	// Сеттер для названия предмета
	inline const void set_subject(const string &s) { this->subjec = s; };
	// Сеттер для имени автора
	inline const void set_autor(const string &a) { this->author = a; };
	// Сеттер для фамилии преподователя
	inline const void set_teacherName(const string &t) { this->teachName = t; };
	// Сеттер для оценки
	inline const void set_mark(const int &m) { this->mark = m; };
	
	// Виртуальное переопределение оператора вывода
	virtual ostream& operator<< (const Work* work) = 0;

protected:
	/* Описание */
	// Название предмета
	string subjec;
	// Имя автора
	string author;
	// Фамилия преподователя
	string teachName;
	// Оценка
	int mark;

	/* Идентификаторы */
	// Идентификатор типа
	string type;
	// ID
	int id;	

	// Генерация ИД
	static int id_gen;
};