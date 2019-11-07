#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int MOD = (1 << 20);

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	set<int> ans;
	vector<int> vec(100000, 0);
	int n, m, op, k, x;

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> op >> k;
		k--;
		if (op == 1) {
			cin >> x;
			x--;
			vec[k] |= (1 << x);
		} else if (op == 2) {
			cin >> x;
			x--;
			vec[k] &= ~(1 << x);
			vec[k] %= MOD;
		} else if (op == 3) {
			vec[k] = (vec[k] << 1) % MOD;
		} else {
			vec[k] >>= 1;
		}
	}
	for (int i=0; i<n; ++i)
		ans.insert(vec[i]);

	cout << ans.size() << '\n';

	return 0;
}
