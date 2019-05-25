#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define MAX 500001

stack<int> st;
queue<int> que;
vector<int> graph[MAX], group_graph[MAX];
int n, m, a, b, c, s, k;
int cnt, label, group_start, ans;
int visit[MAX], finish[MAX], cash[MAX], rest[MAX], group[MAX];
int group_max[MAX], group_path[MAX], group_rest[MAX], group_cash[MAX], group_in[MAX];

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
			if (t == n)
				break;
		}
		label++;
	}
	return ret;
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b;
		graph[a-1].push_back(b-1);
	}

	for (int i=0; i<n; ++i)
		cin >> cash[i];

	for (int i=0; i<n; ++i)
		if (!visit[i])
			dfs(i);

	cin >> s >> k;
	s--;
	for (int i=0; i<k; ++i) {
		cin >> c;
		rest[c-1] = 1;
	}

	for (int i=0; i<n; ++i) {
		int cur = group[i];
		group_cash[cur] += cash[i];
		if (rest[i])
			group_rest[cur] = 1;
		if (s == i)
			group_start = cur;

		for (int j=0; j<graph[i].size(); ++j) {
			int next = group[graph[i][j]];
			if (cur != next) {
				group_graph[cur].push_back(next);
				group_in[next]++;
			}
		}
	}

	for (int i=0; i<label; ++i) {
		group_max[i] = group_cash[i];
		if (i == group_start)
			group_path[i] = 1;
		if (!group_in[i])
			que.push(i);
	}
	
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		for (int i=0; i<group_graph[cur].size(); ++i) {
			int next = group_graph[cur][i];
			if (group_path[cur]) {
				group_max[next] = max(group_max[next], group_max[cur] + group_cash[next]);
				group_path[next] = 1;
			}
			if (--group_in[next] == 0)
				que.push(next);
		}
	}

	for (int i=0; i<label; ++i)
		if (group_rest[i] && group_path[i])
			ans = max(ans, group_max[i]);
	cout << ans << '\n';

	return 0;
}
