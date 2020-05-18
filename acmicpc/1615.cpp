#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 2001

int n, m, x, y;
int tree[MAX*4];
vector<pair<int, int>> vec;

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

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		vec.push_back({x, y});
	}

	sort(vec.begin(), vec.end());

	long long ans = 0;
	for (int i=0; i<m; ++i) {
		ans += sum(n) - sum(vec[i].second);
		update(vec[i].second, 1);
	}
	cout << ans << '\n';

	return 0;
}
