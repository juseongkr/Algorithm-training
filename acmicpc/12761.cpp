#include <iostream>
#include <queue>
using namespace std;
#define MAX 100001

int a, b, n, m;
int visit[MAX];

int main()
{
	cin >> a >> b >> n >> m;

	queue<pair<int, int>> que;
	que.push({n, 0});
	visit[n] = 1;

	while (!que.empty()) {
		int cur = que.front().first;
		int dist = que.front().second;
		que.pop();

		if (cur == m) {
			cout << dist << '\n';
			return 0;
		}

		int next = cur + 1;
		if (next < MAX && !visit[next]) {
			visit[next] = 1;
			que.push({next, dist+1});
		}

		next = cur - 1;
		if (next >= 0 && !visit[next]) {
			visit[next] = 1;
			que.push({next, dist+1});
		}

		next = cur + a;
		if (next < MAX && !visit[next]) {
			visit[next] = 1;
			que.push({next, dist+1});
		}

		next = cur - a;
		if (next >= 0 && !visit[next]) {
			visit[next] = 1;
			que.push({next, dist+1});
		}

		next = cur + b;
		if (next < MAX && !visit[next]) {
			visit[next] = 1;
			que.push({next, dist+1});
		}

		next = cur - b;
		if (next >= 0 && !visit[next]) {
			visit[next] = 1;
			que.push({next, dist+1});
		}
	
		next = cur * a;
		if (next < MAX && !visit[next]) {
			visit[next] = 1;
			que.push({next, dist+1});
		}

		next = cur * b;
		if (next < MAX && !visit[next]) {
			visit[next] = 1;
			que.push({next, dist+1});
		}
	}

	return 0;
}
