#include <iostream>
using namespace std;
#define MAX 51

int main()
{
	int dict[26];
	int n, cnt = -1;
	string s, t, ans;

	cin >> s >> n;
	while (n--) {
		cin >> t;
		fill(dict, dict+26, 0);
		for (int i=0; i<s.length(); ++i)
			dict[s[i]-'A']++;

		for (int i=0; i<t.length(); ++i)
			dict[t[i]-'A']++;

		int L = dict['L'-'A'];
		int O = dict['O'-'A'];
		int V = dict['V'-'A'];
		int E = dict['E'-'A'];
		int ret = ((L+O)*(L+V)*(L+E)*(O+V)*(O+E)*(V+E))%100;

		if (cnt < ret) {
			cnt = ret;
			ans = t;
		}
		if (cnt == ret && ans > t)
			ans = t;
	}
	cout << ans << '\n';

	return 0;
}
