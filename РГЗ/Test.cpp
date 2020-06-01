#include "Test.h"

// Конструктор по-умолчанию
Test::Test() : Work()
{
	this->type = this->Type;
	this->id = this->id_gen;
	this->theme = '\0';
	this->variant = 0;
}
// Конструктор с параметрами
Test::Test(string sub, string a, string tName, int m, string theme, int var)
	: Work (sub, a, tName, m)
{
	this->type = this->Type;
	this->id = this->id_gen;
	this->theme = theme;
	this->variant = var;
}
// Деструктор
Test::~Test()
{
}
// Перегрузка оператора "<"
const const bool & Test::operator<(const Test & obj) const
{
	bool expr = this->author < obj.get_autor()
		&& this->subjec < obj.get_subject()
		&& this->teachName < obj.get_teacherName()
		&& this->mark < obj.get_mark()
		&& this->theme < obj.get_theme()
		&& this->variant < obj.get_variant();
	return expr;
}
// Перегрузка оператора ">"
const bool & Test::operator>(const Test & obj) const
{
	bool expr = !(Test::operator<(obj));
	return expr;
}
// Перегрузка оператора "=="
const bool & Test::operator==(const Test & obj) const
{
	bool expr = this->author == obj.get_autor()
		&& this->subjec == obj.get_subject()
		&& this->teachName == obj.get_teacherName()
		&& this->mark == obj.get_mark()
		&& this->theme == obj.get_theme()
		&& this->variant == obj.get_variant();
	return expr;
}
// Перегрузка оператора "<="
const bool & Test::operator<=(const Test & obj) const
{
	bool expr = this->author <= obj.get_autor()
		&& this->subjec <= obj.get_subject()
		&& this->teachName <= obj.get_teacherName()
		&& this->mark <= obj.get_mark()
		&& this->theme <= obj.get_theme()
		&& this->variant <= obj.get_variant();
	return expr;
}
// Перегрузка оператора ">="
const bool & Test::operator>=(const Test & obj) const
{
	bool expr = this->author >= obj.get_autor()
		&& this->subjec >= obj.get_subject()
		&& this->teachName >= obj.get_teacherName()
		&& this->mark >= obj.get_mark()
		&& this->theme >= obj.get_theme()
		&& this->variant >= obj.get_variant();
	return expr;
}
// Перегрузка оператора "<<"
ostream & Test::operator<<(const Work* obj)
{
	cout << "ID: " << obj->get_id() << endl
		<< "Type: " << obj->get_type() << endl
		<< "Предмет: " << obj->get_subject() << endl
		<< "Автор: " << obj->get_autor() << endl
		<< "Преподователь: " << obj->get_teacherName() << endl
		<< "Тема: " << obj->get_theme() << endl
		<< "Вариант: " << obj->get_variant() << endl
		<< "Оценка: " << obj->get_mark() << endl;
	return cout;
}
// Перегрузка оператора ">>"
istream & operator>>(istream & is, Test & obj)
{
	cin.ignore(10, '\n');
	cout << "Введите название предмета: ";
	std::getline(is, obj.subjec);
	cout << "Введите имя автора работы: ";
	std::getline(is, obj.author);
	cout << "Введите фамилию преподователя: ";
	std::getline(is, obj.teachName);
	cout << "Введите тему теста: ";
	std::getline(is, obj.theme);
	cout << "Введите номер варианта: ";
	is >> obj.variant;
	cout << "Введите оценку: ";
	is >> obj.mark;
	return is;
}
