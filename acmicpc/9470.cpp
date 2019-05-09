#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1001

int main()
{
	int t, k, m, p, a, b;
	vector<int> graph[MAX];
	queue<int> que;
	int in[MAX], cnt[MAX], ord[MAX];

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &k, &m, &p);
		for (int i=0; i<MAX; ++i) {
			graph[i].clear();
			in[i] = cnt[i] = ord[i] = 0;
		}

		for (int i=0; i<p; ++i) {
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			in[b]++;
		}

		for (int i=1; i<=m; ++i) {
			if (in[i] == 0) {
				que.push(i);
				ord[i] = 1;
			}
		}

		int max_val = 0;
		while (!que.empty()) {
			int cur = que.front();
			que.pop();

			if (cnt[cur])
				ord[cur]++;

			max_val = max(max_val, ord[cur]);

			for (int i=0; i<graph[cur].size(); ++i) {
				int next = graph[cur][i];

				if (ord[cur] == ord[next]) {
					cnt[next]++;
				} else if (ord[cur] > ord[next]) {
					ord[next] = ord[cur];
					cnt[next] = 0;
				}

				in[next]--;
				if (!in[next])
					que.push(next);
			}
		}
		printf("%d %d\n", k, max_val);
	}

	return 0;
}
