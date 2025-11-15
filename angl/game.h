#pragma once
#include "library.h"

void game() {
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
	string word_angl, word_rus; //Объявление временных переменных для записи слов в вектор
	vector <word> words; //Объявление вектора с словами

	//Заполнение вектора
	while (fin >> word_angl >> word_rus, word_angl != "0")
	{
		word current;
		current.word_angl = word_angl;

		vector <string> words_rus;//Добавление английского слова
		int i = 0;
		int k = 0;
		//Веделение всех русских слов
		while (word_rus[i] != '0') {
			if (word_rus[i] == ',') {
				words_rus.push_back(word_rus.substr(k, i - k));
				k = i + 1;
			}
			i++;
		}
		words_rus.push_back(word_rus.substr(k, i - k));
		//
		current.word_rus = words_rus;//Добавление русских слов
		words.push_back(current);
	}
	//

	int right = 0, wrong = 0;//Объявление переменных для записи количества верных и неверных ответов
	int n = words.size(); //Количество элементов в векторе слов
	string answer;//Объявление временной переменной для ответов
	vector <word> wrong_ans;//Объявление вектора неправильных ответов

	while (true) {
		//Генерация случайного индекса для вектора слов
		srand(time(NULL));
		int a = rand() % n;
		//cout << words[a].word_rus[0];
		//
		//Вывод английского слова и запись ответа пользователя на русском
		cout << words[a].word_angl << endl;
		cin >> answer;
		//
		//1Условие выхода из цикла
		if (answer == "stop") {
			system("cls"); //Отчистка консоли
			cout << right << " " << wrong << endl; //Вывод количества верных и неверных ответов
			//2Вывод всех неправильно написанных слов
			for (word& wrong : wrong_ans) {
				cout << wrong.word_angl << " "; //Вывод неправильного английского слова
				for (string& word_rus : wrong.word_rus)
					cout << word_rus << " "; // Вывод всех неправильных русских слов
				cout << endl;
			}
			//2
			return; //конец программы
		}
		//1
		//Проверка на совпадение хотябы одного русского слова из списка с ответом
		bool flag = false;
		for (string& word_r : words[a].word_rus)
			if (answer == word_r)
				flag = true;
		//
		//Подсчёт верных и неверных ответов и вывод правильного значения в случае неправильного ответа
		if (flag) {
			cout << "YES";
			right++;
		}
		else {
			wrong_ans.push_back(words[a]);
			for (string& word_r : words[a].word_rus) {
				cout << word_r << " "; //Выыод правильного ответа в случае ввода неправильного
			}
			cout << endl << "NO";
			wrong++;
		}
		//
		cout << endl << "-------------" << endl;//Разделитель 

	}
}
