#include <iostream>
#include <queue>
using namespace std;

int state[2002][2002];

int main()
{
	queue<pair<int, int>> que;
	int n;

	cin >> n;
	que.push({1, 0});
	while (!que.empty()) {
		auto [cur, clip] = que.front();
		que.pop();
		if (cur == n) {
			cout << state[cur][clip];
			return 0;
		}

		int a[3] = {cur, cur+clip, cur-1};
		int b[3] = {cur, clip, clip};
		for (int i=0; i<3; ++i) {
			int next_cur = a[i];
			int next_clip = b[i];
			if (next_cur < 0 || next_cur > n * 2 || state[next_cur][next_clip])
				continue;

			que.push({next_cur, next_clip});
			state[next_cur][next_clip] = state[cur][clip] + 1;
		}
	}

	return 0;
}
