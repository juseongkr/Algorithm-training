#include <iostream>
#include <set>
using namespace std;
#define MAX 7
const int INF = 1e9+7;

int n;
int num[MAX];
set<int> dp[(1 << MAX)];

bool is_prime(int x)
{
	if (x < 2)
		return false;

	for (int i=2; i*i<=x; ++i)
		if (x % i == 0)
			return false;
	return true;
}

set<int> solve(int bit)
{
	if (dp[bit].size() > 0 || !bit)
		return dp[bit];

	for (int i=0; i<(1 << n); ++i) {
		int x = bit & i;
		int y = bit & ~x;

		if (x == 0 || y == 0)
			continue;

		solve(x);
		solve(y);

		for (auto i : dp[x]) {
			for (auto j : dp[y]) {
				if (i)
					dp[bit].insert(j/i);
				if (j)
					dp[bit].insert(i/j);

				dp[bit].insert(i+j);
				dp[bit].insert(i-j);
				dp[bit].insert(i*j);
				dp[bit].insert(j-i);
			}
		}
	}

	return dp[bit];
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> num[i];
		dp[(1 << i)].insert(num[i]);
	}

	auto ret = solve((1 << n)-1);

	int mi = INF, mx = 0;
	for (auto i : ret) {
		if (is_prime(i)) {
			mi = min(mi, i);
			mx = max(mx, i);
		}
	}

	if (mi == INF)
		cout << "-1\n";
	else
		cout << mi << '\n' << mx << '\n';

	return 0;
}
