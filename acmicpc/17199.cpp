#include <iostream>
#include <vector>
using namespace std;
#define MAX 101

vector<int> graph[MAX];
int visit[MAX], dest[MAX];

void dfs(int n)
{
	visit[n] = 1;
	for (int i=0; i<graph[n].size(); ++i) {
		int next = graph[n][i];
		if (!visit[next]) {
			visit[next] = 1;
			dfs(next);
		}
	}
}

int main()
{
	int n, a, b;

	cin >> n;
	for (int i=0; i<n-1; ++i) {
		cin >> a >> b;
		graph[a].push_back(b);
	}

	for (int i=1; i<=n; ++i) {
		fill(visit, visit+MAX, 0);
		dfs(i);
		for (int j=1; j<=n; ++j)
			if (visit[j])
				dest[j]++;
	}

	for (int i=1; i<=n; ++i) {
		if (dest[i] == n) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << "-1\n";

	return 0;
}
