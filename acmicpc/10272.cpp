#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
#define MAX 513
const int INF = 1e9+7;

int t, n, x, y;
double dp[MAX][MAX];
vector<pair<int, int>> vec;

inline double dist(pair<int, int> x, pair<int, int> y)
{
	double a = x.first - y.first;
	double b = x.second - y.second;
	return sqrt(a*a + b*b);
}

double solve(int a, int b)
{
	if (b == n-1)
		return dist(vec[a], vec[b]);

	if (dp[a][b])
		return dp[a][b];

	dp[a][b] = min(solve(a, b+1) + dist(vec[b], vec[b+1]),
			solve(b, b+1) + dist(vec[a], vec[b+1]));

	return dp[a][b];
}

int main()
{
	cin >> t;
	while (t--) {
		cin >> n;
		vec.clear();
		for (int i=0; i<n; ++i) {
			cin >> x >> y;
			vec.push_back({x, y});
		}

		memset(dp, 0, sizeof(dp));
		cout << solve(0, 0) << '\n';
	}

	return 0;
}
