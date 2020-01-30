#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n, num;
long long ans;
map<int, int> m;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> num;
	m[num] = 1;
	cout << "0\n";
	for (int i=0; i<n-1; ++i) {
		cin >> num;
		int t = 0;
		auto it = m.upper_bound(num);
		if (it != m.end())
			t = it->second;

		if (it != m.begin()) {
			it--;
			t = max(t, it->second);
		}

		ans += t;
		m[num] = t+1;
		cout << ans << '\n';
	}

	return 0;
}
