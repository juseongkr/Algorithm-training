#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;
#define MAX 17
const double INF = 1e9;

int n;
double x[MAX], y[MAX], dp[MAX][1 << MAX];

double dist(double x1, double y1, double x2, double y2)
{
	double x = abs(x1-x2);
	double y = abs(y1-y2);
	return sqrt(x*x + y*y);
}

double solve(int cur, int bit)
{
	if (bit == (1 << n)-1)
		return dp[cur][bit] = dist(x[cur], y[cur], x[0], y[0]);

	if (dp[cur][bit])
		return dp[cur][bit];

	dp[cur][bit] = INF;
	for (int i=0; i<n; ++i) {
		if (bit & (1 << i))
			continue;
		dp[cur][bit] = min(dp[cur][bit], solve(i, bit | (1 << i)) + dist(x[cur], y[cur], x[i], y[i]));
	}

	return dp[cur][bit];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> x[i] >> y[i];

	cout << fixed << setprecision(6) << solve(0, 1) << '\n';

	return 0;
}
