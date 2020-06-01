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

// ������� ����������� ����� "������ ��������"
class Work
{
public:
	/* ������������, ���������� */
	// ����������� ��-���������
	Work();
	// ����������� � �����������
	Work(string sub, string a, string tName, int m);
	// ����������
	~Work();

	/* �������� ������� */
	// ��������� ID
	inline const int& get_id() const { return this->id; };
	// ��������� ����
	inline const string& get_type() const { return this->type; };
	
	/* ������� */
	// ��������� �������� ��������
	inline const string& get_subject() const { return this->subjec; };
	// ��������� ����� ������
	inline const string& get_autor() const { return this->author; };
	// ��������� ������� �������������
	inline const string& get_teacherName() const { return this->teachName; };
	// ��������� ������
	inline const int& get_mark() const { return this->mark; };

	/* ����������� ������ */
	// ��������� ���� �����
	virtual const string& get_theme() const = 0;
	// ��������� ������� ���
	virtual const string& get_task() const = 0;
	// ��������� �������� �����
	virtual const int& get_variant() const = 0;
	// ��������� ��������� ���
	virtual const int& get_diff() const = 0;

	/* ������� */
	// ������ ��� �������� ��������
	inline const void set_subject(const string &s) { this->subjec = s; };
	// ������ ��� ����� ������
	inline const void set_autor(const string &a) { this->author = a; };
	// ������ ��� ������� �������������
	inline const void set_teacherName(const string &t) { this->teachName = t; };
	// ������ ��� ������
	inline const void set_mark(const int &m) { this->mark = m; };
	
	// ����������� ��������������� ��������� ������
	virtual ostream& operator<< (const Work* work) = 0;

protected:
	/* �������� */
	// �������� ��������
	string subjec;
	// ��� ������
	string author;
	// ������� �������������
	string teachName;
	// ������
	int mark;

	/* �������������� */
	// ������������� ����
	string type;
	// ID
	int id;	

	// ��������� ��
	static int id_gen;
};