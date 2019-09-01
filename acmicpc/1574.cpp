#include <iostream>
#include <vector>
using namespace std;
#define MAX 301

int n, m, x, y, k;
vector<int> graph[MAX];
int A[MAX], B[MAX], visit[MAX];
bool map[MAX][MAX];

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

	cin >> n >> m >> k;
	for (int i=0; i<k; ++i) {
		cin >> x >> y;
		map[x-1][y-1] = true;
	}

	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (!map[i][j])
				graph[i].push_back(j);

	cout << match() << '\n';

	return 0;
}
