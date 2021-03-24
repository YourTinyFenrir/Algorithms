#pragma once

struct Node {
	int value;
	Node* parent;
	Node() { }
	Node(int val) {
		this->value = val;
		this->parent = this;
	}
};

class CHM {
	Node** nodes;
	int* ranks;
	int size;

public:
	CHM(int size);
	bool Union(int a, int b); // 0 - были в разных множествах, 1 - в одном
	Node* Find(int a);
	~CHM();
};

