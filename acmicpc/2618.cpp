#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001

int n, w;
bool path[MAX][MAX];
int x[MAX], y[MAX], dp[MAX][MAX];

int dist(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

int solve(int a, int b)
{
	if (a == w || b == w)
		return 0;

	if (~dp[a][b])
		return dp[a][b];

	int cur = max(a, b);

	int A = solve(cur+1, b);
	if (a == 0)
		A += dist(1, 1, x[cur], y[cur]);
	else
		A += dist(x[a-1], y[a-1], x[cur], y[cur]);

	int B = solve(a, cur+1);
	if (b == 0)
		B += dist(n, n, x[cur], y[cur]);
	else
		B += dist(x[b-1], y[b-1], x[cur], y[cur]);

	path[a][b] = A > B;

	return dp[a][b] = min(A, B);
}

void print(int a, int b)
{
	if (a == w || b == w)
		return;

	cout << path[a][b] + 1 << '\n';
	int cur = max(a, b);
	if (path[a][b])
		print(a, cur+1);
	else
		print(cur+1, b);
}

int main()
{
	cin >> n >> w;
	for (int i=0; i<w; ++i)
		cin >> x[i] >> y[i];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';
	print(0, 0);

	return 0;
}
