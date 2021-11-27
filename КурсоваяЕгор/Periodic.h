#pragma once
#include "Libraries.h"
#include "Product.h"

class Periodic : public Product {
public:
	static int count;

	Periodic();
	~Periodic();

	int GetCount() override { return count; }
	void SetInfo() override {
		Product::SetInfo();
	}
	void PrintUniqueInfo(fstream& fs) override { }
	void SetUniqueInfo(fstream& fs) override { }
	string GetUniqueInfo() override { return "  --"; }
};

int Periodic::count = 0;

Periodic::Periodic() : Product::Product() {
	count++;
}

Periodic::~Periodic() {
	count--;
}