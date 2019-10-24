#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 50001

int dol[MAX];

int d, n, m;

bool check(int k)
{
	int prev = 0, cnt = 0;
	for (int i=0; i<n; ++i) {
		if (dol[i] - prev < k)
			cnt++;
		else
			prev = dol[i];
	}

	if (d - prev < k)
		cnt++;
	return cnt > m;
}

int main()
{
	cin >> d >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> dol[i];

	sort(dol, dol+n);

	int ans = 0;
	int l = 0, r = d+1;
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid))
			r = mid-1;
		else
			l = mid+1;
	}
	cout << r << '\n';

	return 0;
}
