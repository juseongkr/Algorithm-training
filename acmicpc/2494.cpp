#include <iostream>
#include <cstring>
using namespace std;
#define MAX 10001

int n;
int a[MAX], b[MAX];
int dp[MAX][10], way[MAX][10], to[MAX][10], cost[MAX][10];
string s1, s2;

int solve(int idx, int turn)
{
	if (idx == n)
		return 0;

	if (dp[idx][turn] != -1)
		return dp[idx][turn];

	int cur = (a[idx] + turn) % 10;
	int l = (b[idx] - cur + 10) % 10;
	int r = (cur - b[idx] + 10) % 10;

	int left = solve(idx+1, (turn + l) % 10) + l;
	int right = solve(idx+1, turn) + r;

	if (left < right) {
		dp[idx][turn] = left;
		way[idx][turn] = 1;
		to[idx][turn] = (turn + l) % 10;
		cost[idx][turn] = l;
	} else {
		dp[idx][turn] = right;
		way[idx][turn] = 2;
		to[idx][turn] = turn;
		cost[idx][turn] = r;
	}
	return dp[idx][turn];
}

void show(int idx, int turn)
{
	if (idx == n)
		return;

	if (cost[idx][turn] == 0) {
		show(idx+1, turn);
	} else {
		cout << idx+1 << " ";
		if (way[idx][turn] == 2)
			cout << "-";
		cout << cost[idx][turn] << '\n';
		show(idx+1, to[idx][turn]);
	}
}

int main()
{
	cin >> n >> s1 >> s2;
	for (int i=0; i<n; ++i) {
		a[i] = s1[i]-'0';
		b[i] = s2[i]-'0';
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';
	show(0, 0);

	return 0;
}
