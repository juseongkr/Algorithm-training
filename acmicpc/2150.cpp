#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

#define MAX 100001
int visit[MAX], finish[MAX];
vector<int> graph[MAX];
vector<vector<int>> ans;
stack<int> st;
int cnt = 1;

int dfs(int n)
{
	visit[n] = cnt++;
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
		vector<int> tmp;
		while (1) {
			int t = st.top();
			st.pop();
			tmp.push_back(t);
			finish[t] = 1;
			if (t == n)
				break;
		}
		sort(tmp.begin(), tmp.end());
		ans.push_back(tmp);
	}

	return ret;
}

int main()
{
	int v, e, a, b;
	
	scanf("%d %d", &v, &e);
	for (int i=0; i<e; ++i) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
	}

	for (int i=1; i<=v; ++i)
		if (!visit[i])
			dfs(i);

	sort(ans.begin(), ans.end());

	printf("%lu\n", ans.size());
	for (int i=0; i<ans.size(); ++i) {
		for (int j=0; j<ans[i].size(); ++j)
			printf("%d ", ans[i][j]);
		printf("-1\n");
	}

	return 0;
}
