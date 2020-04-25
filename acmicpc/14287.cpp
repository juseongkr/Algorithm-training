#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

int n, m, a, b, c, label;
int tree[MAX*4], l[MAX], r[MAX];
vector<int> graph[MAX];

void update(int i, int diff)
{
	while (i <= n) {
		tree[i] += diff;
		i += (i & -i);
	}
}

int sum(int i)
{
	int ret = 0;
	while (i) {
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}

void dfs(int cur)
{
	l[cur] = ++label;
	for (int i=0; i<graph[cur].size(); ++i) {
		int next = graph[cur][i];
		dfs(next);
	}
	r[cur] = label;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> a;
	for (int i=2; i<=n; ++i) {
		cin >> a;
		graph[a].push_back(i);
	}
	
	dfs(1);

	while (m--) {
		cin >> c;
		if (c == 1) {
			cin >> a >> b;
			update(l[a], b);
		} else {
			cin >> a;
			cout << sum(r[a]) - sum(l[a]-1) << '\n';
		}
	}

	return 0;
}
