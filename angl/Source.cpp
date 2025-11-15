#include "game.h"
#include "editor_mode.h"

int main() {
	SetConsoleOutputCP(1251);
	char choice;
	cout << "Введите режим программы" << endl << "1.Игра" << endl << "2.Редактирование" << endl;;
	cin >> choice;
	switch (choice)
	{
	case '1':
		game();
		break;
	case '2':
		editor_mode();
		break;

	default:
		system("cls");
		cout << "Неправильные данные";
		return 0;
	}
	return 0;
}