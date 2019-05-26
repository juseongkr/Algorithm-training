#include <iostream>
#include <vector>
using namespace std;
#define MAX 1001

vector<int> graph[MAX];
int visit[MAX], A[MAX], B[MAX];
int t, n, m, a, b, ans;

bool dfs(int a)
{
	visit[a] = 1;
	for (int i=0; i<graph[a].size(); ++i) {
		int b = graph[a][i];
		if (B[b] == -1 || (!visit[B[b]] && dfs(B[b]))) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i=1; i<=m; ++i) {
			cin >> a >> b;
			for (int j=a; j<=b; ++j)
				graph[i].push_back(j);
		}

		fill(A, A+MAX, -1);
		fill(B, B+MAX, -1);
		for (int i=1; i<=m; ++i) {
			fill(visit, visit+MAX, 0);
			if (dfs(i))
				ans++;
		}
		cout << ans << '\n';

		ans = 0;
		for (int i=0; i<MAX; ++i)
			graph[i].clear();
	}

	return 0;
}
