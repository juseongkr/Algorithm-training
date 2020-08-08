#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001
const int INF = 1e9+7;

int n, m;
int a[MAX], b[MAX];

bool check(int mid)
{
	for (int i=0, j=0; i<n; ++i, ++j) {
		while (j < m && abs(a[i] - b[j]) > mid)
			j++;

		if (j == m)
			return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	
	for (int i=0; i<m; ++i)
		cin >> b[i];

	if (n > m) {
		for (int i=0; i<n; ++i)
			swap(a[i], b[i]);
		swap(n, m);
	}

	sort(a, a+n);
	sort(b, b+m);

	int l = 0, r = INF;
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
