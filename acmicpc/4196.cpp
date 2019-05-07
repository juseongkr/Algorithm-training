#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define MAX 100001
vector<int> graph[MAX];
stack<int> st;
int visit[MAX], finish[MAX], group[MAX], in[MAX];
int cnt, label;

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
	int t, n, m, a, b, ans;

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		cnt = 0, label = 0, ans = 0;
		for (int i=0; i<MAX; ++i) {
			visit[i] = finish[i] = group[i] = in[i] = 0;
			graph[i].clear();
		}

		for (int i=0; i<m; ++i) {
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
		}

		for (int i=1; i<=n; ++i)
			if (visit[i] == 0)
				dfs(i);

		for (int i=1; i<=n; ++i) {
			for (int j=0; j<graph[i].size(); ++j) {
				int it = graph[i][j];
				if (group[i] != group[it])
					in[group[it]]++;
			}
		}

		for (int i=0; i<label; ++i)
			if (in[i] == 0)
				ans++;

		printf("%d\n", ans);
	}

	return 0;
}
