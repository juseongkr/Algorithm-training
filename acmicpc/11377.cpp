#include <iostream>
#include <vector>
using namespace std;
#define MAX 2002

vector<int> graph[MAX];
int A[MAX], B[MAX], visit[MAX];
int n, m, k, t, p, cnt, cnt2;

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
	cin >> n >> m >> p;
	for (int i=0; i<n; ++i) {
		cin >> k;
		for (int j=0; j<k; ++j) {
			cin >> t;
			graph[i].push_back(t);
			graph[1000+i].push_back(t);
		}
	}

	fill(A, A+MAX, -1);
	fill(B, B+MAX, -1);
	for (int i=0; i<n; ++i) {
		fill(visit, visit+MAX, 0);
		if (dfs(i))
			cnt++;
	}
	
	for (int i=1000; i<1000+n; ++i) {
		fill(visit, visit+MAX, 0);
		if (dfs(i))
			cnt2++;
		if (cnt2 == p)
			break;
	}

	cout << cnt + cnt2 << '\n';

	return 0;
}
