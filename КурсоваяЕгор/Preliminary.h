#pragma once
#include "Libraries.h"
#include "Product.h"

class Preliminary : public Product {
public:
	static int count;

	Preliminary();
	~Preliminary();

	int GetCount() override { return count; }
	void SetInfo() override {
		Product::SetInfo();
	}
	void PrintUniqueInfo(fstream& fs) override { }
	void SetUniqueInfo(fstream& fs) override { }
	string GetUniqueInfo() override { return "  --"; }
};

int Preliminary::count = 0;

Preliminary::Preliminary() : Product::Product() {
	count++;
}

Preliminary::~Preliminary() {
	count--;
}