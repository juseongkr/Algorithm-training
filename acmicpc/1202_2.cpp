#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main()
{
	vector<pair<int, int>> vec;
	multiset<int> st;
	int n, k, a, b;

	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> a >> b;
		vec.push_back({b, a});
	}

	sort(vec.rbegin(), vec.rend());

	for (int i=0; i<k; ++i) {
		cin >> a;
		st.insert(a);
	}

	long long ans = 0;
	for (int i=0; i<n; ++i) {
		auto it = st.lower_bound(vec[i].second);
		if (it != st.end()) {
			ans += vec[i].first;
			st.erase(it);
		}
	}
	cout << ans << '\n';

	return 0;
}
