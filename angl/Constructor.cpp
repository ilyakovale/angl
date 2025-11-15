#include "library.h"

int main() {
	//Изменение таблицы кодировки
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//
	//Выбор файла со словами
	char choice;
	cout << "Выберите часть речи" << endl << "1.Общее" << endl;
	cin >> choice;
	string file_name;
	switch (choice) {
	case '1':
		file_name = "words.txt";
		break;
	}
	ifstream fin(file_name);
	system("cls");
	//
	//Ввод искомого слова
	string target;
	cout << "Введите искомое английское слово"<<endl;
	cin >> target;
	//
	return 0;
}