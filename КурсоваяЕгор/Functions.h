#pragma once
#include "Libraries.h"
#include "Product.h"
#include "User.h"
#include "Essential.h"
#include "Periodic.h"
#include "Preliminary.h"
#include "Special.h"

using namespace std;

fstream& operator>>(fstream& fs, User& obj) {
	fs >> obj.login >> obj.password;
	return fs;
}

fstream& operator<<(fstream& fs, Product& obj) {
	fs << endl << obj.GetType() << " " << obj.GetName() << " " << obj.GetNum();
	fs << " " << obj.GetPrice() << " " << obj.GetCellNum();
	return fs;
}

fstream& operator>>(fstream& fs, Product& obj) {
	fs >> obj.type >> obj.name >> obj.num >> obj.price >> obj.cellNum;
	return fs;
}

int HidePass(string& info) {
	int flag = 0;
	info = "";
	int ch = 0; // Переменная для символа.
	while (true) // Создание бесконечного цикла.
	{
		ch = _getch(); // Помещаем код нажатой клавиши в переменную.
		if (ch == 13) // Установка Enter на прерывание цикла.
		{
			break; // Прерывание цикла.
		}
		if (ch == 27) // Установка Esc на закрытие консоли.
		{
			flag = 1;
			break; // Выход из консоли.
		}
		if (ch == 8 && !info.empty()) // Установка Backspace на удаление символов.
		{
			cout << (char)8 << ' ' << char(8);
			if (!info.empty()) info.erase(info.length() - 1);
		}

		if (ch != 8) {
			cout << "*";
			info += (char)ch;
		}
	}
	cout << endl;
	return flag;
}

int nums(int& num) {
	string info;
	int flag = 0;
	info = "";
	int ch = 0; // Переменная для символа.
	while (true) // Создание бесконечного цикла.
	{
		while (true) {
			ch = _getch(); // Помещаем код нажатой клавиши в переменную.
			if ((ch >= 48 && ch <= 57) || ch == 8 || ch == 13) break;
		}
		if (ch == 13) // Установка Enter на прерывание цикла.
		{
			break; // Прерывание цикла.
		}
		if (ch == 27) // Установка Esc на закрытие консоли.
		{
			flag = 1;
			break; // Выход из консоли.
		}
		if (ch == 8 && !info.empty()) // Установка Backspace на удаление символов.
		{
			cout << (char)8 << ' ' << char(8);
			if (!info.empty()) info.erase(info.length() - 1);
		}

		if (ch != 8) {
			cout << (char)ch;
			info += (char)ch;
		}
	}
	stringstream A; A << info; A >> num;
	cout << endl;
	return flag;
}

int nums(float& num) {
	string info;
	int flag = 0;
	info = "";
	int ch = 0; // Переменная для символа.
	while (true) // Создание бесконечного цикла.
	{
		while (true) {
			ch = _getch(); // Помещаем код нажатой клавиши в переменную.
			if ((ch >= 48 && ch <= 57) || ch == 8 || ch == 13 || ch == 46) break;
		}
		if (ch == 13) // Установка Enter на прерывание цикла.
		{
			break; // Прерывание цикла.
		}
		if (ch == 27) // Установка Esc на закрытие консоли.
		{
			flag = 1;
			break; // Выход из консоли.
		}
		if (ch == 8 && !info.empty()) // Установка Backspace на удаление символов.
		{
			cout << (char)8 << ' ' << char(8);
			if (!info.empty()) info.erase(info.length() - 1);
		}

		if (ch != 8) {
			cout << (char)ch;
			info += (char)ch;
		}
	}
	stringstream A; A << info; A >> num;
	cout << endl;
	return flag;
}

void Encryption(string& str) {
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = str[i] + 7;
	}
}

void Decryption(string& str) {
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = str[i] - 7;
	}
}

int Menu() {
	int choice;
	cout << "\n\n\n\n\n";
	cout << "\t\t\t\t  ||=========================================||\n"
		"\t\t\t\t  ||                                         ||\n"
		"\t\t\t\t  ||  1. Регистрация нового пользователя     ||\n"
		"\t\t\t\t  ||                                         ||\n"
		"\t\t\t\t  ||=========================================||\n"
		"\t\t\t\t  ||                                         ||\n"
		"\t\t\t\t  ||  2. Вход                                ||\n"
		"\t\t\t\t  ||                                         ||\n"
		"\t\t\t\t  ||=========================================||\n"
		"\t\t\t\t  ||                                         ||\n"
		"\t\t\t\t  ||  3. Выход                               ||\n"
		"\t\t\t\t  ||                                         ||\n"
		"\t\t\t\t  ||=========================================||\n\n";
	cout << "\t\t\t\t                 Ваш выбор: "; nums(choice);
	return choice;
}

int UserMenu() {
	int choice;
	cout << "\t\t\t\t\t||=============================================||\n"
		"\t\t\t\t\t||                                             ||\n"
		"\t\t\t\t\t||  1. Добавление информации                   ||\n"
		"\t\t\t\t\t||                                             ||\n"
		"\t\t\t\t\t||=============================================||\n"
		"\t\t\t\t\t||                                             ||\n"
		"\t\t\t\t\t||  2. Редактирование информации               ||\n"
		"\t\t\t\t\t||                                             ||\n"
		"\t\t\t\t\t||=============================================||\n"
		"\t\t\t\t\t||                                             ||\n"
		"\t\t\t\t\t||  3. Удаление информации                     ||\n"
		"\t\t\t\t\t||                                             ||\n"
		"\t\t\t\t\t||=============================================||\n"
		"\t\t\t\t\t||                                             ||\n"
		"\t\t\t\t\t||  4. Просмотр информации                     ||\n"
		"\t\t\t\t\t||                                             ||\n"
		"\t\t\t\t\t||=============================================||\n"
		"\t\t\t\t\t||                                             ||\n"
		"\t\t\t\t\t||  5. Поиск информации                        ||\n"
		"\t\t\t\t\t||                                             ||\n"
		"\t\t\t\t\t||=============================================||\n"
		"\t\t\t\t\t||                                             ||\n"
		"\t\t\t\t\t||  6. Отчёт о всех лекарствах в алф. порядке  ||\n"
		"\t\t\t\t\t||                                             ||\n"
		"\t\t\t\t\t||=============================================||\n"
		"\t\t\t\t\t||                                             ||\n"
		"\t\t\t\t\t||  7. Назад                                   ||\n"
		"\t\t\t\t\t||                                             ||\n"
		"\t\t\t\t\t||=============================================||\n"
		"\t\t\t\t\t               Ваш выбор: "; nums(choice);
	return choice;

}

int AddMenu() {
	int choice;
	cout << "\n\n\n";
	cout << "\t\t\t||============================================================||\n"
		"\t\t\t||                                                            ||\n"
		"\t\t\t||  1. Добавление информации о товаре первой необходимости    ||\n"
		"\t\t\t||                                                            ||\n"
		"\t\t\t||============================================================||\n"
		"\t\t\t||                                                            ||\n"
		"\t\t\t||  2. Добавление информации о товаре периодического спроса   ||\n"
		"\t\t\t||                                                            ||\n"
		"\t\t\t||============================================================||\n"
		"\t\t\t||                                                            ||\n"
		"\t\t\t||  3. Добавление информации о товаре предварительного спроса ||\n"
		"\t\t\t||                                                            ||\n"
		"\t\t\t||============================================================||\n"
		"\t\t\t||                                                            ||\n"
		"\t\t\t||  4. Добавление информации о специализированном товаре      ||\n"
		"\t\t\t||                                                            ||\n"
		"\t\t\t||============================================================||\n"
		"\t\t\t||                                                            ||\n"
		"\t\t\t||  5. Назад                                                  ||\n"
		"\t\t\t||                                                            ||\n"
		"\t\t\t||============================================================||\n\n"
		"\t\t\t                 Ваш выбор: "; nums(choice);
	return choice;
}

int RedMenu() {
	int choice;
	cout << "\n\n\n";
	cout << "\t\t\t||================================================================||\n"
		"\t\t\t||                                                                ||\n"
		"\t\t\t||  1. Редактирование информации о товаре первой необходимости    ||\n"
		"\t\t\t||                                                                ||\n"
		"\t\t\t||================================================================||\n"
		"\t\t\t||                                                                ||\n"
		"\t\t\t||  2. Редактирование информации о товаре периодического спроса   ||\n"
		"\t\t\t||                                                                ||\n"
		"\t\t\t||================================================================||\n"
		"\t\t\t||                                                                ||\n"
		"\t\t\t||  3. Редактирование информации о товаре предварительного спроса ||\n"
		"\t\t\t||                                                                ||\n"
		"\t\t\t||================================================================||\n"
		"\t\t\t||                                                                ||\n"
		"\t\t\t||  4. Редактирование информации о специализированном товаре      ||\n"
		"\t\t\t||                                                                ||\n"
		"\t\t\t||================================================================||\n"
		"\t\t\t||                                                                ||\n"
		"\t\t\t||  5. Назад                                                      ||\n"
		"\t\t\t||                                                                ||\n"
		"\t\t\t||================================================================||\n\n"
		"\t\t\t                 Ваш выбор: "; nums(choice);
	return choice;
}

int DelMenu() {
	int choice;
	cout << "\n\n\n";
	cout << "\t\t\t||============================================================||\n"
		"\t\t\t||                                                            ||\n"
		"\t\t\t||  1. Удаление информации о товаре первой необходимости      ||\n"
		"\t\t\t||                                                            ||\n"
		"\t\t\t||============================================================||\n"
		"\t\t\t||                                                            ||\n"
		"\t\t\t||  2. Удаление информации о товаре периодического спроса     ||\n"
		"\t\t\t||                                                            ||\n"
		"\t\t\t||============================================================||\n"
		"\t\t\t||                                                            ||\n"
		"\t\t\t||  3. Удаление информации о товаре предварительного спроса   ||\n"
		"\t\t\t||                                                            ||\n"
		"\t\t\t||============================================================||\n"
		"\t\t\t||                                                            ||\n"
		"\t\t\t||  4. Удаление информации о специализированном товаре        ||\n"
		"\t\t\t||                                                            ||\n"
		"\t\t\t||============================================================||\n"
		"\t\t\t||                                                            ||\n"
		"\t\t\t||  5. Назад                                                  ||\n"
		"\t\t\t||                                                            ||\n"
		"\t\t\t||============================================================||\n\n"
		"\t\t\t                 Ваш выбор: "; nums(choice);
	return choice;
}

int ShowMenu() {
	int choice;
	cout << "\n\n\n";
	cout << "\t\t\t||=============================================================||\n"
		"\t\t\t||                                                             ||\n"
		"\t\t\t||  1. Просмотр информации о товаре первой необходимости       ||\n"
		"\t\t\t||                                                             ||\n"
		"\t\t\t||=============================================================||\n"
		"\t\t\t||                                                             ||\n"
		"\t\t\t||  2. Просмотр информации о товаре периодического спроса      ||\n"
		"\t\t\t||                                                             ||\n"
		"\t\t\t||=============================================================||\n"
		"\t\t\t||                                                             ||\n"
		"\t\t\t||  3. Просмотр информации о товаре предварительного спроса    ||\n"
		"\t\t\t||                                                             ||\n"
		"\t\t\t||=============================================================||\n"
		"\t\t\t||                                                             ||\n"
		"\t\t\t||  4. Просмотр информации о специализированном товаре         ||\n"
		"\t\t\t||                                                             ||\n"
		"\t\t\t||============================================================ ||\n"
		"\t\t\t||                                                             ||\n"
		"\t\t\t||  5. Просмотр отсортированной по возрастанию цены информации ||\n"
		"\t\t\t||                                                             ||\n"
		"\t\t\t||=============================================================||\n"
		"\t\t\t||                                                             ||\n"
		"\t\t\t||  6. Просмотр отсортированной по номеру ячеек информации     ||\n"
		"\t\t\t||                                                             ||\n"
		"\t\t\t||=============================================================||\n"
		"\t\t\t||                                                             ||\n"
		"\t\t\t||  7. Назад                                                   ||\n"
		"\t\t\t||                                                             ||\n"
		"\t\t\t||=============================================================||\n"
		"\t\t\t                       Ваш выбор: "; nums(choice);
	return choice;
}

int FindMenu() {
	int choice;
	cout << "\n\n";
	cout << "\t\t\t   ||============================================================||\n"
		"\t\t\t   ||                                                            ||\n"
		"\t\t\t   ||  1. Поиск информации о товаре первой необходимости         ||\n"
		"\t\t\t   ||                                                            ||\n"
		"\t\t\t   ||============================================================||\n"
		"\t\t\t   ||                                                            ||\n"
		"\t\t\t   ||  2. Поиск информации о товаре периодического спроса        ||\n"
		"\t\t\t   ||                                                            ||\n"
		"\t\t\t   ||============================================================||\n"
		"\t\t\t   ||                                                            ||\n"
		"\t\t\t   ||  3. Поиск информации о товаре предварительного спроса      ||\n"
		"\t\t\t   ||                                                            ||\n"
		"\t\t\t   ||============================================================||\n"
		"\t\t\t   ||                                                            ||\n"
		"\t\t\t   ||  4. Поиск информации о специализированном товаре           ||\n"
		"\t\t\t   ||                                                            ||\n"
		"\t\t\t   ||============================================================||\n"
		"\t\t\t   ||                                                            ||\n"
		"\t\t\t   ||  5. Фильтрация информации по номеру ячеек                  ||\n"
		"\t\t\t   ||                                                            ||\n"
		"\t\t\t   ||============================================================||\n"
		"\t\t\t   ||                                                            ||\n"
		"\t\t\t   ||  6. Назад                                                  ||\n"
		"\t\t\t   ||                                                            ||\n"
		"\t\t\t   ||============================================================||\n"
		"\t\t\t                         Ваш выбор: "; nums(choice);
	return choice;
}

int CheckExistLog(string log, string pass) {
	int flag = 1;
	fstream fs;
	fs.open("Users.txt");
	if (fs.is_open()) {
		deque <User> U;
		while (!fs.eof())
		{
			User user;
			fs >> user;
			U.push_back(user);
		}
		fs.close();
		for (int i = 0; i < U.size(); i++)
		{
			Decryption(U[i].password);
			(U[i].login == log) ? flag = 0 : flag;
			(U[i].login == log && U[i].password == pass) ? flag = 2 : flag;
		}
	}
	else {
		flag = -1;
	}
	return flag;
}

void UserInFile(string path, User user) {
	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app);
	if (fs.is_open()) {
		fs << user.login << " " << user.password << endl;
		fs.close();
	}
	else {
		cout << "Ошибка открытия файла" << endl;
	}
}

void reg() {
	User user;
	bool flag = true;
	while (flag) {
		system("cls");
		cout << "Введите логин: "; cin >> user.login;
		int ch = CheckExistLog(user.login, "");
		if (ch == 1 || ch == -1) {
			cout << "\nВведите пароль: "; HidePass(user.password);
			cout << "\nПовторите пароль: "; HidePass(user.confpass);
			if (user.password == user.confpass) {
				Encryption(user.password);
				cout << "\nРегистрация прошла успешно" << endl;
				system("pause");
				UserInFile("Users.txt", user);
				flag = false;
			}
			else {
				cout << "Пароль или логин не совпадают!" << endl;
				system("pause");
			}
		}
		else {
			cout << "Пользователь с таким логином уже зарегистрирован!" << endl;
			system("pause");
		}
	}
}

int authorization() {
	int res;
	User user;
	bool flag = true;
	while (flag) {
		system("cls");
		int ch = CheckExistLog("", "");
		if (ch == -1) {
			cout << "Необходима регистрация!" << endl;
			res = -1;
			system("pause");
			break;
		}
		cout << "Введите логин: "; cin >> user.login;
		cout << "\nВведите пароль: "; HidePass(user.password);
		ch = CheckExistLog(user.login, user.password);
		if (ch == 2) {
			res = 1;
			cout << "Вход выполнен успешно!" << endl;
			system("pause");
			flag = false;
		}
		else {
			cout << "\nНеверный логин или пароль!\n";
			system("pause");
			continue;
		}
	}
	return res;
}

int CheckFile(string path) {
	int res = 0;
	fstream fs;
	fs.open(path);
	if (fs.is_open()) res = 1;
	return res;
}

int CheckCell(int num, string name) {
	int flag = 0;
	if (CheckFile("Essentials.txt") == 0) return flag;
	fstream fs;
	fs.open("Essentials.txt", fstream::in | fstream::out);
	if (fs.is_open()) {
		deque <Essential> D;
		while (!fs.eof()) {
			Essential object;
			fs >> object;
			object.SetUniqueInfo(fs);
			D.push_back(object);
		}
		fs.close();
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].GetCellNum() == num && D[i].GetName()!= name) flag = 1;
		}
	}

	if (CheckFile("Periodics.txt") == 0) return flag;
	fs.open("Periodics.txt", fstream::in | fstream::out);
	if (fs.is_open()) {
		deque <Periodic> D;
		while (!fs.eof()) {
			Periodic object;
			fs >> object;
			object.SetUniqueInfo(fs);
			D.push_back(object);
		}
		fs.close();
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].GetCellNum() == num && D[i].GetName() != name) flag = 1;
		}
	}

	if (CheckFile("Preliminaries.txt") == 0) return flag;
	fs.open("Periodics.txt", fstream::in | fstream::out);
	if (fs.is_open()) {
		deque <Preliminary> D;
		while (!fs.eof()) {
			Preliminary object;
			fs >> object;
			object.SetUniqueInfo(fs);
			D.push_back(object);
		}
		fs.close();
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].GetCellNum() == num && D[i].GetName() != name) flag = 1;
		}
	}

	if (CheckFile("Special.txt") == 0) return flag;
	fs.open("Special.txt", fstream::in | fstream::out);
	if (fs.is_open()) {
		deque <Special> D;
		while (!fs.eof()) {
			Special object;
			fs >> object;
			object.SetUniqueInfo(fs);
			D.push_back(object);
		}
		fs.close();
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].GetCellNum() == num && D[i].GetName() != name) flag = 1;
		}
	}
	return flag;
}

void Add(Product* obj, string path) {
	obj->SetInfo();
	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app);
	if (fs.is_open()) {
		fs << *obj;
		obj->PrintUniqueInfo(fs);
		fs.close();
	}
	else {
		cout << "Не удалось записать информацию" << endl;
	}
}

template <class Type>
void Redact(Type type, string path) {
	cout << endl;
	if (CheckFile(path) == 0) {
		cout << "Информация о товарах отсутствует!" << endl;
		system("pause");
		return;
	}
	string title;
	cout << "Введите название товара, информацию о котором необходимо изменить: ";
	cin >> title;
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		int flag = 0;
		deque <Type> D;
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUniqueInfo(fs);
			D.push_back(object);
		}
		fs.close();
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].name == title) {
				flag = 1;
				cout << "Введите новую информацию:" << endl << endl;
				D[i].SetInfo();
			}
		}
		if (flag == 0) {
			cout << endl << "Товар с такими данными не найден, проверьте введённые данные" << endl;
			system("pause");
			return;
		}
		char Fname[20];
		for (int i = 0; i < path.size(); i++)
		{
			Fname[i] = path[i];
		}
		Fname[path.size()] = '\0';
		remove(Fname);
		fs.open(path, fstream::out | fstream::in | fstream::app);
		if (fs.is_open()) {
			for (int i = 0; i < D.size(); i++)
			{
				fs << D[i];
			}
			fs.close();
		}
	}
	else {
		cout << "Не удалось отредактировать информацию" << endl;
	}
}

template <class Type>
void Delete(Type type, string path) {
	if (CheckFile(path) == 0) {
		cout << "Информация о товарах отсутствует!" << endl;
		system("pause");
		return;
	}
	string title;
	cout << "Введите название товара, информацию о котором необходимо удалить: " << endl;
	cin >> title;
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		int flag = 0;
		deque <Type> D;
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUniqueInfo(fs);
			D.push_back(object);
		}
		fs.close();
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].name == title) flag = 1;
		}
		if (flag == 0) {
			cout << endl << "Товар с такими данными не найден, проверьте введённые данные" << endl;
			system("pause");
			return;
		}
		char Fname[20];
		for (int i = 0; i < path.size(); i++)
		{
			Fname[i] = path[i];
		}
		Fname[path.size()] = '\0';
		remove(Fname);
		fs.open(path, fstream::out | fstream::in | fstream::app);
		if (fs.is_open()) {
			for (int i = 0; i < D.size(); i++)
			{
				if (!(D[i].name == title)) fs << D[i];
			}
			fs.close();
		}
	}
	else {
		cout << "Не удалось удалить информацию" << endl;
	}
}

void PrintHead() {
	cout << "|" << setw(88) << setfill('=') << "|" << endl;
	cout << "|     |" << setw(20) << setfill(' ') << "|" << setw(18) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(7) << setfill(' ') << "|" << setw(15) << setfill(' ') << "|" << setw(9) << setfill(' ') << "|" << endl;

	cout << resetiosflags(ios::adjustfield);
	cout.setf(ios::left);
	cout << "|  №  |" << setw(19) << setfill(' ') << " Тип товара" << "|" << setw(17) << setfill(' ') << " Название" << "|" << setw(12) << setfill(' ') << " Количество" << "|" << setw(6) << setfill(' ') << " Цена" << "|" << setw(14) << setfill(' ') << " Номер ячейки" << "|" << setw(8) << setfill(' ') << " Рецепт" << "|" << endl;

	cout.setf(ios::right);
	cout << "|     |" << setw(20) << setfill(' ') << "|" << setw(18) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(7) << setfill(' ') << "|" << setw(15) << setfill(' ') << "|" << setw(9) << setfill(' ') << "|" << endl;
	cout << "|" << setw(88) << setfill('=') << "|" << endl;
}

void PrintObject(Product* object, int n) {
	cout << "|     |" << setw(20) << setfill(' ') << "|" << setw(18) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(7) << setfill(' ') << "|" << setw(15) << setfill(' ') << "|" << setw(9) << setfill(' ') << "|" << endl;

	cout << resetiosflags(ios::adjustfield);
	cout.setf(ios::left);
	cout << "| " <<setw(4) << setfill(' ') << n+1 << "| " << setw(18) << setfill(' ') << object->GetType() << "| " << setw(16) << setfill(' ') << object->GetName() << "| " << setw(11) << setfill(' ') << object->GetNum() << "| " << setw(5) << setfill(' ') << object->GetPrice() << "| " << setw(13) << setfill(' ') << object->GetCellNum() << "| " << setw(7) << setfill(' ') << object->GetUniqueInfo() << "|" << endl;

	cout << resetiosflags(ios::adjustfield);
	cout.setf(ios::right);
	cout << "|     |" << setw(20) << setfill(' ') << "|" << setw(18) << setfill(' ') << "|" << setw(13) << setfill(' ') << "|" << setw(7) << setfill(' ') << "|" << setw(15) << setfill(' ') << "|" << setw(9) << setfill(' ') << "|" << endl;
	cout << "|" << setw(88) << setfill('=') << "|" << endl;
}

template <class Type>
void Show(Type type, string path, int flag) {
	if (CheckFile(path) == 0) {
		cout << "Информация отсутствует!" << endl;
		if (flag == 0) system("pause");
		return;
	}
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		deque <Type> D;
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUniqueInfo(fs);
			D.push_back(object);
		}
		fs.close();

		if (flag != 0) {
			for (int i = 1; i < D.size(); i++)
			{
				int d = exp2(i) - 1;
				if (d <= D.size()) {

					for (int k = 0; k < D.size() - d; k++)
					{
						int j = k;
						if (flag == 1) {
							while (j >= 0 && D[j].GetPrice() > D[j + d].GetPrice())
							{
								Type object = D[j];
								D[j] = D[j + d];
								D[j + d] = object;
								j--;
							}
						}
						if (flag == 2) {
							while (j >= 0 && D[j].GetCellNum() > D[j + d].GetCellNum())
							{
								Type object = D[j];
								D[j] = D[j + d];
								D[j + d] = object;
								j--;
							}
						}
						if (flag == 3) {
							while (j >= 0 && D[j].GetName()[0] > D[j + d].GetName()[0])
							{
								Type object = D[j];
								D[j] = D[j + d];
								D[j + d] = object;
								j--;
							}
						}
					}
				}
			}
		}
		
		PrintHead();

		for (int i = 0; i < D.size(); i++)
		{
			PrintObject(&D[i], i);
		}
		if (flag == 0) system("pause");
	}
	else {
		cout << "Не удалось удалить информацию" << endl;
	}
}

template <class Type>
void Find(Type type, string path) {
	if (CheckFile(path) == 0) {
		cout << "Информация о товаре отсутствует!" << endl;
		system("pause");
		return;
	}
	string title;
	cout << "Введите название товара, информацию о котором необходимо найти: " << endl;
	cin >> title;
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		int flag = 0;
		deque <Type> D;
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUniqueInfo(fs);
			D.push_back(object);
		}
		fs.close();
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].GetName() == title) flag = 1;
		}
		if (flag == 0) {
			cout << endl << "Товар с такими данными не найден, проверьте введённые данные" << endl;
			system("pause");
			return;
		}
		cout << endl;
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].GetName() == title) {
				PrintHead();

				PrintObject(&D[i], i);
			}
		}
		system("pause");
	}
	else {
		cout << "Не удалось удалить информацию" << endl;
	}
}

template <class Type>
void FilterCellNums(Type type, string path) {
	int flag = 0;
	if (CheckFile(path) == 0) {
		cout << "Информация отсутствует!" << endl;
		system("pause");
		return;
	}
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		deque <Type> D;
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUniqueInfo(fs);
			D.push_back(object);
		}
		fs.close();
		int minNum, maxNum;
		while (true) {
			while (true) {
				cout << "Введите нижний диапазон номеров ячеек: "; nums(minNum);
				if (minNum < 0) {
					cout << "Введено неверное значение!\nПовторите ввод";
					system("pause");
				}
				else break;
			}
			while (true) {
				cout << "Введите верхний диапазон номеров ячеек: "; nums(maxNum);
				if (maxNum < 0) {
					cout << "Введено неверное значение!\nПовторите ввод";
					system("pause");
				}
				else break;
			}
			if (maxNum <= minNum) {
				cout << "Максимальный диапазон ячеек не может быть меньше либо равен минимальному" << endl;
				system("pause");
			}
			else break;
		}
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].GetCellNum() >= minNum && D[i].GetCellNum() <= maxNum) flag = 1;
		}
		if (flag == 1) {

			PrintHead();

			for (int i = 0; i < D.size(); i++)
			{
				if (D[i].GetCellNum() >= minNum && D[i].GetCellNum() <= maxNum) {
					PrintObject(&D[i], i);
				}
			}
		}
		else {
			cout << "\nНи одного товара с номером ячейки в таком диапазоне не найдено\n";
		}
	}
}