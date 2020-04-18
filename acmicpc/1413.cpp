#include <iostream>
#include <cstring>
using namespace std;
#define MAX 21
#define ll long long

int n, m;
ll dp[MAX][MAX];

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll solve(int a, int b)
{
	if (a == 0)
		return 1;
	if (b == 0)
		return 0;

	if (~dp[a][b])
		return dp[a][b];

	return dp[a][b] = (a-1) * solve(a-1, b) + solve(a-1, b-1);
}

int main()
{
	cin >> n >> m;

	memset(dp, -1, sizeof(dp));
	ll x = solve(n, m);
	ll y = solve(n, n);
	ll g = gcd(x, y);

	cout << x / g << "/" << y / g << '\n';

	return 0;
}
