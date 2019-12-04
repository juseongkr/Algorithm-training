#include <iostream>
using namespace std;
const int INF = 1e9+7;

int num[12], cnt[4], total[4], ans;

void solve(int m)
{
	if (m == 12) {
		int mx = -INF, mi = INF;
		for (int i=0; i<4; ++i) {
			mx = max(mx, total[i]);
			mi = min(mi, total[i]);
		}
		ans = min(ans, mx-mi);
		return;
	}

	for (int i=0; i<4; ++i) {
		if (cnt[i] < 3) {
			cnt[i]++;
			total[i] += num[m];
			solve(m+1);
			total[i] -= num[m];
			cnt[i]--;
		}
	}
}

int main()
{
	for (int i=0; i<12; ++i)
		cin >> num[i];

	ans = INF;
	solve(0);

	cout << ans << '\n';

	return 0;
}
