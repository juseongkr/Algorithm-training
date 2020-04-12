#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, n, k;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		vector<int> vec, ans;
		for (int i=0; i<n; ++i) {
			cin >> k;
			vec.push_back(k);
		}

		sort(vec.begin(), vec.end());
		for (int i=0; i<n/2; ++i) {
			ans.push_back(vec[i]);
			ans.push_back(vec[n-1-i]);
		}
		if (n % 2)
			ans.push_back(vec[n/2]);

		for (int i=ans.size()-1; i>=0; i--)
			cout << ans[i] << " ";
		cout << '\n';
	}

	return 0;
}
