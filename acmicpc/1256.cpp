#include <iostream>
#include <cstring>
using namespace std;
const int INF = 1e9+7;
#define MAX 101

int n, m, k;
int dp[MAX][MAX];
string ans;
bool flag;

int solve(int a, int b)
{
	if (a == 0 || b == 0)
		return 1;

	if (~dp[a][b])
		return dp[a][b];

	dp[a][b] = min(INF, solve(a-1, b) + solve(a, b-1));

	return dp[a][b];
}

void skip(int a, int b, int k)
{
	if (a == 0) {
		for (int i=0; i<b; ++i)
			ans += 'z';
		return;
	}

	if (b == 0) {
		for (int i=0; i<a; ++i)
			ans += 'a';
		return;
	}

	int pivot = solve(a-1, b);
	if (k < pivot) {
		ans += 'a';
		skip(a-1, b, k);
	} else if (pivot < INF) {
		ans += 'z';
		skip(a, b-1, k-pivot);
	} else {
		flag = true;
	}
}

int main()
{
	cin >> n >> m >> k;
	memset(dp, -1, sizeof(dp));
	if (solve(n, m) < k)
		flag = true;
	else
		skip(n, m, k-1);

	if (flag)
		cout << "-1\n";
	else
		cout << ans << '\n';

	return 0;
}
