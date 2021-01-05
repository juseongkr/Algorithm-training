#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001
const long long INF = 1e18+7;

int n, num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	sort(num, num+n);

	long long mi = -INF;
	int l = 0, r = n-1;
	while (l < r) {
		long long sum = num[l] + num[r];
		if (abs(mi) > abs(sum))
			mi = sum;

		if (sum > 0)
			r--;
		else
			l++;
	}

	cout << mi << '\n';

	return 0;
}
