#pragma once
#include "Libraries.h"

using namespace std;

int CheckCell(int num, string name);
int nums(int& num);
int nums(float& num);

class Product {
protected:
	string type;
	string name;
	int num;
	float price;
	int cellNum;
public:
	Product();

	string GetType() { return type; }
	string GetName() { return name; }
	int GetNum() { return num; }
	float GetPrice() { return price; }
	int GetCellNum() { return cellNum; }

	virtual void SetInfo();
	virtual int GetCount() = 0;
	virtual void PrintUniqueInfo(fstream& fs) = 0;
	virtual void SetUniqueInfo(fstream& fs) = 0;
	virtual string GetUniqueInfo() = 0;

	friend fstream& operator>>(fstream& fs, Product& obj);

	template <class Type> friend void Redact(Type type, string path);
	template <class Type> friend void Delete(Type type, string path);
};

Product::Product() {
	type = "-";
	name = "-";
	num = 0;
	price = 0;
	cellNum = 0;
}

void Product::SetInfo() {
	cout << "������� ��� ������(� ������� ��������������): "; cin >> type;
	cout << "\n������� �������� ������: "; cin >> name;
	while (true) {
		cout << "\n������� ���������� ������(� ��.): "; nums(num);
		if (num <= 0) {
			cout << "������� ������������ ��������!\n��������� ����";
			system("pause");
		}
		else break;
	}
	while (true) {
		cout << "\n������� ���� �� ������� ������: "; nums(price);
		if (price <= 0) {
			cout << "������� ������������ ��������!\n��������� ����";
			system("pause");
		}
		else break;
	}
	while (true) {
		cout << "\n������� ����� ������, � ������� ��������� �����: "; nums(cellNum);
		if (CheckCell(cellNum, name) == 1) {
			cout << "\n������ � ����� ������� ����������!" << endl;
			system("pause");
		}
		else {
			break;
		}
	}
}