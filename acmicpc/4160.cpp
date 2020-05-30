#include <iostream>
using namespace std;
#define MAX 25

int n, ans;
int num[MAX], psum[MAX];

void solve(int cur, int diff, int both)
{
	if (diff == 0)
		ans = max(ans, both);

	if (cur == 0 || abs(diff) > psum[cur] || ans - both > psum[cur])
		return;

	solve(cur-1, diff + num[cur], both + num[cur]);
	solve(cur-1, diff - num[cur], both + num[cur]);
	solve(cur-1, diff, both);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	while (1) {
		cin >> n;
		if (n == 0)
			break;

		ans = 0;
		psum[0] = 0;
		for (int i=1; i<=n; ++i) {
			cin >> num[i];
			psum[i] = psum[i-1] + num[i];
		}

		solve(n, 0, 0);

		cout << psum[n] - ans << '\n';
	}

	return 0;
}
