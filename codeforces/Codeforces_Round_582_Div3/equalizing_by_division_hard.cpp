#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
#define MAX 200001

int main()
{
	vector<int> vec[MAX];
	int n, k, t, ans = INT_MAX;

	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> t;
		int j = 0;
		while (t) {
			vec[t].push_back(j);
			t /= 2;
			j++;
		}
		vec[0].push_back(j);
	}

	for (int i=0; i<MAX; ++i) {
		if (vec[i].size() >= k) {
			sort(vec[i].begin(), vec[i].end());
			int cnt = 0;
			for (int j=0; j<k; ++j)
				cnt += vec[i][j];
			ans = min(ans, cnt);
		}
	}
	cout << ans << '\n';

	return 0;
}
