#include <iostream>
using namespace std;
#define MAX 10001

int n, k, d;
int a[MAX], b[MAX], c[MAX];

bool check(int m)
{
	long long total = 0;
	for (int i=0; i<k; ++i) {
		int t = min(m, b[i]);
		if (t >= a[i])
			total += 1 + (t - a[i]) / c[i];
	}
	return total >= d;
}

int main()
{
	cin >> n >> k >> d;
	for (int i=0; i<k; ++i)
		cin >> a[i] >> b[i] >> c[i];

	int l = 0, r = n;
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
