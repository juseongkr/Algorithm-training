#include <iostream>
#include <vector>
using namespace std;
#define MAX 5001

int a, b, n, m, x, y;
bool visit[MAX];
int fcnt[MAX], bcnt[MAX];
vector<int> go[MAX], back[MAX];

int dfs1(int cur)
{
	if (visit[cur])
		return 0;

	int ret = 1;
	visit[cur] = 1;

	for (int i=0; i<go[cur].size(); ++i) {
		int next = go[cur][i];
		ret += dfs1(next);
	}

	return ret;
}

int dfs2(int cur)
{
	if (visit[cur])
		return 0;

	int ret = 1;
	visit[cur] = 1;

	for (int i=0; i<back[cur].size(); ++i) {
		int next = back[cur][i];
		ret += dfs2(next);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> a >> b >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		go[x].push_back(y);
		back[y].push_back(x);
	}

	int A = 0, B = 0, C = 0;
	for (int i=0; i<n; ++i) {
		fill(visit, visit+n, 0);
		int l = dfs1(i);
		fill(visit, visit+n, 0);
		int r = dfs2(i);

		if (a + l > n)
			A++;
		if (b + l > n)
			B++;
		if (r > b)
			C++;
	}

	cout << A << '\n' << B << '\n' << C << '\n';

	return 0;
}
