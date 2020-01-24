#include <iostream>
#include <vector>
using namespace std;
#define MAX 301

int n, m, p, q, x, y;
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
	cin >> n >> m >> p >> q;
	for (int i=0; i<p; ++i) {
		cin >> x >> y;
		graph[x-1].push_back(y-1);
	}

	int l = match();

	for (int i=0; i<MAX; ++i)
		graph[i].clear();

	for (int i=0; i<q; ++i) {
		cin >> x >> y;
		graph[x-1].push_back(y-1);
	}

	int r = match();

	if (l < r)
		cout << "네 다음 힐딱이\n";
	else
		cout << "그만 알아보자\n";

	return 0;
}
