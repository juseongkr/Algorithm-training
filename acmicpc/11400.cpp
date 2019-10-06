#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define MAX 100001

int v, e, x, y, label;
vector<int> graph[MAX];
int dfsn[MAX];
set<pair<int, int>> cut;

int dfs(int cur, int prev=-1)
{
	int ret = dfsn[cur] = ++label;

	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		if (next == prev)
			continue;

		if (dfsn[next] != 0) {
			ret = min(ret, dfsn[next]);
		} else {
			int t = dfs(next, cur);
			ret = min(ret, t);
			if (t > dfsn[cur])
				cut.insert({min(cur, next), max(cur, next)});
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> v >> e;
	for (int i=0; i<e; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(1);

	cout << cut.size() << '\n';
	for (auto i : cut)
		cout << i.first << " " << i.second << '\n';

	return 0;
}
