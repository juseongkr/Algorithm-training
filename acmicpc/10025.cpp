#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 100001

int n, k, x, y;
int sum[MAX];
vector<pair<int, int>> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		vec.push_back({y, x});
	}

	sort(vec.begin(), vec.end());

	for (int i=0; i<n; ++i)
		sum[i+1] = sum[i] + vec[i].second;

	int ans = 0;
	for (int i=0; i<n; ++i) {
		int l = upper_bound(vec.begin(), vec.end(), pair<int, int>(2*k + vec[i].first, 1e9+7)) - vec.begin();
		ans = max(ans, sum[l] - sum[i]);
	}
	cout << ans << '\n';

	return 0;
}
