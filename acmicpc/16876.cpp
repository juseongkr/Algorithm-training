#include <iostream>
#include <cstring>
using namespace std;
#define MAX 10001

int m;
int dp[MAX][101];
string n;

bool solve(string s, int t)
{
	if (t == m) {
		if (s > n)
			return true;
		else
			return false;
	}

	int num = stoi(s);
	if (dp[num][t] != -1)
		return dp[num][t];

	if (t % 2)
		dp[num][t] = true;
	else
		dp[num][t] = false;

	for (int i=0; i<4; ++i) {
		string p = s;
		if (p[i] == '9')
			p[i] = '0';
		else
			p[i]++;

		if (t % 2)
			dp[num][t] &= solve(p, t+1);
		else
			dp[num][t] |= solve(p, t+1);
	}

	return dp[num][t];
}

int main()
{
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	if (solve(n, 0))
		cout << "koosaga\n";
	else
		cout << "cubelover\n";

	return 0;
}
