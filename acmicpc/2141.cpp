#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, x, y;
long long total;
vector<pair<int, int>> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		total += y;
		vec.push_back({x, y});
	}

	sort(vec.begin(), vec.end());

	long long sum = 0;
	for (int i=0; i<n; ++i) {
		auto [idx, val] = vec[i];
		sum += val;
		if ((total+1)/2 <= sum) {
			cout << idx;
			return 0;
		}
	}

	return 0;
}
