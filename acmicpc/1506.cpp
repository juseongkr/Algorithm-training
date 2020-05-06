#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define MAX 101

string s;
int n, ans;
int cost[MAX];

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
			int val = cost[cur];
			while (1) {
				int t = st.top();
				val = min(val, cost[t]);
				st.pop();
				group[t] = label;
				comp[label].push_back(t);
				if (t == cur)
					break;
			}
			label++;
			ans += val;
		}
		return low;
	}

	void getSCC()
	{
		for (int i=0; i<len; ++i)
			if (!id[i])
				dfs(i);
	}
};

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> cost[i];

	SCC scc(n);
	for (int i=0; i<n; ++i) {
		cin >> s;
		for (int j=0; j<n; ++j) {
			if (s[j] == '1')
				scc.graph[i].push_back(j);
		}
	}
	scc.getSCC();

	cout << ans << '\n';

	return 0;
}
