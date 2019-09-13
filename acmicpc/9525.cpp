#include <iostream>
#include <vector>
using namespace std;
#define MAX 10001

int n, m, cnt;
vector<int> graph[MAX];
int A[MAX], B[MAX], visit[MAX];
char map[101][101];
int row[101][101], col[101][101];

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
	cin >> n;
	m = n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	int num = 0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (map[i][j] != 'X') {
				if (j-1 < 0 || map[i][j-1] == 'X')
					row[i][j] = ++num;
				else if (map[i][j-1] != 'X')
					row[i][j] = row[i][j-1];
			}
		}
	}

	num = 0;
	for (int j=0; j<m; ++j) {
		for (int i=0; i<n; ++i) {
			if (map[i][j] != 'X') {
				if (i-1 < 0 || map[i-1][j] == 'X')
					col[i][j] = ++num;
				else if (map[i-1][j] != 'X')
					col[i][j] = col[i-1][j];
			}
		}
	}

	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (map[i][j] == '.')
				graph[row[i][j]].push_back(col[i][j]);

	cout << match() << '\n';

	return 0;
}
