#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 151

int main()
{
	vector<pair<int, int>> vec;
	int n, x, y;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		vec.push_back({y, x});
	}
	sort(vec.begin(), vec.end());

	int ans = 0;
	int p1 = 0, p2 = 0;
	for (int i=0; i<n; ++i) {
		int go = vec[i].second;
		if (go >= p1) {
			if (go < p2) {
				p1 = p2;
				p2 = vec[i].first;
				ans++;
			} else {
				p2 = vec[i].first;
				ans++;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
