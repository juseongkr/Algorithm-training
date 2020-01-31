#include <iostream>
#include <vector>
using namespace std;

int T;
vector<int> cnt[26];
string s, t;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> s >> t;
		for (int i=0; i<26; ++i)
			cnt[i].clear();

		for (int i=0; i<s.length(); ++i)
			cnt[s[i]-'a'].push_back(i);

		int ans = 1, idx = 0;
		for (int i=0; i<t.length(); ++i) {
			int cur = t[i]-'a';
			if (cnt[cur].size() == 0) {
				ans = -1;
				break;
			} else {
				auto it = lower_bound(cnt[cur].begin(), cnt[cur].end(), idx);
				if (it == cnt[cur].end()) {
					ans++;
					idx = cnt[cur][0];
				} else {
					idx = *it;
				}
			}
			idx++;
		}
		cout << ans << '\n';
	}

	return 0;
}
