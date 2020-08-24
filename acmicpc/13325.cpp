#include <iostream>
using namespace std;
#define MAX (1 << 21)

int n, ans;
int tree[MAX];

int dfs(int cur)
{
	if (2 * cur + 1 > n) {
		ans += tree[cur];
		return tree[cur];
	}

	int left = dfs(2 * cur);
	int right = dfs(2 * cur + 1);
	ans += tree[cur] + abs(left - right);
	return tree[cur] + max(left, right);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	n = (1 << (n+1));
	for (int i=2; i<n; ++i)
		cin >> tree[i];

	dfs(1);
	cout << ans << '\n';

	return 0;
}
