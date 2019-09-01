#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 101

int t, n, m, t1, t2, a, q;
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
		int last = 0;
		for (int i=0; i<m; ++i) {
			cin >> t1 >> t2 >> a;
			last = max(last, t2);
			for (int j=0; j<a; ++j) {
				cin >> q;
				for (int k=t1; k<t2; ++k)
					graph[q-1].push_back(k);
			}
		}

		for (int i=0; i<n; ++i)
			sort(graph[i].begin(), graph[i].end());

		if (match() != n) {
			cout << "-1\n";
		} else {
			for (int i=last; i>=0; i--) {
				if (B[i] != -1) {
					cout << i+1 << '\n';
					break;
				}
			}
		}
		for (int i=0; i<MAX; ++i)
			graph[i].clear();
	}

	return 0;
}
