#include <iostream>
#include <vector>
using namespace std;
#define MAX 201

int n, m;
vector<int> graph[MAX];
int A[MAX], B[MAX], visit[MAX];
double x[MAX], y[MAX];

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
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> x[i];

	for (int i=0; i<m; ++i)
		cin >> y[i];

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if ((x[i]/2 <= y[j] && y[j] <= x[i]*3/4) ||
			    (x[i] <= y[j] && y[j] <= x[i]*5/4))
				graph[i].push_back(j);
		}
	}

	cout << match() << '\n';

	return 0;
}
