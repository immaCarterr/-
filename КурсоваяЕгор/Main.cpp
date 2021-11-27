#include "Libraries.h"
#include "Functions.h"
#include "Product.h"
#include "Essential.h"
#include "Periodic.h"
#include "Preliminary.h"
#include "Special.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool flag = true;
	while (flag) {
		system("cls");
		int choice1 = Menu();
		switch (choice1) {
		case 1:
			system("cls");
			reg();
			continue;
			break;
		case 2:
			system("cls");
			if (authorization() == -1) continue;
			while (true) {
				system("cls");
				int choice2 = UserMenu();
				if (choice2 == 7) break;
				switch (choice2) {
				case 1:
					while (true) {
						system("cls");
						int choice3 = AddMenu();
						if (choice3 == 5) break;
						switch (choice3) {
						case 1: {
							system("cls");
							Essential essential;
							Add(&essential, "Essentials.txt");
							break;
						}
						case 2: {
							system("cls");
							Periodic periodic;
							Add(&periodic, "Periodics.txt");
							break;
						}
						case 3: {
							system("cls");
							Preliminary preliminary;
							Add(&preliminary, "Preliminaries.txt");
							break;
						}
						case 4: {
							system("cls");
							Special special;
							Add(&special, "Special.txt");
							break;
						}
						default: {
							system("cls");
							cout << "Неверный выбор!\nПовторите попытку." << endl;
							system("pause");
						}
						}
					}
					continue;
					break;
				case 2:
					while (true) {
						system("cls");
						int choice4 = RedMenu();
						if (choice4 == 5) break;
						switch (choice4) {
						case 1: {
							system("cls");
							Essential essential;
							Show(essential, "Essentials.txt", 0);
							Redact(essential, "Essentials.txt");
							break;
						}
						case 2: {
							system("cls");
							Periodic periodic;
							Show(periodic, "Periodics.txt", 0);
							Redact(periodic, "Periodics.txt");
							break;
						}
						case 3: {
							system("cls");
							Preliminary preliminary;
							Show(preliminary, "Preliminaries.txt", 0);
							Redact(preliminary, "Preliminaries.txt");
							break;
						}
						case 4: {
							system("cls");
							Special special;
							Show(special, "Special.txt", 03);
							Redact(special, "Special.txt");
							break;
						}
						default: {
							system("cls");
							cout << "Неверный выбор!\nПовторите попытку." << endl;
							system("pause");
						}
						}
					}
					continue;
					break;
				case 3:
					while (true) {
						system("cls");
						int choice5 = DelMenu();
						if (choice5 == 5) break;
						switch (choice5) {
						case 1: {
							system("cls");
							Essential essential;
							Delete(essential, "Essentials.txt");
							break;
						}
						case 2: {
							system("cls");
							Periodic periodic;
							Delete(periodic, "Periodics.txt");
							break;
						}
						case 3: {
							system("cls");
							Preliminary preliminary;
							Delete(preliminary, "Preliminaries.txt");
							break;
						}
						case 4: {
							system("cls");
							Special special;
							Delete(special, "Special.txt");
							break;
						}
						default: {
							system("cls");
							cout << "Неверный выбор!\nПовторите попытку." << endl;
							system("pause");
						}
						}
					}
					continue;
					break;
				case 4:
					while (true) {
						system("cls");
						int choice6 = ShowMenu();
						if (choice6 == 7) break;
						switch (choice6) {
						case 1: {
							system("cls");
							Essential essential;
							Show(essential, "Essentials.txt", 0);
							break;
						}
						case 2: {
							system("cls");
							Periodic periodic;
							Show(periodic, "Periodics.txt", 0);
							break;
						}
						case 3: {
							system("cls");
							Preliminary preliminary;
							Show(preliminary, "Preliminaries.txt", 0);
							break;
						}
						case 4: {
							system("cls");
							Special special;
							Show(special, "Special.txt", 0);
							break;
						}
						case 5: {
							system("cls");
							Essential essential;
							cout << "Товары первой необходисоти:" << endl;
							Show(essential, "Essentials.txt", 1);

							Periodic periodic;
							cout << "\n\nТовары периодического спроса:" << endl;
							Show(periodic, "Periodics.txt", 1);

							Preliminary preliminary;
							cout << "\n\nТовары предварительного спроса:" << endl;
							Show(preliminary, "Preliminaries.txt", 1);

							Special special;
							cout << "\n\nСпециальные товары:" << endl;
							Show(special, "Special.txt", 1);
							system("pause");
							break;
						}
						case 6: {
							system("cls");
							Essential essential;
							cout << "Товары первой необходисоти:" << endl;
							Show(essential, "Essentials.txt", 2);

							Periodic periodic;
							cout << "\n\nТовары периодического спроса:" << endl;
							Show(periodic, "Periodics.txt", 2);

							Preliminary preliminary;
							cout << "\n\nТовары предварительного спроса:" << endl;
							Show(preliminary, "Preliminaries.txt", 2);

							Special special;
							cout << "\n\nСпециальные товары:" << endl;
							Show(special, "Special.txt", 2);
							system("pause");
							break;
						}
						default: {
							system("cls");
							cout << "Неверный выбор!\nПовторите попытку." << endl;
							system("pause");
						}
						}
					}
					continue;
					break;
				case 5:
					while (true) {
						system("cls");
						int choice7 = FindMenu();
						if (choice7 == 6) break;
						switch (choice7) {
						case 1: {
							system("cls");
							Essential essential;
							Find(essential, "Essentials.txt");
							break;
						}
						case 2: {
							system("cls");
							Periodic periodic;
							Find(periodic, "Periodics.txt");
							break;
						}
						case 3: {
							system("cls");
							Preliminary preliminary;
							Find(preliminary, "Preliminaries.txt");
							break;
						}
						case 4: {
							system("cls");
							Special special;
							Find(special, "Special.txt");
							break;
						}
						case 5: {
							system("cls");
							Essential essential;
							cout << "Товары первой необходисоти:" << endl;
							FilterCellNums(essential, "Essentials.txt");

							Periodic periodic;
							cout << "\n\nТовары периодического спроса:" << endl;
							FilterCellNums(periodic, "Periodics.txt");

							Preliminary preliminary;
							cout << "\n\nТовары предварительного спроса:" << endl;
							FilterCellNums(preliminary, "Preliminaries.txt");

							Special special;
							cout << "\n\nСпециальные товары:" << endl;
							FilterCellNums(special, "Special.txt");
							system("pause");
							break;
						}
						default: {
							system("cls");
							cout << "Неверный выбор!\nПовторите попытку." << endl;
							system("pause");
						}
						}
					}
					continue;
					break;
				case 6: {
					system("cls");
					Essential essential;
					cout << "Товары первой необходисоти:" << endl;
					Show(essential, "Essentials.txt", 3);

					Periodic periodic;
					cout << "\n\nТовары периодического спроса:" << endl;
					Show(periodic, "Periodics.txt", 3);

					Preliminary preliminary;
					cout << "\n\nТовары предварительного спроса:" << endl;
					Show(preliminary, "Preliminaries.txt", 3);

					Special special;
					cout << "\n\nСпециальные товары:" << endl;
					Show(special, "Special.txt", 3);
					system("pause");
					break;
				}
				default: {
					system("cls");
					cout << "Неверный выбор!\nПовторите попытку." << endl;
					system("pause");
				}
				}
			}
			continue;
			break;
		case 3:
			exit(0);
			break;
		default: {
			system("cls");
			cout << "Неверный выбор!\nПовторите попытку." << endl;
			system("pause");
		}
		}
	}
	return 0;
}