#pragma once
#include "Libraries.h"
#include "Product.h"

class Special : public Product {
	string recipe;
public:
	static int count;

	Special();
	~Special();

	string GetRecipe() { return recipe; }

	void SetInfo() override {
		Product::SetInfo();
		cout << "\nНеобходимость рецепта при продаже(да или нет): "; cin >> recipe;
	}

	int GetCount() override { return count; }
	void PrintUniqueInfo(fstream& fs) override { 
		fs << " " << recipe;
	}
	void SetUniqueInfo(fstream& fs) override {
		fs >> recipe;
	}
	string GetUniqueInfo() override { return recipe; }
};

int Special::count = 0;

Special::Special() : Product::Product() {
	count++;
	recipe = "-";
}

Special::~Special() {
	count--;
}