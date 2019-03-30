#include <iostream>
#include <queue>
using namespace std;

queue<int> que;
int visit[100001];
int dept[100001];
int n, k;

void bfs()
{
	que.push(n);
	visit[n] = 1;
	
	while (!que.empty()) {
		int pos = que.front();
		que.pop();

		int next = pos + 1;
		if (next <= 100000 && visit[next] == 0) {
			que.push(next);
			visit[next] = 1;
			dept[next] = dept[pos] + 1;
		}

		next = pos - 1;
		if (next >= 0 && visit[next] == 0) {
			que.push(next);
			visit[next] = 1;
			dept[next] = dept[pos] + 1;
		}

		next = pos * 2;
		if (next <= 100000 && visit[next] == 0) {
			que.push(next);
			visit[next] = 1;
			dept[next] = dept[pos] + 1;
		}
	}
}

int main()
{
	cin >> n >> k;

	bfs();

	cout << dept[k] << '\n';

	return 0;
}
