#include <iostream>
#include <vector>
using namespace std;
#define MAX 6401

vector<int> graph[MAX];
int A[MAX], B[MAX], visit[MAX];
int t, n, m, cnt, sum;

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

int conv(int x, int y) { return x*m+y; }

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		sum = 0;
		cin >> n >> m;
		vector<string> map(n);
		for (int i=0; i<n; ++i)
			cin >> map[i];

		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				if (map[i][j] == '.')
					sum++;

		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				if (map[i][j] == 'x')
					continue;

				if (i > 0) {
					if (j > 0) {
						if (map[i-1][j-1] == '.') {
							int x = conv(i, j);
							int y = conv(i-1, j-1);
							if (j % 2 == 0) {
								graph[x].push_back(y);
							} else {
								graph[y].push_back(x);
							}
						}
					}

					if (j+1 < m) {
						if (map[i-1][j+1] == '.') {
							int x = conv(i, j);
							int y = conv(i-1, j+1);
							if (j % 2 == 0) {
								graph[x].push_back(y);
							} else {
								graph[y].push_back(x);
							}
						}
					}
				}

				if (j > 0) {
					if (map[i][j-1] == '.') {
						int x = conv(i, j);
						int y = conv(i, j-1);
						if (j % 2 == 0) {
							graph[x].push_back(y);
						} else {
							graph[y].push_back(x);
						}
					}
				}
			}
		}

		cnt = 0;
		fill(A, A+n*m, -1);
		fill(B, B+n*m, -1);
		for (int i=0; i<n*m; ++i) {
			fill(visit, visit+n*m, 0);
			if (dfs(i))
				cnt++;
		}
		cout << sum - cnt << '\n';

		for (int i=0; i<MAX; ++i)
			graph[i].clear();
	}

	return 0;
}
