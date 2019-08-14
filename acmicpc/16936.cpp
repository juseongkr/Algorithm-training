#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<pair<int, long long>> vec;
	long long t;
	int n;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		long long num = t;
		int cnt = 0;
		while (t % 3 == 0) {
			t /= 3;
			cnt++;
		}
		vec.push_back({-cnt, num});
	}
	sort(vec.begin(), vec.end());

	for (int i=0; i<vec.size(); ++i)
		cout << vec[i].second << " ";

	return 0;
}
