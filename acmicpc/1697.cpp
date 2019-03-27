#include <iostream>
#include <queue>
using namespace std;

int visit[100001] = {0, };

int bfs(int n, int k)
{
	queue<pair<int, int>> que;

	que.push({n, 0});

	while (!que.empty()) {
		int cur = que.front().first;
		int dep = que.front().second;
		que.pop();

		if (cur == k)
			return dep;

		visit[cur] = 1;

		if (cur + 1 <= 100000 && visit[cur + 1] == 0)
			que.push({cur+1, dep+1});

		if (cur - 1 >= 0 && visit[cur - 1] == 0)
			que.push({cur-1, dep+1});

		if (cur * 2 <= 100000 && visit[cur * 2] == 0)
			que.push({cur*2, dep+1});

	}
	return que.front().second;
}

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);

	printf("%d\n", bfs(n, k));

	return 0;
}
