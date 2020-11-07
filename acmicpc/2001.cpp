#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MAX 101
typedef pair<int, int> pi;

int n, m, k, x, y, z;
int jewel[MAX];
bool visit[MAX][(1 << 15)];
vector<pi> graph[MAX];
int ans;

void dfs(int cur, int bit, int cnt)
{
	if (cur == 1 && ans < cnt)
		ans = cnt;

	visit[cur][bit] = 1;

	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i].first;
		int next_cost = graph[cur][i].second;
		int next_bit = bit | (1 << jewel[cur]);

		if (next_cost >= cnt && !visit[next][bit])
			dfs(next, bit, cnt);

		if (jewel[cur] && next_cost >= cnt+1 && !visit[next][next_bit])
			dfs(next, next_bit, cnt+1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0; i<k; ++i) {
		cin >> x;
		jewel[x] = i+1;
	}

	graph[1].push_back({1, (1 << 15)-1});
	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}

	dfs(1, 0, 0);

	cout << ans << '\n';

	return 0;
}
