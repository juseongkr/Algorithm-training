#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	vector<pair<int, int>> vec;
	int n, a, b;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a >> b;
		vec.push_back({b, a});
	}

	sort(vec.rbegin(), vec.rend());

	int start = vec[0].first;
	for (int i=0; i<n-1; ++i) {
		if (start - vec[i].second > vec[i+1].first)
			start = vec[i+1].first;
		else
			start -= vec[i].second;
	}

	int ans = start - vec[n-1].second;
	if (ans > 0)
		cout << ans << '\n';
	else
		cout << "0\n";

	return 0;
}
