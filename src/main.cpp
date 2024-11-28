#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <string>
#include <windows.h>
#include <sstream>

struct Description
{
	std::string habitat;
	std::string phoneNumber;
};

using dictionary = std::map<std::string, Description>;

static void isCapital(const char x, int& y)
{
	if (x >= '�' && x <= '�') {
		y++; 
	}
}

static void addToGuide(dictionary& guide)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");

	int objects = 0;

	std::string str;
	std::string key;
	Description description;
	bool test = FALSE;
	int number;

	auto s = guide.size();

	std::cout << "�� ������ ������ �1� � ������ ������ � ����������� " << s << " ���������."
		<< "������� �������� ������ �������� � ������� ? (���� � ����� �� ��������)\n";

	std::cin >> objects;
	std::cin.get();

	while (objects) {
		key = "";
		description.habitat = "";
		description.phoneNumber = "";
		number = 0;
		bool test = FALSE;

		std::getline(std::cin, str);
		std::stringstream ss(str);
		std::string word;

		while (ss >> word) {

			isCapital(word[0], number);

			size_t pos = word.find(".");

			if (word.find(".") != std::string::npos || number > 1) {
				test = TRUE;
			}

			if (word[0] == '8') {
				description.phoneNumber += word;
			}

			if (test == TRUE) {
				description.habitat += word + " ";
			}
			else {
				key += word + " ";
			}
		}

		key.pop_back();
		description.habitat.pop_back();
		
		guide.insert({ key, description });
		objects--;
	}
	
	std::cout << "______������ ���������______\n";
}

static void showToGuide(const dictionary& guide)
{
	std::string title;
	std::string place;
	int n = 0;

	std::cin >> title;
	std::cin >> place;

	if (guide.find(title) == guide.end()) {
		std::cout << "������ ���� ��� � �����������\n";
	}
	else {
		if (guide.at(title).habitat == place) {
			std::cout << "������� ����: " << guide.at(title).phoneNumber << std::endl;
		}
		else {
			std::cout << "������ ���� ��� � ��� �����\n";
		}
	}

	std::cout << "______����� �������______\n";
}

static void delToGuide(dictionary& guide)
{
	std::string str;
	int n = 0;

	std::getline(std::cin, str);
	
	guide.erase(str);

	std::cout << "______������ �������______\n";
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	int n = 0;

	dictionary guide;
	std::string str;

	std::cout << "===��������� ���������� �� ���������� ���===\n";
	
	while (true) {

		std::cout << "������ ���� �� ������ ���������\n"
			<< "1: �������� � ����������\n"
			<< "2: ����� � �����������\n"
			<< "3: �����\n"
			<< "4: ������� ������\n";

		std::cin >> n;
		std::cin.get();
		
		switch (n) {
		case 1:
			addToGuide(guide);
			break;
		case 2:
			showToGuide(guide);
			break;
		case 3:
			std::cout << "�������� ���!";
			return 0;
		case 4:
			std::cout << "�� ������ ������ �4� ���� �� ������ �������?";
			delToGuide(guide);
			break;
		default:
			std::cout << "������� �� ���������� �����, ��������� �������!";
		}
	}
;

	return 0;
}