#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 50001

int n, k;
int num[MAX];

bool check(int m)
{
	int cur = 0;
	for (int i=0; i<k; ++i)
		if (cur < n)
			cur = upper_bound(num, num+n, num[cur] + 2*m) - num;

	return cur == n;
}

int main()
{
	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	sort(num, num+n);

	int l = 0, r = num[n-1];
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
