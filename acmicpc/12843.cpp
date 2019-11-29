#include <iostream>
#include <vector>
using namespace std;
#define MAX 2001

char c;
int n, m, t, x, y;
vector<int> vec, graph[MAX];
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
	for (int i=0; i<vec.size(); ++i) {
		fill(visit, visit+MAX, 0);
		if (dfs(vec[i]))
			ret++;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> t >> c;
		if (c == 'c')
			vec.push_back(t);
	}

	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	cout << n - match() << '\n';

	return 0;
}
