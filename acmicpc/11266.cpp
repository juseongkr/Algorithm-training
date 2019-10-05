#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define MAX 100001

int v, e, x, y, label, root;
vector<int> graph[MAX];
int dfsn[MAX];
set<int> cut;

int dfs(int cur)
{
	int ret = dfsn[cur] = ++label;
	int child = 0;

	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];

		if (dfsn[next] != 0) {
			ret = min(ret, dfsn[next]);
		} else {
			int t = dfs(next);
			ret = min(ret, t);
			if (t >= dfsn[cur] && cur != root)
				cut.insert(cur);
			child++;
		}
	}
	if (cur == root && child > 1)
		cut.insert(cur);
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

	for (int i=1; i<=v; ++i) {
		if (dfsn[i] == 0) {
			root = i;
			dfs(i);
		}
	}

	cout << cut.size() << '\n';
	for (int i : cut)
		cout << i << " ";

	return 0;
}
