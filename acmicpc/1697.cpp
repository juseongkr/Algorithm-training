#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001
int visit[MAX];

int main()
{
	queue<pair<int, int>> que;
	int n, k;

	cin >> n >> k;

	que.push({n, 0});
	visit[n] = 1;
	while (!que.empty()) {
		int cur = que.front().first;
		int dep = que.front().second;
		que.pop();

		visit[cur] = 1;
		if (cur == k) {
			cout << dep << '\n';
			return 0;
		}

		if (cur + 1 <= MAX && !visit[cur+1])
			que.push({cur+1, dep+1});

		if (cur - 1 >= 0 && !visit[cur-1])
			que.push({cur-1, dep+1});

		if (cur * 2 <= MAX && !visit[cur*2])
			que.push({cur*2, dep+1});
	}

	return 0;
}
