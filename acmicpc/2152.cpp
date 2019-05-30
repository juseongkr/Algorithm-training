#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define MAX 10001

stack<int> st;
vector<int> graph[MAX], group_graph[MAX];
int visit[MAX], finish[MAX], group[MAX], in[MAX], city[MAX], max_city[MAX], path[MAX];
int n, m, s, t, a, b, cnt, label, start, dest;

int dfs(int n)
{
	visit[n] = ++cnt;
	st.push(n);

	int ret = visit[n];
	for (int i=0; i<graph[n].size(); ++i) {
		int next = graph[n][i];
		if (!visit[next])
			ret = min(ret, dfs(next));
		else if (!finish[next])
			ret = min(ret, visit[next]);
	}

	if (ret == visit[n]) {
		while (1) {
			int t = st.top();
			st.pop();
			finish[t] = 1;
			group[t] = label;
			city[label]++;
			if (n == t)
				break;
		}
		label++;
	}
	return ret;
}

int main()
{
	cin >> n >> m >> s >> t;
	for (int i=0; i<m; ++i) {
		cin >> a >> b;
		graph[a].push_back(b);
	}
	
	for (int i=1; i<=n; ++i)
		if (!visit[i])
			dfs(i);

	start = group[s];
	dest = group[t];
	for (int i=1; i<=n; ++i) {
		int cur = group[i];
		for (int j=0; j<graph[i].size(); ++j) {
			int next = group[graph[i][j]];
			if (cur != next) {
				group_graph[cur].push_back(next);
				in[next]++;
			}
		}
	}

	queue<int> que;
	for (int i=0; i<label; ++i) {
		max_city[i] = city[i];
		if (i == start)
			path[i] = 1;
		if (!in[i])
			que.push(i);
	}

	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		for (int i=0; i<group_graph[cur].size(); ++i) {
			int next = group_graph[cur][i];
			if (path[cur]) {
				max_city[next] = max(max_city[next], max_city[cur] + city[next]);
				path[next] = 1;
			}
			if (--in[next] == 0)
				que.push(next);
		}
	}

	if (path[dest])
		cout << max_city[dest] << '\n';
	else
		cout << "0\n";

	return 0;
}
