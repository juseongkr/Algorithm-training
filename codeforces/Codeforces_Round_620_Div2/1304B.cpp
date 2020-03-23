#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, m;
	string s, mid, ans;
	map<string, int> mp;

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> s;
		string r = s;
		reverse(r.begin(), r.end());
		if (r == s) {
			mid = s;
			continue;
		}
		mp[s]++;
	}

	for (auto i : mp) {
		string r = i.first;
		reverse(r.begin(), r.end());

		if (mp.count(r)) {
			for (int j=0; j<i.second; ++j)
				ans += i.first;
			mp[i.first] = 0;
			mp[r] = 0;
		}
	}

	if (ans.length() == 0 && mid.length() == 0) {
		cout << "0\n";
	} else {
		string ret = ans + mid;
		reverse(ans.begin(), ans.end());
		ret += ans;
		cout << ret.length() << '\n' << ret << '\n';
	}

	return 0;
}
