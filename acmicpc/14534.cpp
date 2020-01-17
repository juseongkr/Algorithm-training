#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	vector<int> vec;
	string s;
	int t;

	cin >> t;
	for (int T=1; T<=t; ++T) {
		cin >> s;
		cout << "Case # " << T << ":\n";
		int n = s.length();
		vec.clear();
		for (int i=0; i<n; ++i)
			vec.push_back(i);
		do {
			for (int i=0; i<n; ++i)
				cout << s[vec[i]];
			cout << '\n';
		} while (next_permutation(vec.begin(), vec.end()));
	}

	return 0;
}
