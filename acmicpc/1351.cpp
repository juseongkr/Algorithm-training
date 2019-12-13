#include <iostream>
#include <map>
using namespace std;
#define ll long long

ll n, p, q;
map<ll, ll> dp;

ll solve(ll n)
{
	if (n == 0)
		return 1;

	if (dp.count(n))
		return dp[n];
	
	return dp[n] = solve(n/p) + solve(n/q);
}

int main()
{
	cin >> n >> p >> q;

	cout << solve(n) << '\n';

	return 0;
}
