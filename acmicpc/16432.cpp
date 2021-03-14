#include <iostream>
#include <vector>
using namespace std;
#define MAX 1001

int n, k, x;
int visit[MAX][10], ans[MAX];
vector<int> graph[MAX];
bool flag;

void dfs(int cur, int prev)
{
	if (cur == n) {
		for (int i=0; i<n; ++i)
			cout << ans[i] << '\n';
		flag = true;
		exit(0);
	}

	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];

		if (prev == next || visit[cur][next])
			continue;

		ans[cur] = next;
		visit[cur][next] = 1;
		dfs(cur+1, next);
	}
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> k;
		for (int j=0; j<k; ++j) {
			cin >> x;
			graph[i].push_back(x);
		}
	}

	dfs(0, -1);

	if (!flag)
		cout << "-1\n";

	return 0;
}
