#pragma once
#include "Works.h"

// ����� "����" - ��������� ������ "������ ��������"
class Test : public Work
{
public:
	/* ������������, ���������� */
	// ����������� ��-���������
	Test();
	// ����������� � �����������
	Test(string sub, string a, string tName, int m, string theme, int var);
	// ����������
	~Test();

	/* ��������� ������� */
	/* ������� */
	// ��������������� ��������� ���� �����
	inline const string& get_theme() const override { return this->theme; };
	// ��������������� ��������� �������� ��������
	inline const int& get_variant() const override { return this->variant; };
	// ��������������� ��������� ������� ���
	inline const string& get_task() const override { return ""; };
	// ��������������� ��������� ��������� ���
	inline const int& get_diff() const override { return 0; };

	/* ������� */
	// ������ ��� ���� �����
	inline const void set_theme(const string &th) { this->theme = th; };
	// ������ ��� ��������
	inline const void set_variant(const int &var) { this->variant = var; };

	/* ��������� */
	// ��������������� ��������� ">"
	const bool& operator< (const Test& obj) const;
	// ��������������� ��������� "<"
	const bool& operator> (const Test& obj) const;
	// ��������������� ��������� "=="
	const bool& operator== (const Test& obj) const;
	// ��������������� ��������� "<="
	const bool& operator<= (const Test& obj) const;
	// ��������������� ��������� ">="
	const bool& operator>= (const Test& obj) const;
	// ��������������� ��������� "<<"
	ostream& operator<< (const Work* obj) override;
	// ��������������� ��������� ">>"
	friend istream& operator>> (istream& is, Test& obj);

private:
	/* �������� */
	// ���� �����
	string theme;
	// ������� �����
	int variant;
	
	/* �������������� */
	// ������������� ����
	static string Type;
};

/* ��������� */
// ��������������� ��������� ">>"
istream& operator>> (istream& is, Test& obj);