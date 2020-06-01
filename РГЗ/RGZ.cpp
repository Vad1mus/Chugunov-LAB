#include "RGZ.h"

// Конструктор по-умолчанию
RGZ::RGZ() : Work()
{
	this->type = this->Type;
	this->id = this->id_gen;
	this->task = '\0';
	this->difficulty = 0;
}
// Конструктор с параметрами
RGZ::RGZ(string sub, string a, string tName, int m, string task, int diff)
	: Work(sub, a, tName, m)
{
	this->type = this->Type;
	this->id = this->id_gen;
	this->task = task;
	this->difficulty = diff;
}
// Деструктор
RGZ::~RGZ()
{
}
// Перегрузка оператора "<"
const bool & RGZ::operator<(const RGZ & obj) const
{
	bool expr = this->author < obj.get_autor()
		&& this->subjec < obj.get_subject()
		&& this->teachName < obj.get_teacherName()
		&& this->mark < obj.get_mark()
		&& this->task < obj.get_task()
		&& this->difficulty < obj.get_diff();
	return expr;
}
// Перегрузка оператора ">"
const bool & RGZ::operator>(const RGZ & obj) const
{
	bool expr = this->author > obj.get_autor()
		&& this->subjec > obj.get_subject()
		&& this->teachName > obj.get_teacherName()
		&& this->mark > obj.get_mark()
		&& this->task > obj.get_task()
		&& this->difficulty > obj.get_diff();
	return expr;
}
// Перегрузка оператора "=="
const bool & RGZ::operator==(const RGZ & obj) const
{
	bool expr = this->author == obj.get_autor()
		&& this->subjec == obj.get_subject()
		&& this->teachName == obj.get_teacherName()
		&& this->mark == obj.get_mark()
		&& this->task == obj.get_task()
		&& this->difficulty == obj.get_diff();
	return expr;
}
// Перегрузка оператора "<="
const bool & RGZ::operator<=(const RGZ & obj) const
{
	bool expr = this->author <= obj.get_autor()
		&& this->subjec <= obj.get_subject()
		&& this->teachName <= obj.get_teacherName()
		&& this->mark <= obj.get_mark()
		&& this->task <= obj.get_task()
		&& this->difficulty <= obj.get_diff();
	return expr;
}
// Перегрузка оператора ">="
const bool & RGZ::operator>=(const RGZ & obj) const
{
	bool expr = this->author >= obj.get_autor()
		&& this->subjec >= obj.get_subject()
		&& this->teachName >= obj.get_teacherName()
		&& this->mark >= obj.get_mark()
		&& this->task >= obj.get_task()
		&& this->difficulty >= obj.get_diff();
	return expr;
}
// Перегрузка оператора "<<"
ostream & RGZ::operator<<(const Work * obj)
{
	cout << "ID: " << obj->get_id() << endl
		<< "Type: " << obj->get_type() << endl
		<< "Предмет: " << obj->get_subject() << endl
		<< "Автор: " << obj->get_autor() << endl
		<< "Преподователь: " << obj->get_teacherName() << endl
		<< "Задание: " << obj->get_task() << endl
		<< "Сложность: " << obj->get_diff() << endl
		<< "Оценка: " << obj->get_mark() << endl;
	return cout;
}
// Перегрузка оператора ">>"
istream & operator>>(istream& is, RGZ & obj)
{
	cin.ignore(100500, '\n');
	cout << "Введите название предмета: ";
	std::getline(is, obj.subjec);
	cout << "Введите имя автора работы: ";
	std::getline(is, obj.author);
	cout << "Введите фамилию преподователя: ";
	std::getline(is, obj.teachName);
	cout << "Введите задание работы: ";
	std::getline(is, obj.task);
	cout << "Введите сложность задания: ";
	is >> obj.difficulty;
	cout << "Введите оценку: ";
	is >> obj.mark;
	return is;
}
