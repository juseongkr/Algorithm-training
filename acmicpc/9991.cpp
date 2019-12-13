#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	vector<pair<string, int>> vec;
	int n, t, k;
	string s;

	cin >> n >> t;
	for (int i=0; i<n; ++i) {
		cin >> s;
		vec.push_back({s, i});
	}

	sort(vec.begin(), vec.end());

	for (int i=0; i<t; ++i) {
		cin >> k >> s;
		int l = lower_bound(vec.begin(), vec.end(), make_pair(s, 0)) - vec.begin();
		int r = upper_bound(vec.begin(), vec.end(), make_pair(s + "~", 0)) - vec.begin();

		if (r - l < k)
			cout << "-1\n";
		else
			cout << vec[l+k-1].second + 1 << '\n';
	}

	return 0;
}
