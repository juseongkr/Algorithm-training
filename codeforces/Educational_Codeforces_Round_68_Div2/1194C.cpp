#include <iostream>
#include <map>
using namespace std;

int T;
string s, t, p;

int main()
{
	cin >> T;
	while (T--) {
		cin >> s >> t >> p;
		if (s == t) {
			cout << "YES\n";
			continue;
		}

		int idx = 0;
		map<char, int> m;
		for (int i=0; i<t.length(); ++i) {
			m[t[i]]++;
			if (t[i] == s[idx])
				idx++;
		}

		if (idx != s.length()) {
			cout << "NO\n";
			continue;
		}

		for (int i=0; i<s.length(); ++i)
			m[s[i]]--;

		for (int i=0; i<p.length(); ++i)
			m[p[i]]--;

		bool flag = true;
		for (auto i : m) {
			if (i.second > 0) {
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
