#include <iostream>
#include <queue>
using namespace std;

queue<int> que;
int family[101][101];
int visit[101], level[101];
int n, s, e, m, x, y;

void bfs(int start)
{
	visit[start] = 1;
	que.push(start);

	while (!que.empty()) {
		int t = que.front();
		que.pop();
		
		for (int i=1; i<=n; ++i) {
			if (visit[i] != 1 && family[t][i] == 1) {
				que.push(i);
				visit[i] = 1;
				level[i] = level[t] + 1;
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	scanf("%d %d", &s, &e);
	scanf("%d", &m);

	for (int i=0; i<m; ++i) {
		scanf("%d %d", &x, &y);
		family[x][y] = family[y][x] = 1;
	}
	
	bfs(s);

	if (level[e])
		printf("%d\n", level[e]);
	else
		printf("-1\n");

	return 0;
}
