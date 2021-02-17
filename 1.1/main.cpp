#include <iostream>
#include <vector>

using namespace std;

int main() {

	int numOfPair;
	cin >> numOfPair;
	vector<int> res;

	for (int i = 0; i < numOfPair; ++i) {
		int a, b;
		cin >> a;
		cin >> b;
		res.push_back(a + b);
	}

	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;

	return 0;

}