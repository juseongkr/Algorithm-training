#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
	queue<int> que;
	vector<int> vec[501];
	int in[501], time[501], ret[501];
	int n, t;

	memset(ret, 0, sizeof(ret));
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		scanf("%d", &time[i]);
		while (scanf("%d", &t) && t != -1) {
			vec[t].push_back(i);
			in[i]++;
		}
	}

	for (int i=1; i<=n; ++i) {
		if (!in[i]) {
			que.push(i);
			ret[i] = time[i];
		}
	}

	while (!que.empty()) {
		int k = que.front();
		que.pop();

		for (int i=0; i<vec[k].size(); ++i) {
			int next = vec[k][i];
			ret[next] = max(ret[next], ret[k] + time[next]);
			in[next]--;
			if (!in[next])
				que.push(next);
		}
	}

	for (int i=1; i<=n; ++i)
		printf("%d\n", ret[i]);

	return 0;
}
