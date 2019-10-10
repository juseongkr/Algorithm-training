#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	map<string, int> m;
	string s, t;
	int n;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> s >> t;
		string code = s.substr(0, 2);
		if (code != t) {
			code += t;
			if (!m.count(code))
				m[code] = 0;
			m[code]++;
		}
	}

	int ans = 0;
	for (auto it : m) {
		string code = it.first.substr(2) + it.first.substr(0, 2);
		if (m.count(code))
			ans += it.second * m[code];
	}
	cout << ans / 2 << '\n';

	return 0;
}
