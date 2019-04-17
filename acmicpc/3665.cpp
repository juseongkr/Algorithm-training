#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	vector<int> ans;
	queue<int> que;
	int in[501], place[501];
	int graph[501][501];
	int t, n, a, b, m;

	scanf("%d", &t);
	while (t--) {
		memset(graph, 0, sizeof(graph));
		memset(place, 0, sizeof(place));
		memset(in, 0, sizeof(in));
		ans.clear();

		scanf("%d", &n);
		for (int i=1; i<=n; ++i)
			scanf("%d", &place[i]);

		for (int i=1; i<=n; ++i) {
			for (int j=i+1; j<=n; ++j) {
				graph[place[i]][place[j]] = 1;
				in[place[j]]++;
			}
		}

		scanf("%d", &m);
		for (int i=0; i<m; ++i) {
			scanf("%d %d", &a, &b);
			if (graph[a][b] == 1) {
				graph[a][b] = 0;
				graph[b][a] = 1;
				in[b]--;
				in[a]++;
			} else {
				graph[b][a] = 0;
				graph[a][b] = 1;
				in[b]++;
				in[a]--;
			}
		}

		for (int i=1; i<=n; ++i)
			if (!in[i])
				que.push(i);

		for (int i=0; i<n; ++i) {
			if (que.empty()) {
				printf("IMPOSSIBLE\n");
				break;
			}
			int tmp = que.front();
			que.pop();
			ans.push_back(tmp);

			for (int j=1; j<=n; ++j) {
				if (graph[tmp][j] == 1) {
					in[j]--;
					if (!in[j])
						que.push(j);
				}
			}
		}

		if (que.size() > 1) {
			printf("?\n");
		} else if (ans.size() == n) {
			for (int i : ans)
				printf("%d ", i);
			printf("\n");
		}

		while (!que.empty())
			que.pop();
	}

	return 0;
}
