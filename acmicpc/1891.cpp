#include <iostream>
using namespace std;
#define ll long long
#define X first
#define Y second

string s;

pair<ll, ll> divide(int i, ll r, ll c, ll l)
{
	if (l == 1)
		return {r, c};

	int t = s[i];
	if (t == '1')
		return divide(i+1, r, c+l/2, l/2);
	else if (t == '2')
		return divide(i+1, r, c, l/2);
	else if (t == '3')
		return divide(i+1, r+l/2, c, l/2);
	else
		return divide(i+1, r+l/2, c+l/2, l/2);
}

string solve(ll r, ll c, ll x, ll y, ll l)
{
	if (l == 1)
		return "";
	
	if (x < r+l/2 && y >= c+l/2)
		return "1" + solve(r, c+l/2, x, y, l/2);
	else if (x < r+l/2 && y < c+l/2)
		return "2" + solve(r, c, x, y, l/2);
	else if (x >= r+l/2 && y < c+l/2)
		return "3" + solve(r+l/2, c, x, y, l/2);
	else
		return "4" + solve(r+l/2, c+l/2, x, y, l/2);
}

int main()
{
	ll n, x, y;

	cin >> n >> s >> y >> x;
	n = (1LL << n);
	auto pos = divide(0, 0, 0, n);
	pos.X -= x;
	pos.Y += y;
	if (0 <= pos.X && pos.X < n && 0 <= pos.Y && pos.Y < n)
		cout << solve(0, 0, pos.X, pos.Y, n) << '\n';
	else
		cout << "-1\n";

	return 0;
}
