#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 101

int ans[MAX];
int t, p, n, k;
vector<pair<int, int>> vec;

int main()
{
	cin >> t;
	while (t--) {
		cin >> p >> n;
		vec.clear();
		fill(ans, ans+MAX, 0);
		for (int i=0; i<n; ++i) {
			cin >> k;
			vec.push_back({k, -i});
		}

		sort(vec.begin(), vec.end());

		for (int i=0; i<n; ++i) {
			auto [val, idx] = vec[i];
			ans[-idx] = min(val, p / (n-i));
			p -= ans[-idx];
		}

		if (p == 0) {
			for (int i=0; i<n; ++i)
				cout << ans[i] << " ";
			cout << '\n';
		} else {
			cout << "IMPOSSIBLE\n";
		}
	}

	return 0;
}
