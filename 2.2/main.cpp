#include <iostream>

using namespace std;

bool isCovered(int* arr, int size, int length, int k) {

	int num = 0;
	int cur = arr[0];

	for (int j = 0; j < size; ++j)
		if (arr[j] - cur > length) {
			cur = arr[j];
			num++;
		}
	
	num++; // Добавляем отрезок, включающий последнюю точку

	if (num <= k)
		return true;
	else
		return false;

}

int binarySearch(int k, int* pts, int size) {

	int length = pts[size-1] - pts[0];
	int left = 0;
	int right = length;
	bool end = false;

	while (!end) {
		int middle = (right + left) / 2;
		
		bool check = isCovered(pts, size, middle, k);

		if (check) {
			if (middle == left) {
				end = true;
				length = left;
			}
			else {
				right = middle;
				length = middle;
			}
		}
		else {
			if (right - left <= 1)
				end = true;
			else
				left = middle;
		}
	}

	return length;

}

int main() {

	int N; // Число точек на прямой
	cin >> N;

	int k; // Количество отрезков
	cin >> k;

	int* pts = new int[N]; // Массив точек
	for (int i = 0; i < N; ++i)
		cin >> pts[i];

	cout << binarySearch(k, pts, N);

	delete[] pts;

	return 0;

}