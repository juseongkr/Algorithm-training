#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 100001

int t;
int dp[5][5][MAX];
vector<int> v;

int power(int a, int b)
{
	if (a == 0)
		return 2;
	if (a == b)
		return 1;
	if (abs(a - b) == 2)
		return 4;
	else
		return 3;
}

int solve(int a, int b, int c)
{
	if (c == v.size())
		return 0;

	if (dp[a][b][c] != -1)
		return dp[a][b][c];

	dp[a][b][c] = min(solve(v[c], b, c+1) + power(a, v[c]), \
			  solve(a, v[c], c+1) + power(b, v[c]));
	return dp[a][b][c];
}

int main()
{
	while (1) {
		cin >> t;
		if (t == 0)
			break;
		v.push_back(t);
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, 0) << '\n';

	return 0;
}
