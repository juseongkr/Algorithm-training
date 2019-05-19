#include <iostream>
#include <vector>
using namespace std;

#define MAX 151
vector<int> graph[MAX];
int visit[MAX];

void dfs(int n)
{
	for (int i=0; i<graph[n].size(); ++i) {
		int next = graph[n][i];
		if (!visit[next]) {
			visit[next] = visit[n] + 1;
			dfs(next);
		}
	}
}

int main()
{
	int n, k, t;
	
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> t;
		graph[i].push_back(t);
	}

	dfs(0);

	int ans = visit[k];
	if (ans)
		cout << ans << '\n';
	else
		cout << "-1\n";

	return 0;
}
