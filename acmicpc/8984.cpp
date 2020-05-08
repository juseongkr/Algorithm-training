#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 100001

int n, l, u, v;
vector<int> t, d;
vector<tuple<int, int, int>> st;
long long dpT[MAX], dpD[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> l;
	for (int i=0; i<n; ++i) {
		cin >> u >> v;
		st.push_back({u, v, abs(u-v)+l});
		t.push_back(u);
		d.push_back(v);
	}

	sort(st.begin(), st.end());
	sort(t.begin(), t.end());
	sort(d.begin(), d.end());

	t.erase(unique(t.begin(), t.end()), t.end());
	d.erase(unique(d.begin(), d.end()), d.end());

	long long ans = 0;
	for (int i=0; i<n; ++i) {
		auto x = lower_bound(t.begin(), t.end(), get<0>(st[i])) - t.begin();
		auto y = lower_bound(d.begin(), d.end(), get<1>(st[i])) - d.begin();

		long long retT = max(dpT[x], dpD[y] + get<2>(st[i]));
		long long retD = max(dpD[y], dpT[x] + get<2>(st[i]));

		dpT[x] = retT;
		dpD[y] = retD;

		ans = max({ans, dpT[x], dpD[y]});
	}
	cout << ans << '\n';

	return 0;
}
