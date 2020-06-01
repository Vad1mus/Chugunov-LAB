#include "RGZ.h"

// ����������� ��-���������
RGZ::RGZ() : Work()
{
	this->type = this->Type;
	this->id = this->id_gen;
	this->task = '\0';
	this->difficulty = 0;
}
// ����������� � �����������
RGZ::RGZ(string sub, string a, string tName, int m, string task, int diff)
	: Work(sub, a, tName, m)
{
	this->type = this->Type;
	this->id = this->id_gen;
	this->task = task;
	this->difficulty = diff;
}
// ����������
RGZ::~RGZ()
{
}
// ���������� ��������� "<"
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
// ���������� ��������� ">"
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
// ���������� ��������� "=="
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
// ���������� ��������� "<="
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
// ���������� ��������� ">="
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
// ���������� ��������� "<<"
ostream & RGZ::operator<<(const Work * obj)
{
	cout << "ID: " << obj->get_id() << endl
		<< "Type: " << obj->get_type() << endl
		<< "�������: " << obj->get_subject() << endl
		<< "�����: " << obj->get_autor() << endl
		<< "�������������: " << obj->get_teacherName() << endl
		<< "�������: " << obj->get_task() << endl
		<< "���������: " << obj->get_diff() << endl
		<< "������: " << obj->get_mark() << endl;
	return cout;
}
// ���������� ��������� ">>"
istream & operator>>(istream& is, RGZ & obj)
{
	cin.ignore(100500, '\n');
	cout << "������� �������� ��������: ";
	std::getline(is, obj.subjec);
	cout << "������� ��� ������ ������: ";
	std::getline(is, obj.author);
	cout << "������� ������� �������������: ";
	std::getline(is, obj.teachName);
	cout << "������� ������� ������: ";
	std::getline(is, obj.task);
	cout << "������� ��������� �������: ";
	is >> obj.difficulty;
	cout << "������� ������: ";
	is >> obj.mark;
	return is;
}
