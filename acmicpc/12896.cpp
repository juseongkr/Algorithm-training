#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

int n, x, y, far, ans;
vector<int> graph[MAX];
bool visit[MAX];

void dfs(int cur, int cost)
{
	if (visit[cur])
		return;
	visit[cur] = 1;

	if (ans < cost) {
		ans = cost;
		far = cur;
	}

	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];

		dfs(next, cost + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n-1; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(1, 0);
	fill(visit, visit+MAX, 0);
	dfs(far, 0);

	if (ans % 2)
		cout << ans/2+1 << '\n';
	else
		cout << ans/2 << '\n';

	return 0;
}
