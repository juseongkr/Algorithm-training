#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

int n, x;
int num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];
	cin >> x;

	sort(num, num+n);

	int ans = 0;
	for (int i=0; i<n; ++i) {
		int l = 0, r = n-1;
		while (l <= r) {
			int mid = (l+r)/2;
			if (num[mid] + num[i] == x) {
				ans++;
				break;
			} else if (num[mid] + num[i] < x) {
				l = mid+1;
			} else {
				r = mid-1;
			}
		}
	}

	cout << ans / 2 << '\n';

	return 0;
}
