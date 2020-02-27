#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

class Stat {
public:
	int a, b, c;
	bool operator<(const Stat &s) const
	{
		return s.c > c;
	}
};

int n, k, a, b, c;
vector<Stat> vec;

int main()
{
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> a >> b >> c;
		vec.push_back({a, b, c});
	}

	sort(vec.begin(), vec.end());

	int ans = 1e9+7;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			int cnt = 0;
			for (int p=0; p<n; ++p) {
				if (vec[p].a <= vec[i].a && vec[p].b <= vec[j].b)
					cnt++;
				if (cnt == k) {
					int ret = vec[i].a + vec[j].b + vec[p].c;
					ans = min(ans, ret);
					break;
				}
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
