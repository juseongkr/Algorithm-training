#include <iostream>
#include <climits>
using namespace std;
#define MAX 1000001

int dp[MAX], parent[MAX];

int dfs(int n)
{
	int k, min_val = INT_MAX;

	if (n == 0 || n == 1)
		return 0;

	if (dp[n] != -1)
		return dp[n];

	if (n % 3 == 0) {
		int next = dfs(n/3);
		if (min_val > next) {
			min_val = next;
			k = n / 3;
		}
	}
	if (n % 2 == 0) {
		int next = dfs(n/2);
		if (min_val > next) {
			min_val = next;
			k = n / 2;
		}
	}
	if (n > 1) {
		int next = dfs(n-1);
		if (min_val > next) {
			min_val = next;
			k = n-1;
		}
	}

	parent[n] = k;
	dp[n] = min_val + 1;
	return dp[n];
}

int main()
{
	int n;

	cin >> n;
	fill(dp, dp+MAX, -1);
	fill(parent, parent+MAX, -1);

	cout << dfs(n) << '\n';

	for (int i=n; i!=-1; i=parent[i])
		cout << i << " ";
	cout << '\n';

	return 0;
}
