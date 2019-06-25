#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000001

int main()
{
	int num[MAX];
	int n, s;

	cin >> n >> s;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	sort(num, num+n);

	int ans = 0;
	for (int i=0; i<n; ++i) {
		int l = 0, r = n-1;
		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (num[i] + num[mid] <= s)
				l = mid;
			else
				r = mid - 1;
		}
		if (l > i)
			ans += (l - i);
	}
	cout << ans << '\n';

	return 0;
}
