#include <iostream>
#include <queue>
using namespace std;
#define MAX 100000

bool visit[MAX];

int main()
{
	int n, t, g;

	cin >> n >> t >> g;

	queue<pair<int, int>> que;
	visit[n] = true;
	que.push({n, 0});

	while (!que.empty()) {
		auto [cur, cnt] = que.front();
		que.pop();

		if (cnt > t)
			break;

		if (cur == g) {
			cout << cnt << '\n';
			return 0;
		}

		if (cur+1 < MAX && !visit[cur+1]) {
			visit[cur+1] = true;
			que.push({cur+1, cnt+1});
		}

		if (cur*2 >= MAX)
			continue;

		int next = cur*2;
		int temp = next;
		int len = 1;
		while (temp) {
			temp /= 10;
			len *= 10;
		}
		next -= (len / 10);
		if (next < MAX && !visit[next]) {
			visit[next] = true;
			que.push({next, cnt+1});
		}
	}
	cout << "ANG\n";

	return 0;
}
