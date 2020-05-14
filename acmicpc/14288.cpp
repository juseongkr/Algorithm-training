#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

int n, m, a, b, c, label;
int up[MAX*4], down[MAX*4], l[MAX], r[MAX];
vector<int> graph[MAX];

void update_up(int i, int diff)
{
	while (i <= n) {
		up[i] += diff;
		i += (i & -i);
	}
}

int sum_up(int i)
{
	int ret = 0;
	while (i) {
		ret += up[i];
		i -= (i & -i);
	}
	return ret;
}

void update_down(int i, int diff)
{
	while (i <= n) {
		down[i] += diff;
		i += (i & -i);
	}
}

int sum_down(int i)
{
	int ret = 0;
	while (i) {
		ret += down[i];
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

	bool op = 0;
	while (m--) {
		cin >> c;
		if (c == 1) {
			cin >> a >> b;
			if (op) {
				update_up(l[a], b);
			} else {
				update_down(l[a], b);
				update_down(r[a]+1, -b);
			}
		} else if (c == 2) {
			cin >> a;
			int x = sum_down(l[a]);
			int y = sum_up(r[a]) - sum_up(l[a]-1);
			cout << x + y << '\n';
		} else {
			op = !op;
		}
	}

	return 0;
}
