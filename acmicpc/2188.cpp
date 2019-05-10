#include <iostream>
#include <queue>
#include <climits>
using namespace std;

#define MAX 505

int capa[MAX][MAX], flow[MAX][MAX], pre[MAX];

int main()
{
	int n, m, a, b;

	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; ++i) {
		scanf("%d", &a);
		for (int j=0; j<a; ++j) {
			scanf("%d", &b);
			capa[0][i] = capa[i][200+b] = capa[200+b][500] = 1;
		}
	}

	int total = 0, start = 0, end = 500;
	while (1) {
		queue<int> que;
		fill(pre, pre+MAX, -1);
		que.push(start);
		while (!que.empty()) {
			int cur = que.front();
			que.pop();
			if (cur == end)
				break;
			for (int next=0; next<MAX; ++next) {
				if (pre[next] == -1 && capa[cur][next] > flow[cur][next]) {
					que.push(next);
					pre[next] = cur;
				}
			}
		}
		if (pre[end] == -1)
			break;

		int min_val = INT_MAX;
		for (int i=end; i!=start; i=pre[i])
			min_val = min(min_val, capa[pre[i]][i] - flow[pre[i]][i]);

		for (int i=end; i!=start; i=pre[i]) {
			flow[pre[i]][i] += min_val;
			flow[i][pre[i]] -= min_val;
		}
		total += min_val;
	}
	printf("%d\n", total);

	return 0;
}
