#include <iostream>
#include <queue>
using namespace std;
#define MAX 101

int board[MAX], visit[MAX];

int main()
{
	int n, m, x, y;

	cin >> n >> m;
	for (int i=1; i<=100; ++i)
		board[i] = i;

	for (int i=0; i<n+m; ++i) {
		cin >> x >> y;
		board[x] = y;
	}

	queue<int> que;
	visit[1] = 1;
	que.push(1);
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		for (int i=1; i<=6; ++i) {
			int next = board[cur + i];
			if (next > 100)
				continue;
			if (!visit[next]) {
				que.push(next);
				visit[next] = visit[cur] + 1;
			}
		}
	}
	cout << visit[100] - 1 << '\n';

	return 0;
}
