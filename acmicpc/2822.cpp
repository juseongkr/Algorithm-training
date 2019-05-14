#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<pair<int, int>> num;
	vector<int> ans;
	int t, sum = 0;

	for (int i=1; i<=8; ++i) {
		cin >> t;
		num.push_back({t, i});
	}

	sort(num.rbegin(), num.rend());

	for (int i=0; i<5; ++i) {
		sum += num[i].first;
		ans.push_back(num[i].second);
	}

	sort(ans.begin(), ans.end());

	cout << sum << '\n';
	for (int i=0; i<5; ++i)
		cout << ans[i] << " ";

	return 0;
}
