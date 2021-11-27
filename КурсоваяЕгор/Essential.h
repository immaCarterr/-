#pragma once
#include "Libraries.h"
#include "Product.h"

class Essential : public Product {
public:
	static int count;

	Essential();
	~Essential();

	int GetCount() override { return count; }
	void SetInfo() override {
		Product::SetInfo();
	}
	void PrintUniqueInfo(fstream& fs) override { }
	void SetUniqueInfo(fstream& fs) override { }
	string GetUniqueInfo() override { return "  --"; }
};

int Essential::count = 0;

Essential::Essential() : Product::Product() {
	count++;
}

Essential::~Essential() {
	count--;
}