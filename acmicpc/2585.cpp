#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
#include <tuple>
#include <cmath>
#include <queue>
using namespace std;
#define MAX 1001
typedef tuple<int, int, int> tiii;

int n, k, x, y;
vector<pair<int, int>> pos;
bool visit[MAX];

int dist(pair<int, int> u, pair<int, int> v)
{
	int x = u.first - v.first;
	int y = u.second - v.second;
	return ceil(sqrt(x * x + y * y) / 10);
}

bool bfs(int m, int s)
{
	memset(visit, false, sizeof(visit));
	queue<tiii> que;
	que.push({0, 0, s});

	while (!que.empty()) {
		auto [x, y, cnt] = que.front();
		que.pop();

		if (cnt < 0)
			continue;

		if (dist({10000, 10000}, {x, y}) <= m)
			return true;

		for (int i=0; i<pos.size(); ++i) {
			auto [nx, ny] = pos[i];
			if (!visit[i] && dist({x, y}, {nx, ny}) <= m) {
				visit[i] = true;
				que.push({nx, ny, cnt-1});
			}
		}
	}
	return false;
}

int main()
{
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		pos.push_back({x, y});
	}

	int l = 0, r = INT_MAX;
	while (l <= r) {
		int mid = (l+r)/2;
		if (bfs(mid, k))
			r = mid-1;
		else
			l = mid+1;
	}
	cout << l << '\n';

	return 0;
}
