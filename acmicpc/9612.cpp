#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
	string s;
	int n, mx = 0;
	vector<string> v;
	map<string, int> m;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> s;
		m[s]++;
	}
	
	for (auto i : m)
		mx = max(mx, i.second);

	for (auto i : m)
		if (i.second == mx)
			v.push_back(i.first);

	sort(v.begin(), v.end());

	cout << v.back() << ' ' << mx << '\n';

	return 0;
}
