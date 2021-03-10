#include <iostream>
#include <set>

using namespace std;

int main() {

	multiset<int> tree;

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;

		auto it = tree.find(num);
		if (it == tree.end()) {
			cout << "- ";
			tree.insert(num);
		}
		else
			cout << "+ ";
		
		it = tree.upper_bound(num);
		if (it == tree.end())
			cout << "-" << endl;
		else
			cout << *it << endl;

	}

	return 0;

}