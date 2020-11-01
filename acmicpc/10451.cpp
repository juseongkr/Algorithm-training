#include <iostream>
#include <vector>
using namespace std;
#define MAX 1001

int T, n, x;
int graph[MAX];
bool visit[MAX];

void dfs(int cur)
{
	visit[cur] = true;
	
	int next = graph[cur];
	if (!visit[next])
		dfs(next);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		fill(visit, visit+MAX, 0);
		for (int i=1; i<=n; ++i)
			cin >> graph[i];

		int ans = 0;
		for (int i=1; i<=n; ++i) {
			if (!visit[i]) {
				dfs(i);
				ans++;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
