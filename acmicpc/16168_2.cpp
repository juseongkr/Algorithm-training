#include <iostream>
#include <vector>
using namespace std;
#define MAX 3001

int v, e, x, y;
int in[MAX];
bool visit[MAX];
vector<int> graph[MAX];

void dfs(int cur)
{
	if (visit[cur])
		return;
	visit[cur] = true;

	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		in[cur]++;
		dfs(next);
	}
}

int main()
{
	cin >> v >> e;
	for (int i=0; i<e; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	int cnt = 0, ans = 0;
	for (int i=1; i<=v; ++i) {
		if (visit[i])
			continue;

		cnt++;
		fill(in, in+MAX, 0);
		dfs(i);
		for (int j=1; j<=v; ++j)
			if (in[j] % 2 == 1)
				ans++;
	}

	if (cnt == 1 && (ans == 0 || ans == 2))
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
