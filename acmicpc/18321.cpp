#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001
const int INF = 1e9+7;

int n, m, x, y, z;
int num[MAX], visit[MAX];
vector<pair<int, int>> graph[MAX];

void dfs(int cur, int cnt, int mid)
{
	if (visit[cur] == cnt)
		return;
	visit[cur] = cnt;

	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i].first;
		int next_cost = graph[cur][i].second;

		if (next_cost >= mid)
			dfs(next, cnt, mid);
	}
}

bool check(int mid)
{
	int cnt = 0;
	fill(visit, visit+MAX, -1);
	for (int i=1; i<=n; ++i)
		if (visit[i] == -1)
			dfs(i, cnt++, mid);

	for (int i=1; i<=n; ++i)
		if (visit[i] != visit[num[i]])
			return false;

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=1; i<=n; ++i)
		cin >> num[i];

	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}

	int l = 0, r = INF;
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid))
			l = mid+1;
		else
			r = mid-1;
	}

	if (r < INF)
		cout << r << '\n';
	else
		cout << "-1\n";

	return 0;
}
