#include <iostream>
#include <map>
using namespace std;

int n, mx;
string s;
map<string, int> m;

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> s;
		m[s]++;
	}

	for (auto i : m)
		mx = max(mx, i.second);

	for (auto i : m)
		if (i.second == mx)
			cout << i.first << '\n';

	return 0;
}
