#include <iostream>
#include <cstring>
using namespace std;
#define MAX 30001

bool check[MAX], prime[MAX];
int dp[MAX];

int dfs(int k)
{
	if (k == 0)
		return 0;
	if (dp[k] != -1)
		return dp[k];

	dp[k] = 0;
	if (prime[k])
		dp[k] = 1;

	string s = to_string(k);
	for (int i=0; i<s.length(); ++i) {
		string t;
		for (int j=0; j<i; ++j)
			t += s[j];
		for (int j=i+1; j<s.length(); ++j)
			t += s[j];
		int next = atoi(t.c_str());

		if (prime[next])
			dp[k] = max(dp[k], dfs(next) + 1);
	}
	return dp[k];
}

int main()
{
	int test, a, b;

	fill(dp, dp+MAX, -1);
	fill(check+2, check+MAX, true);
	for (int i=2; i<MAX; ++i) {
		if (check[i])
			prime[i] = true;
		for (int j=i; j<MAX; j+=i)
			check[j] = false;
	}

	cin >> test;
	for (int c=1; c<=test; ++c) {
		cin >> a >> b;
		int x = dfs(a);
		int y = dfs(b);
		int ans = 0;

		if (x > y)
			ans = 1;
		else if (x < y)
			ans = 2;
		else
			ans = 3;

		cout << "Case #" << c << '\n' << ans << '\n';
	}

	return 0;
}
