#include <iostream>
#include <vector>
using namespace std;
#define MAX 500001

int n, x, y;
int depth[MAX];
bool visit[MAX], leaf[MAX];
vector<int> graph[MAX];

void dfs(int cur, int cnt)
{
	visit[cur] = 1;
	depth[cur] = cnt;
	bool flag = false;

	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];

		if (!visit[next]) {
			flag = true;
			dfs(next, cnt+1);
		}
	}

	leaf[cur] = flag ? 0 : 1;
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

	int ans = 0;
	for (int i=1; i<=n; ++i)
		if (leaf[i])
			ans += depth[i];

	if (ans % 2)
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}
