#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
	queue<int> que;
	vector<int> graph[1001];
	int in[1001], time[1001], ret[1001];
	int t, n, k, a, b, w;

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		for (int i=1; i<=n; ++i)
			scanf("%d", &time[i]);

		for (int i=0; i<k; ++i) {
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			in[b]++;
		}

		scanf("%d", &w);
		for (int i=1; i<=n; ++i) {
			if (!in[i]) {
				que.push(i);
				ret[i] = time[i];
			}
		}

		while (!que.empty()) {
			int q = que.front();
			que.pop();

			for (int i=0; i<graph[q].size(); ++i) {
				int next = graph[q][i];
				ret[next] = max(ret[next], ret[q] + time[next]);
				in[next]--;
				if (!in[next])
					que.push(next);
			}
		}

		printf("%d\n", ret[w]);

		while (!que.empty())
			que.pop();
		for (int i=0; i<1001; ++i)
			graph[i].clear();
		memset(in, 0, sizeof(in));
		memset(ret, 0, sizeof(ret));
		memset(time, 0, sizeof(time));
	}

	return 0;
}
