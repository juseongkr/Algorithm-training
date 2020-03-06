#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 75001

int t, n, x, y;
int tree[MAX*4];
vector<pair<int, int>> vec;
vector<int> pos;

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

	cin >> t;
	while (t--) {
		cin >> n;
		fill(tree, tree+MAX*4, 0);
		vec.clear();
		pos.clear();
		for (int i=0; i<n; ++i) {
			cin >> x >> y;
			vec.push_back({-x, y});
			pos.push_back(y);
		}

		sort(vec.begin(), vec.end());
		sort(pos.begin(), pos.end());

		long long ans = 0;
		for (int i=0; i<n; ++i) {
			auto [X, Y] = vec[i];
			auto it = lower_bound(pos.begin(), pos.end(), Y) - pos.begin() + 1;

			ans += sum(it);
			update(it, 1);
		}
		cout << ans << '\n';
	}

	return 0;
}
