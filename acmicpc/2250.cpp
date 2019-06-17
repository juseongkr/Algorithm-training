#include <iostream>
#include <climits>
using namespace std;
#define MAX 10001

int level, ans, idx = 1;
int node[MAX], low[MAX], high[MAX];
pair<int, int> tree[MAX];

void dfs(int node, int cnt)
{
	if (tree[node].first > 0)
		dfs(tree[node].first, cnt+1);

	low[cnt] = min(low[cnt], idx);
	high[cnt] = idx++;

	if (tree[node].second > 0)
		dfs(tree[node].second, cnt+1);
}

int main()
{
	int n, p, l, r;

	cin >> n;
	fill(low, low+MAX, INT_MAX);
	for (int i=0; i<n; ++i) {
		cin >> p >> l >> r;
		node[p]++;
		if (l != -1)
			node[l]++;
		tree[p].first = l;
		if (r != -1)
			node[r]++;
		tree[p].second = r;
	}

	for (int i=1; i<=n; ++i) {
		if (node[i] == 1) {
			dfs(i, 1);
			break;
		}
	}

	for (int i=1; i<=n; ++i) {
		int sub = (high[i] - low[i]) + 1;
		if (ans < sub) {
			ans = sub;
			level = i;
		}
	}
	cout << level << " " << ans << '\n';

	return 0;
}
