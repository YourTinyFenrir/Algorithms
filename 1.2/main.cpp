#include <iostream>
#include <vector>

using namespace std;

vector<int> sum(vector<int> a, vector<int> b) {

	vector<int> res;
	int mod = 0;

	if (b.size() > a.size()) {
		vector<int> temp;
		for (int i = 0; i < a.size(); ++i)
			temp.push_back(a[i]);
		a.clear();
		for (int i = 0; i < b.size(); ++i)
			a.push_back(b[i]);
		b.clear();
		for (int i = 0; i < temp.size(); ++i)
			b.push_back(temp[i]);
	}

	vector<int> aR;
	for (int i = a.size() - 1; i >= 0; --i)
		aR.push_back(a[i]);

	vector<int> bR;
	for (int i = b.size() - 1; i >= 0; --i)
		bR.push_back(b[i]);

	for (int i = 0; i < aR.size(); ++i) {
		int num;
		if (i < bR.size())
			num = aR[i] + bR[i] + mod;
		else
			num = aR[i] + mod;

		if (num < 10) {
			res.push_back(num);
			mod = 0;
		}
		else {
			res.push_back(num % 10);
			mod = num / 10;
		}
	}

	if (mod > 0)
		res.push_back(mod);

	return res;

}

int main() {

	int numOfPair;
	cin >> numOfPair;
	vector<vector<int>> res;

	for (int i = 0; i < numOfPair; ++i) {
		vector<int> a, b;
		string str;
		cin >> str;

		for (int i = 0; i < str.size(); ++i)
			a.push_back((int)str[i] - 48);

		cin >> str;
		for (int i = 0; i < str.size(); ++i)
			b.push_back((int)str[i] - 48);

		res.push_back(sum(a, b));

	}

	for (int i = 0; i < res.size(); ++i) {
		for (int j = res[i].size() - 1; j >= 0 ; --j)
			cout << res[i][j];
		cout << endl;
	}

	return 0;

}