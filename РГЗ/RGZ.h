#pragma once
#include "Works.h"

// ����� "���" - ��������� ������ "������ ��������"
class RGZ : public Work
{
public:
	/* ������������, ���������� */
	// ����������� ��-���������
	RGZ();
	// ����������� � �����������
	RGZ(string sub, string a, string tName, int m, string task, int diff);
	// ����������
	~RGZ();

	/* ��������� ������� */
	/* ������� */
	// ��������������� ��������� ������� ���
	inline const string& get_task() const override { return this->task; };
	// ��������������� ��������� ��������� ���
	inline const int& get_diff() const override { return this->difficulty; };
	// ��������������� ��������� ���� �����
	inline const string& get_theme() const override { return ""; };
	// ��������������� ��������� �������� ��������
	inline const int& get_variant() const override { return 0; };

	/* ������� */
	// ������ ��� ������� ���
	inline const void set_task(const string &t) { this->task = t; };
	// ������ ��� ��������� ���
	inline const void set_diff(const int &d) { this->difficulty = d; };

	/* ��������� */
	// ��������������� ��������� "<"
	const bool& operator< (const RGZ& obj) const;
	// ��������������� ��������� ">"
	const bool& operator> (const RGZ& obj) const;
	// ��������������� ��������� "=="
	const bool& operator== (const RGZ& obj) const;
	// ��������������� ��������� "<="
	const bool& operator<= (const RGZ& obj) const;
	// ��������������� ��������� ">="
	const bool& operator>= (const RGZ& obj) const;
	// ��������������� ��������� "<<"
	ostream& operator<< (const Work* obj) override;
	// ��������������� ��������� ">>"
	friend istream& operator>> (istream& is, RGZ& obj);

private:
	/* �������� */
	// ������� ���
	string task;
	// ��������� ���
	int difficulty;

	/* �������������� */
	// ������������� ����
	static string Type;
};

/* ��������� */
// ��������������� ��������� >>
istream& operator>> (istream& is, RGZ& obj);