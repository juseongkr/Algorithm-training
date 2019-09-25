#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001

int n, m, p, x, y;
vector<int> graph[MAX];
bool visit[MAX];

int bfs()
{
	queue<int> que;
	visit[p] = true;
	que.push(p);

	int cnt = 0;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		if (!graph[cur].size())
			return cnt;

		int next = graph[cur][0];
		if (!visit[next]) {
			visit[next] = true;
			que.push(next);
			cnt++;
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> p;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		graph[y].push_back(x);
	}
	cout << bfs() << '\n';

	return 0;
}
