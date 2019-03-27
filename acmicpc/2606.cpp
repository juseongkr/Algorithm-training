#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[101][101];
int visit[101];

int dfs()
{
	queue<int> que;
	int cnt = 0;

	que.push(1);
	visit[1] = 1;

	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		cnt++;

		for (int i=1; i<=n; ++i) {
			if (visit[i] != 1 && arr[cur][i] != 0) {
				visit[i] = 1;
				que.push(i);
			}
		}
	}
	
	return cnt;
}

int main()
{
	int a, b;

	scanf("%d %d", &n, &m);

	for (int i=0; i<m; ++i) {
		scanf("%d %d", &a, &b);
		arr[a][b] = arr[b][a] = 1;
	}

	printf("%d\n", dfs() - 1);

	return 0;
}
