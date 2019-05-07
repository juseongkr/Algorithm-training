#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

#define MAX 100001
stack<int> st;
vector<int> graph[MAX];
vector<vector<int>> ans;
int visit[MAX], finish[MAX], in[MAX], group[MAX];
int cnt, label, flag, idx;

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
		vector<int> temp;
		while (1) {
			int t = st.top();
			st.pop();
			finish[t] = 1;
			group[t] = label;
			temp.push_back(t);
			if (t == n)
				break;
		}
		label++;
		sort(temp.begin(), temp.end());
		ans.push_back(temp);
	}

	return ret;
}

int main()
{
	int t, n, m, a, b;

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i=0; i<m; ++i) {
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
		}

		for (int i=0; i<n; ++i)
			if (visit[i] == 0)
				dfs(i);

		for (int i=0; i<n; ++i) {
			for (int j=0; j<graph[i].size(); ++j) {
				int it = graph[i][j];
				if (group[i] != group[it])
					in[group[it]]++;
			}
		}

		for (int i=0; i<label; ++i)
			if (in[i] == 0) {
				flag++;
				idx = i;
			}

		if (flag == 1) {
			for (int i=0; i<n; ++i)
				if (group[i] == idx)
					printf("%d\n", i);
		} else {
			printf("Confused\n");
		}
		printf("\n");

		idx = -1;
		cnt = label = flag = 0;
		for (int i=0; i<ans.size(); ++i)
			ans[i].clear();
		for (int i=0; i<MAX; ++i) {
			visit[i] = finish[i] = group[i] = in[i] = 0;
			graph[i].clear();
		}
	}

	return 0;
}
