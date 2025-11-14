#include "library.h"

int main() {
	//Изменение таблицы кодировки
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	//
	string word_angl, word_rus; //Объявление временных переменных для записи слов в вектор
	vector <word> words; //Объявление вектора с словами

	//Заполнение вектора
	while (fin >> word_angl >> word_rus, word_angl != "0")
	{
		word current;
		current.word_angl = word_angl;
		current.word_rus = word_rus;

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
		//
		//Вывод английского слова и запись ответа пользователя на русском
		cout << words[a].word_angl << endl;
		cin >> answer;
		//
		//1Условие выхода из цикла
		if (answer == "stop") {
			system("cls"); //Отчистка консоли
			cout << right << " " << wrong<<endl; //Вывод количества верных и неверных ответов
			//2Вывод всех неправильно написанных слов
			for (word &x : wrong_ans) {
				cout << x.word_angl << " " << x.word_rus << endl;
			}
			//2
			return 0; //конец программы
		}
		//1
		//Подсчёт верных и неверных ответов и вывод правильного значения в случае неправильного ответа
		if (answer == words[a].word_rus) {
			cout << "YES";
			right++;
		}
		else {
			wrong_ans.push_back(words[a]);
			cout << words[a].word_rus <<endl<<"NO";
			wrong++;
		}
		//
		cout << endl <<"-------------"<<endl;//Разделитель 
		
	}
}