#include <iostream>

class Unit
{
	const char *name;
	int healPoints;

public:
	Unit() : name("Archer"), healPoints(100) {}
};

void *operator new(size_t size)
{
	std::cout << "New\n";
	void *p;
	p = malloc(size);
	return p;
}

void *operator new[](size_t size)
{
	std::cout << "New[]\n";
	void *p;
	p = malloc(size);
	return p;
}

void operator delete(void *p)
{
	std::cout << "Delete\n";
	free(p);
}

void operator delete[](void *p)
{
	std::cout << "Delete[]\n";
	free(p);
}

int main()
{
	Unit *archers;
	archers = new Unit[5];
	delete[] archers;

	Unit *archer;
	archer = new Unit;
	delete archer;

	system("pause");
	return 0;
}