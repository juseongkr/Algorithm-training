#include <iostream>
using namespace std;
const int INF = 1e9+7;

string s;
int n, ans = -INF;

int calc(int x, char op, int y)
{
	switch (op) {
	case '+':
		return x + y;
	case '-':
		return x - y;
	default:
		return x * y;
	}
}

void solve(int cur, int val)
{
	if (cur >= s.length()) {
		ans = max(ans, val);
		return;
	}

	int next = calc(val, s[cur-1], s[cur]-'0');
	solve(cur+2, next);

	if (cur+2 < s.length()) {
		int bracket = calc(s[cur]-'0', s[cur+1], s[cur+2]-'0');
		next = calc(val, s[cur-1], bracket);
		solve(cur+4, next);
	}
}

int main()
{
	cin >> n >> s;
	s = '+' + s;

	solve(1, 0);

	cout << ans << '\n';

	return 0;
}
