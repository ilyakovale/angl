#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <vector>
#include <random>

using namespace std;

ifstream fin("words.txt");

struct word {
	string word_angl;
	vector <string> word_rus;
};
