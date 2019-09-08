#include <iostream>
#include <vector>
using namespace std;
#define MAX 1001

int n, m, x, y, cnt, num;
vector<int> graph[MAX];
int A[MAX], B[MAX], visit[MAX];
int row[101][101], col[101][101];
bool map[101][101];

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
		fill(visit, visit+MAX, false);
		if (dfs(i))
			ret++;
	}
	return ret;
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		map[x][y] = true;
	}

	for (int i=1; i<=n; ++i) {
		int x = i;
		int y = 1;

		while (x <= n && y <= n) {
			if (!map[x][y]) {
				if (x-1 <= 0 || y-1 <= 0 || map[x-1][y-1] == true)
					row[x][y] = ++num;
				else if (!map[x-1][y-1])
					row[x][y] = row[x-1][y-1];
			}
			x++;
			y++;
		}

		x = i;
		y = 1;
		while (x >= 1 && y <= n) {
			if (!map[x][y]) {
				if (x+1 > n || y-1 <= 0 || map[x+1][y-1] == true)
					col[x][y] = ++num;
				else if (!map[x+1][y-1])
					col[x][y] = col[x+1][y-1];
			}
			x--;
			y++;
		}

		x = 1;
		y = i;
		while (x >= 1 && y <= n) {
			if (!map[x][y]) {
				if (x-1 <= 0 || y-1 <= 0 || map[x-1][y-1] == true)
					row[x][y] = ++num;
				else if (!map[x-1][y-1])
					row[x][y] = row[x-1][y-1];
			}
			x++;
			y++;
		}

		x = n;
		y = i;
		while (x >= 1 && y <= n) {
			if (!map[x][y]) {
				if (x+1 > n || y-1 <= 0 || map[x+1][y-1] == true)
					col[x][y] = ++num;
				else if (!map[x+1][y-1])
					col[x][y] = col[x+1][y-1];
			}
			x--;
			y++;
		}
	}

	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			if (map[i][j] == false)
				graph[row[i][j]].push_back(col[i][j]);

	cout << match() << '\n';

	return 0;
}
