#include <iostream>
#include <set>

using namespace std;

int main() {

	set<int> tree;

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;
		auto it = tree.find(num);
		if (it == tree.end()) {
			cout << "-" << endl;
			tree.insert(num);
		}
		else
			cout << "+" << endl;

	}

	return 0;

}