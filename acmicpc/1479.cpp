#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define MAX 2501
#define X first
#define Y second
const int INF = 1e9+7;

string s, p[4];
pair<int, int> dp[MAX][51][1<<4];

pair<int, int> solve(int cur, int cov, int bit)
{
	if (bit == 0)
		return {0, 0};

	if (cur == s.length())
		return {INF, -INF};

	auto &ref = dp[cur][cov][bit];
	if (ref.X != -1)
		return ref;

	ref = solve(cur+1, max(0, cov-1), bit);
	for (int i=0; i<4; ++i) {
		if ((bit & (1 << i)) && (s.substr(cur, p[i].length()) == p[i])) {
			int next = 0;
			if (p[i].length() > cov)
				next = (int)p[i].length() - cov;

			auto t = solve(cur, max(cov, (int)p[i].length()), bit - (1 << i));
			ref = {min(t.X + next, ref.X), max(t.Y + next, ref.Y)};
		}
	}

	return ref;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> s;
	for (int i=0; i<4; ++i)
		cin >> p[i];

	sort(p, p+4);
	memset(dp, -1, sizeof(dp));
	auto ans = solve(0, 0, (1<<4)-1);

	cout << ans.X << " " << ans.Y << '\n';

	return 0;
}
