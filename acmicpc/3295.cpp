#include <iostream>
#include <vector>
using namespace std;
#define MAX 1001

int n, m, t, u, v;
vector<int> graph[MAX];
int A[MAX], B[MAX], visit[MAX];

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

int match()
{
	int ret = 0;
	fill(A, A+MAX, -1);
	fill(B, B+MAX, -1);
	for (int i=0; i<MAX; ++i) {
		fill(visit, visit+MAX, 0);
		if (dfs(i))
			ret++;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i=0; i<m; ++i) {
			cin >> u >> v;
			graph[u].push_back(v);
		}
		cout << match() << '\n';

		for (int i=0; i<MAX; ++i)
			graph[i].clear();
	}

	return 0;
}
