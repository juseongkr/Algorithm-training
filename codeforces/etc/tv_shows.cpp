#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long mod = 10e9 + 7;

int main()
{
	long long n, x, y, s, e, result = 0;
	vector<pair<long long, long long>> show, vec;
	
	scanf("%lld %lld %lld", &n, &x, &y);

	for (int i=0; i<n; ++i) {
		scanf("%lld %lld", &s, &e);
		show.push_back({s, e});
	}

	sort(show.begin(), show.end());

	for (int i=0; i<n; ++i) {
		vec.clear();

		for (int j=i+1; j<=n; ++j) {
			if (vec.empty()) {
				vec.push_back(show[i]);
				show[i] = {0, 0};
			}
			if (show[j].first - vec.back().second == 1) {
				vec.push_back(show[j]);
				show[j] = {0, 0};
			}
		}
		
		if (vec.back().second != 0 && vec.back().first != 0) {
			if (!(vec.size() == 1 && vec.back().first == vec.back().second)) {
				result += ((vec.back().second - vec.front().first) * y) + x;
				cout << "> " << ((vec.back().second - vec.front().first) * y) + x << '\n';
			} else {
				result += x;
				cout << "> " << x << '\n';

			}
		}

		for (auto k : vec)
			cout << "vec: " << k.first << ":" << k.second << " ";
		cout << endl;
	}

	for (int i=0; i<n; ++i)
		cout << show[i].first << ":" << show[i].second << " ";
	cout << endl;
		
	cout << result % mod << '\n';

	return 0;
}
