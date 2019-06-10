#include <iostream>
#include <climits>
using namespace std;

string s, r, t;
int n, ans = INT_MAX;

void push(int i)
{
	s[i] = s[i] == '0' ? '1' : '0';
	if (i >= 1)
		s[i-1] = s[i-1] == '0' ? '1' : '0';
	if (i <= n-2)
		s[i+1] = s[i+1] == '0' ? '1' : '0';
}

void solve(int i, int cnt)
{
	if (i == n-1) {
		if (s == r)
			ans = min(ans, cnt);

		push(i);

		if (s == r)
			ans = min(ans, cnt+1);
		return;
	}

	if (s[i-1] == r[i-1])
		solve(i+1, cnt);

	push(i);

	if (s[i-1] == r[i-1])
		solve(i+1, cnt+1);
}

int main()
{
	cin >> n >> t >> r;

	s = t;
	solve(1, 0);
	s = t;
	push(0);
	solve(1, 1);

	if (ans != INT_MAX)
		cout << ans << '\n';
	else
		cout << "-1\n";

	return 0;
}
