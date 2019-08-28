#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

class SCC {
public:
	int len;
	vector<vector<int>> graph, scc_graph, comp;
	vector<int> id, in, out, group;
	stack<int> st;
	int ord, label;

	SCC(int n) : len(n), ord(0), label(0)
	{
		graph.resize(n+1);
		group.resize(n+1, -1);
		id.resize(n+1);
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
		for (int i=1; i<=len; ++i)
			if (!id[i])
				dfs(i);
	}

	void getDAG()
	{
		getSCC();
		scc_graph.resize(label);
		in.resize(label);
		out.resize(label);

		for (int i=1; i<=len; ++i) {
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n, m, a, b;

	cin >> t;
	while (t--) {
		cin >> n >> m;
		SCC s = SCC(n);
		for (int i=0; i<m; ++i) {
			cin >> a >> b;
			s.graph[a].push_back(b);
		}

		s.getDAG();

		int ans = 0;
		for (int i=0; i<s.label; ++i)
			if (s.in[i] == 0)
				ans++;

		cout << ans << '\n';
	}

	return 0;
}
