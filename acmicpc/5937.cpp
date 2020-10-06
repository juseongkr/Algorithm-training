#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100001

int n, x, y, cnt;
int in[MAX], cost[MAX];
vector<int> graph[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n-1; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		in[y]++;
	}

	queue<int> que;

	for (int i=1; i<=n; ++i) {
		if (!in[i]) {
			cnt++;
			que.push(i);
			cost[i] = 1;
			in[i] = -1;
		}
	}

	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		if (cost[cur] == cnt && graph[cur].size() > 1)
			continue;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];
			cost[next] += cost[cur];
			if (--in[next] == 0)
				que.push(next);
		}
	}

	for (int i=1; i<=n; ++i)
		if (cost[i] == cnt && in[i] != -1)
			cout << i << '\n';

	return 0;
}
