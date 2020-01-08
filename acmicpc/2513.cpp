#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, s, x, y, ans;
vector<pair<int, int>> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> k >> s;
	vec.push_back({s, 0});
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		vec.push_back({x, y});
	}

	sort(vec.begin(), vec.end());

	int pivot = -1;
	for (int i=0; i<vec.size(); ++i) {
		if (vec[i].second == 0) {
			pivot = i;
			break;
		}
	}

	int i = 0;
	while (i < pivot) {
		int j, cur = 0;
		for (j=i; j<pivot; ++j) {
			cur += vec[j].second;
			if (cur > k) {
				vec[j].second = (cur-k);
				break;
			}
		}
		ans += (s - vec[i].first) * 2;
		i = j;
	}

	i = vec.size()-1;
	while (i > pivot) {
		int j, cur = 0;
		for (j=i; j>pivot; --j) {
			cur += vec[j].second;
			if (cur > k) {
				vec[j].second = (cur-k);
				break;
			}
		}
		ans += (vec[i].first - s) * 2;
		i = j;
	}

	cout << ans << '\n';

	return 0;
}
