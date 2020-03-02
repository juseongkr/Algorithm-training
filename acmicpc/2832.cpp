#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 100001

int n, k;
long long ans;
int tree[MAX*4];
vector<int> vec;

void update(int i, int diff)
{
	while (i <= n) {
		tree[i] += diff;
		i += (i & -i);
	}
}

int sum(int i)
{
	int ret = 0;
	while (i) {
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> k;
		vec.push_back(k);
	}

	auto l = vec.begin();
	auto r = vec.begin();
	while (l != vec.end()) {
		r++;
		if (r == vec.end() || *(r-1) < *r) {
			if (r-l-1) {
				ans++;
				reverse(l, r);
			}
			l = r;
		}
	}

	for (int i=0; i<n; ++i) {
		ans += i - sum(vec[i]);
		update(vec[i], 1);
	}

	cout << ans << '\n';

	return 0;
}
