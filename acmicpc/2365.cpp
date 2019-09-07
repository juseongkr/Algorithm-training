#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define INF 100001
#define MAX 103
const int src = 101, sink = 102;

int n, row_sum, col_sum;
int row[MAX], col[MAX];
int capa[MAX][MAX], flow[MAX][MAX], pre[MAX];
vector<int> graph[MAX];

bool check(int m)
{
	memset(flow, 0, sizeof(flow));
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			capa[i][j+50] = m;

	int total = 0;
	while (1) {
		queue<int> que;
		fill(pre, pre+MAX, -1);
		que.push(src);
		while (!que.empty()) {
			int cur = que.front();
			que.pop();
			if (cur == sink)
				break;
			for (int next=0; next<MAX; ++next) {
				if (pre[next] == -1 && capa[cur][next] > flow[cur][next]) {
					que.push(next);
					pre[next] = cur;
				}
			}
		}
		if (pre[sink] == -1)
			break;

		int min_val = INT_MAX;
		for (int i=sink; i!=src; i=pre[i])
			min_val = min(min_val, capa[pre[i]][i] - flow[pre[i]][i]);

		for (int i=sink; i!=src; i=pre[i]) {
			flow[pre[i]][i] += min_val;
			flow[i][pre[i]] -= min_val;
		}
		total += min_val;
	}

	if (row_sum == col_sum && row_sum == total)
		return true;
	return false;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) {
		scanf("%d", &row[i]);
		row_sum += row[i];
	}
	for (int i=1; i<=n; ++i) {
		scanf("%d", &col[i]);
		col_sum += col[i];
	}
	for (int i=1; i<=n; ++i) {
		graph[src].push_back(i);
		graph[i+50].push_back(sink);
		capa[src][i] = row[i];
		capa[i+50][sink] = col[i];
	}

	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j) {
			graph[i].push_back(j+50);
			graph[j+50].push_back(i);
		}
	}

	int l = 0, r = INF, ans = 0;
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid)) {
			r = mid-1;
			ans = mid;
		} else {
			l = mid+1;
		}
	}
	printf("%d\n", ans);

	check(ans);
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=n; ++j)
			printf("%d ", flow[i][j+50]);
		printf("\n");
	}

	return 0;
}
