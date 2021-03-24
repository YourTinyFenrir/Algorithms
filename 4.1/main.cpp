#include "CHM.h"
#include <iostream>

using namespace std;

int main() {

	int size, opers;
	cin >> size;
	cin >> opers;

	CHM chm(size);

	for (int i = 0; i < opers; ++i) {
		int a, b;
		cin >> a;
		cin >> b;

		bool check = chm.Union(a, b);
		if (check)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;

}