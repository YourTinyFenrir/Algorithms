#include "CHM.h"
#include <iostream>

using namespace std;

CHM::CHM(int size) {

	this->nodes = new Node*[size];
	this->ranks = new int[size];
	this->size = size;

	for (int i = 0; i < size; ++i) {
		Node* nd = new Node(i);
		this->nodes[i] = nd;
		this->ranks[i] = 0;
	}

}

bool CHM::Union(int a, int b) {
	Node* x = Find(a);
	Node* y = Find(b);
	if (x == y)
		return true;
	else {
		if (this->ranks[x->value] == this->ranks[y->value])
			ranks[x->value]++;
		if (this->ranks[x->value] < this->ranks[y->value])
			x->parent = y;
		else
			y->parent = x;

		return false;
	}
}

Node* CHM::Find(int a) {

	if (nodes[a] == nodes[a]->parent)
		return nodes[a];
	else {
		Node* parent = nodes[a]->parent;
		nodes[a]->parent = parent->parent; // —жимаем путь до корн€
		return Find(parent->value);
	}

}

CHM::~CHM() {
	for (int i = 0; i < size; ++i)
		delete[] nodes[i];
	delete[] nodes;
	delete[] ranks;
}
