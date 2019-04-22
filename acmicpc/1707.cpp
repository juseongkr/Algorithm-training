#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> graph[20001];
int group[20001];

void dfs(int n, int c)
{
	group[n] = c;
	for (int i=0; i<graph[n].size(); ++i) {
		int next = graph[n][i];
		if (group[next] == 0)
			dfs(next, -1 * c);
	}
}

int main()
{
	int k, n, m, a, b;
	bool flag;

	scanf("%d", &k);
	while (k--) {
		scanf("%d %d", &n, &m);
		memset(group, 0, sizeof(group));
		for (int i=1; i<=n; ++i)
			graph[i].clear();

		for (int i=0; i<m; ++i) {
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int i=1; i<=n; ++i)
			if (group[i] == 0)
				dfs(i, 1);
        
		flag = true;
		for (int i=1; i<=n; ++i) {
			for (int j=0; j<graph[i].size(); ++j) {
				if (group[i] == group[graph[i][j]])  {
					flag = false;
					break;
				}
			}
		}
		
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
