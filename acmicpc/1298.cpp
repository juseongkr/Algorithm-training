#include <iostream>
#include <vector>
using namespace std;
#define MAX 5001

vector<int> graph[MAX];
int A[MAX], B[MAX], visit[MAX];
int n, m, a, b, cnt;

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
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b;
		graph[a].push_back(b);
	}

	fill(A, A+MAX, -1);
	fill(B, B+MAX, -1);
	for (int i=1; i<=n; ++i) {
		fill(visit, visit+MAX, 0);
		if (dfs(i))
			cnt++;
	}

	cout << cnt << '\n';

	return 0;
}
