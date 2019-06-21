#include <iostream>
#include <algorithm>
#include <climits>
#include <tuple>
#include <vector>
using namespace std;

int main()
{
	vector<tuple<int, int, int>> vec;
	int n, x, y, ans = 0;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		vec.push_back({x, y, INT_MAX});
	}

	sort(vec.begin(), vec.end());

	for (int i=0; i<n; ++i) {
		bool flag = true;
		auto [pos, color, value] = vec[i];
		for (int j=i+1; j<n; ++j) {
			auto [next_pos, next_color, next_value] = vec[j];
			if (color == next_color) {
				ans += min(value, next_pos - pos);
				get<2>(vec[i]) = min(value, next_pos - pos);
				get<2>(vec[j]) = next_pos - pos;
				flag = false;
				break;
			}
		}
		if (flag)
			ans += value;
	}
	cout << ans << '\n';

	return 0;
}
