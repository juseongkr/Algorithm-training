#include <iostream>
#include <vector>
using namespace std;
#define MAX 201

vector<int> graph[MAX];
int A[MAX], B[MAX], visit[MAX];
int n, m, s, k, ans;

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
	for (int i=0; i<n; ++i) {
		cin >> s;
		for (int j=0; j<s; ++j) {
			cin >> k;
			graph[i].push_back(k-1);
		}
	}

	fill(A, A+n, -1);
	fill(B, B+m, -1);
	for (int i=0; i<n; ++i) {
		if (A[i] == -1) {
			fill(visit, visit+n, 0);
			if (dfs(i))
				ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}
