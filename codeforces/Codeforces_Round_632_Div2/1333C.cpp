#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 200001
#define ll long long

int n, id[MAX];
ll k, sum[MAX];
vector<ll> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	cin >> n;
	vec.push_back(0);
	fill(id, id+vec.size(), -1);
	for (int i=1; i<=n; ++i) {
		cin >> k;
		sum[i] = sum[i-1] + k;
		vec.push_back(sum[i]);
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	ll ans = 0;
	auto it = lower_bound(vec.begin(), vec.end(), sum[0]) - vec.begin();
	id[it] = 0;
	int idx = -1;
	for (int i=1; i<=n; ++i) {
		it = lower_bound(vec.begin(), vec.end(), sum[i]) - vec.begin();

		idx = max(idx, id[it]);
		id[it] = i;
		ans += (i - (idx+1));
	}

	cout << ans << '\n';

	return 0;
}
