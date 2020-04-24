#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define MAX 1001

int n, k, x, idx;
int mx[MAX], mi[MAX], com[MAX];
int dp[MAX][MAX];

class SCC {
public:
	int len, ord, label;
	vector<vector<int>> graph, scc_graph, comp;
	vector<int> id, in, out, group, sz;
	stack<int> st;

	SCC(int n) : len(n), ord(0), label(0)
	{
		graph.resize(n+1);
		group.resize(n+1, -1);
		id.resize(n+1);
		sz.resize(n+1);
	}

	int dfs(int cur)
	{
		id[cur] = ++ord;
		st.push(cur);

		int low = id[cur];
		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];
			if (id[next] == 0)
				low = min(low, dfs(next));
			else if (group[next] == -1)
				low = min(low, id[next]);
		}

		if (low == id[cur]) {
			comp.push_back(vector<int>());
			while (1) {
				int t = st.top();
				st.pop();
				sz[label]++;
				group[t] = label;
				comp[label].push_back(t);
				if (t == cur)
					break;
			}
			label++;
		}
		return low;
	}

	void getSCC()
	{
		for (int i=0; i<len; ++i)
			if (!id[i])
				dfs(i);
	}

	void getDAG()
	{
		getSCC();
		scc_graph.resize(label);
		in.resize(label);
		out.resize(label);

		for (int i=0; i<len; ++i) {
			for (int j=0; j<graph[i].size(); ++j) {
				int next = graph[i][j];
				if (group[i] == group[next])
					continue;
				scc_graph[group[i]].push_back(group[next]);
			}
		}

		for (int i=0; i<label; ++i) {
			sort(scc_graph[i].begin(), scc_graph[i].end());
			scc_graph[i].erase(unique(scc_graph[i].begin(), scc_graph[i].end()), scc_graph[i].end());
			for (int j=0; j<scc_graph[i].size(); ++j) {
				int next = scc_graph[i][j];
				in[next]++;
				out[i]++;
			}
		}
	}
};

int solve(int cur, int cap)
{
	if (cur > idx)
		return 0;

	if (~dp[cur][cap])
		return dp[cur][cap];

	dp[cur][cap] = solve(cur+1, cap);
	if (mi[cur] <= cap) {
		for (int i=mi[cur]; i<=mx[cur]; ++i) {
			if (cap < i)
				break;
			dp[cur][cap] = max(dp[cur][cap], solve(cur+1, cap-i) + i);
		}
	}
	return dp[cur][cap];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> k;
	SCC scc(n);
	for (int i=0; i<n; ++i) {
		cin >> x;
		x--;
		scc.graph[x].push_back(i);
	}

	scc.getDAG();

	queue<int> que;
	for (int i=0; i<scc.label; ++i) {
		if (!scc.in[i]) {
			que.push(i);
			com[i] = ++idx;
			mx[idx] = mi[idx] = scc.sz[i];
		}
	}

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i=0; i<scc.scc_graph[cur].size(); ++i) {
			int next = scc.scc_graph[cur][i];
			com[next] = com[cur];
			mx[com[next]] += scc.sz[next];
			if (--scc.in[next] == 0)
				que.push(next);
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(1, k) << '\n';

	return 0;
}
