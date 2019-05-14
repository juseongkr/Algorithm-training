#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

#define MAX 1001
int visit[MAX];

int main()
{
	queue<tuple<int, int, int>> que;
	int n;

	cin >> n;

	que.push({1, 0, 0});
	while (!que.empty()) {
		auto [cur, clip, time]  = que.front();
		que.pop();
		
		if (cur == n) {
			cout << time << '\n';
			return 0;
		}

		if (cur < 0 || cur > MAX || clip > MAX)
			continue;

		if (!visit[cur]) {
			que.push({cur, cur, time+1});
			visit[cur] = 1;
		}
		que.push({cur+clip, clip, time+1});
		que.push({cur-1, clip, time+1});
	}

	return 0;
}
