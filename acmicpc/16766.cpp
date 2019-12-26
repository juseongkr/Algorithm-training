#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

int n, m, c;
int cow[MAX];

bool check(int k)
{
	int prev = 0, ret = 1;
	for (int i=1; i<n; ++i) {
		if (i - prev >= c || cow[i] > cow[prev] + k) {
			ret++;
			prev = i;
		}
	}

	return ret <= m;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> c;
	for (int i=0; i<n; ++i)
		cin >> cow[i];

	sort(cow, cow+n);

	int l = 0, r = 1e9+7;
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid))
			r = mid-1;
		else
			l = mid+1;
	}
	cout << l << '\n';

	return 0;
}
