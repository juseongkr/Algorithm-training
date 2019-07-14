#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> dict[26];
	string s, t;
	int n, m;

	cin >> n >> s >> m;
	for (int i=0; i<s.length(); ++i)
		dict[s[i]-'a'].push_back(i+1);

	for (int k=0; k<m; ++k) {
		cin >> t;
		int ans = 0;
		int cur[26] = {0, };
		for (int i=0; i<t.length(); ++i) {
			int c = t[i]-'a';
			ans = max(ans, dict[c][cur[c]]);
			cur[c]++;
		}
		cout << ans << '\n';
	}
	
	return 0;
}
