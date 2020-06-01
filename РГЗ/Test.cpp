#include "Test.h"

// ����������� ��-���������
Test::Test() : Work()
{
	this->type = this->Type;
	this->id = this->id_gen;
	this->theme = '\0';
	this->variant = 0;
}
// ����������� � �����������
Test::Test(string sub, string a, string tName, int m, string theme, int var)
	: Work (sub, a, tName, m)
{
	this->type = this->Type;
	this->id = this->id_gen;
	this->theme = theme;
	this->variant = var;
}
// ����������
Test::~Test()
{
}
// ���������� ��������� "<"
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
// ���������� ��������� ">"
const bool & Test::operator>(const Test & obj) const
{
	bool expr = !(Test::operator<(obj));
	return expr;
}
// ���������� ��������� "=="
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
// ���������� ��������� "<="
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
// ���������� ��������� ">="
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
// ���������� ��������� "<<"
ostream & Test::operator<<(const Work* obj)
{
	cout << "ID: " << obj->get_id() << endl
		<< "Type: " << obj->get_type() << endl
		<< "�������: " << obj->get_subject() << endl
		<< "�����: " << obj->get_autor() << endl
		<< "�������������: " << obj->get_teacherName() << endl
		<< "����: " << obj->get_theme() << endl
		<< "�������: " << obj->get_variant() << endl
		<< "������: " << obj->get_mark() << endl;
	return cout;
}
// ���������� ��������� ">>"
istream & operator>>(istream & is, Test & obj)
{
	cin.ignore(10, '\n');
	cout << "������� �������� ��������: ";
	std::getline(is, obj.subjec);
	cout << "������� ��� ������ ������: ";
	std::getline(is, obj.author);
	cout << "������� ������� �������������: ";
	std::getline(is, obj.teachName);
	cout << "������� ���� �����: ";
	std::getline(is, obj.theme);
	cout << "������� ����� ��������: ";
	is >> obj.variant;
	cout << "������� ������: ";
	is >> obj.mark;
	return is;
}
