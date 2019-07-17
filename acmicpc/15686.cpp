#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define MAX 51

int n, m, ans = INT_MAX;
int map[MAX][MAX];
bool visit[14];
vector<pair<int, int>> h, c;

int dist(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve(int cur, int choose)
{
	if (choose == m) {
		int ret = 0;
		for (int i=0; i<h.size(); ++i) {
			int d = INT_MAX;
			for (int j=0; j<c.size(); ++j)
				if (visit[j])
					d = min(d, dist(h[i], c[j]));
			ret += d;
		}
		ans = min(ans, ret);
		return;
	}

	if (cur == c.size())
		return;

	visit[cur] = 1;
	solve(cur+1, choose+1);
	visit[cur] = 0;
	solve(cur+1, choose);
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				h.push_back({i, j});
			else if (map[i][j] == 2)
				c.push_back({i, j});
		}
	}

	solve(0, 0);
	cout << ans << '\n';

	return 0;
}
