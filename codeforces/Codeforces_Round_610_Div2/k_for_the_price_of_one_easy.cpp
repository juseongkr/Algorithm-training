#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 200002

int t, n, p, k;
int num[MAX];

bool check(int k)
{
	int s = p;
	for (int i=k-1; i>=0; i-=2) {
		s -= num[i];
		if (s < 0)
			return false;
	}
	return true;
}

int main()
{
	cin >> t;
	while (t--) {
		cin >> n >> p >> k;
		for (int i=0; i<n; ++i)
			cin >> num[i];

		sort(num, num+n);

		int l = 0, r = n;
		while (l <= r) {
			int mid = (l+r)/2;
			if (check(mid))
				l = mid+1;
			else
				r = mid-1;
		}
		cout << r << '\n';
	}

	return 0;
}
