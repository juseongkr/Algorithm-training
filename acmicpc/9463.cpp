#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

int t, n, k;
vector<int> vec;
int tree[MAX*4], m[MAX];

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
		fill(tree, tree+MAX*4, 0);
		fill(m, m+MAX, 0);
		vec.clear();
		cin >> n;
		for (int i=0; i<n; ++i) {
			cin >> k;
			m[k] = i+1;
		}

		for (int i=0; i<n; ++i) {
			cin >> k;
			vec.push_back(m[k]);
		}

		long long ans = 0;
		for (int i=0; i<vec.size(); ++i) {
			ans += sum(n) - sum(vec[i]);
			update(vec[i], 1);
		}
		cout << ans << '\n';
	}

	return 0;
}
