#include <iostream>

using namespace std;

int binarySearch(int* arr, int size, int check) {

	int index = -1;
	int left = 0;
	int right = size - 1;
	bool find = false;
	bool end = false;

	while (!end && !find) {
		int middle = (right + left) / 2;
		if (right - left <= 1)
			end = true;

		if (arr[middle] < check)
			left = middle;
		else if (arr[middle] > check)
			right = middle;
		else {
			find = true;
			index = middle;
		}
	}

	if (arr[left] == check)
		index = left;
	if (arr[right] == check)
		index = right;

	return index;

}

int main() {

	// Исходный массив
	int sizeSrc;
	cin >> sizeSrc;
	int* source = new int[sizeSrc];

	for (int i = 0; i < sizeSrc; ++i) {
		int a;
		cin >> a;
		source[i] = a;
	}

	// Проверяемые значения
	int size;
	cin >> size;
	int* checked = new int[size];

	for (int i = 0; i < size; ++i) {
		int a;
		cin >> a;
		checked[i] = a;
	}

	// Индексы проверяемых значений в исходном массиве (-1 при отсутствии)
	int* index = new int[size];

	for (int i = 0; i < size; ++i) 
		index[i] = binarySearch(source, sizeSrc, checked[i]);

	for (int i = 0; i < size; ++i)
		cout << index[i] << endl;

	delete[] source;
	delete[] checked;
	delete[] index;

	return 0;

}