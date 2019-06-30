#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define MAX 100001

int n, m, a, b, ans, label, cnt = 1;
stack<int> st;
vector<int> graph[MAX];
int visit[MAX], finish[MAX], group[MAX], in[MAX];

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
			group[t] = label;
			finish[t] = 1;
			if (n == t)
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
		graph[a].push_back(b);
	}

	for (int i=0; i<n; ++i)
		if (!visit[i])
			dfs(i);

	for (int i=0; i<n; ++i) {
		for (int j=0; j<graph[i].size(); ++j) {
			int next = graph[i][j];
			if (group[i] != group[next])
				in[group[next]]++;
		}
	}

	for (int i=0; i<label; ++i)
		if (!in[i])
			ans++;

	cout << ans << '\n';

	return 0;
}
