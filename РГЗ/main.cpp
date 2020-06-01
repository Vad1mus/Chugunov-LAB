#include "Settings.h"
#include "Dialog.h"

int main()
{
	setlocale(LC_ALL, "rus");
	// Создание объэкта класса Dialog
	Dialog Cller;
	// Выполнение метода Run
	Cller.Run();

	system("PAUSE");
	return 0;
}