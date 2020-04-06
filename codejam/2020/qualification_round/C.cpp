#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1001

int T, n, x, y;

int main()
{
	cin >> T;
	for (int t=1; t<=T; ++t) {
		cin >> n;
		vector<pair<int, pair<int, int>>> vec;
		char ans[MAX];
		for (int i=0; i<n; ++i) {
			cin >> x >> y;
			vec.push_back(make_pair(x, make_pair(y, i)));
		}

		sort(vec.begin(), vec.end());

		int l = 0, r = 0;
		bool flag = true;
		for (int i=0; i<n; ++i) {
			int x = vec[i].first;
			int y = vec[i].second.first;
			int idx = vec[i].second.second;
			if (l <= x) {
				l = y;
				ans[idx] = 'C';
			} else if (r <= x) {
				r = y;
				ans[idx] = 'J';
			} else {
				flag = false;
				break;
			}
		}

		if (flag) {
			cout << "Case #" << t << ": ";
			for (int i=0; i<n; ++i)
				cout << ans[i];
			cout << '\n';
		} else {
			cout << "Case #" << t << ": IMPOSSIBLE\n";
		}
	}

	return 0;
}
