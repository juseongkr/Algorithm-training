#include <iostream>
using namespace std;
#define MAX 1001

int n, m, t;
int cnt[5], opt[MAX];
string s[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> s[i];

	for (int i=0; i<m; ++i) {
		fill(cnt, cnt+5, 0);
		for (int j=0; j<n; ++j)
			cnt[s[j][i]-'A']++;

		int max_val = 0;
		for (int j=0; j<5; ++j)
			max_val = max(max_val, cnt[j]);
		opt[i] = max_val;
	}

	int ans = 0;
	for (int i=0; i<m; ++i) {
		cin >> t;
		ans += (opt[i] * t);
	}
	cout << ans << '\n';

	return 0;
}
