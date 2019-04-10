#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main()
{
	set<string> s;
	vector<string> v;
	string str;
	int n, m;

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> str;
		s.insert(str);
	}

	for (int i=0; i<m; ++i) {
		cin >> str;
		if (s.count(str))
			v.push_back(str);
	}

	sort(v.begin(), v.end());

	cout << v.size() << '\n';
	for (string i : v)
		cout << i << '\n';

	return 0;
}
