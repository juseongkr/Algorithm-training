#include <iostream>
#include <vector>
using namespace std;
#define MAX 1251

int n, m, cnt;
char map[51][51];
int col[51][51], row[51][51];
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

int matching()
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
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	int num = 0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (map[i][j] == '*') {
				if (j-1 < 0 || map[i][j-1] == '.')
					row[i][j] = ++num;
				else if (map[i][j-1] == '*')
					row[i][j] = row[i][j-1];
			}
		}
	}

	num = 0;
	for (int j=0; j<m; ++j) {
		for (int i=0; i<n; ++i) {
			if (map[i][j] == '*') {
				if (i-1 < 0 || map[i-1][j] == '.')
					col[i][j] = ++num;
				else if (map[i-1][j] == '*')
					col[i][j] = col[i-1][j];
			}
		}
	}

	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (col[i][j] != 0 & row[i][j] != 0)
				graph[col[i][j]].push_back(row[i][j]);

	cout << matching() << '\n';

	return 0;
}
