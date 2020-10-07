#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 400001
typedef pair<int, int> pi;

int n, m, x, ans;
int in[MAX], cost[MAX];
vector<int> graph[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> cost[i] >> m;
		for (int j=0; j<m; ++j) {
			cin >> x;
			in[x]++;
			graph[i].push_back(x);
		}
	}

	priority_queue<pi, vector<pi>, greater<pi>> que;

	for (int i=1; i<=n; ++i)
		if (!in[i])
			que.push({cost[i], i});

	int cnt = n;
	while (!que.empty()) {
		auto [cos, cur] = que.top();
		que.pop();
		cnt--;

		ans = max(ans, cos + cnt);
		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];
			if (--in[next] == 0)
				que.push({cost[next], next});
		}
	}

	cout << ans << '\n';

	return 0;
}
