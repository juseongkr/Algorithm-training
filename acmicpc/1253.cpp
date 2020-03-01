#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 2001

int n, ans;
int num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	sort(num, num+n);

	for (int i=0; i<n; ++i) {
		int l = 0, r = n-1;
		while (l < r) {
			if (num[l] + num[r] < num[i]) {
				l++;
			} else if (num[l] + num[r] > num[i]) {
				r--;
			} else {
				if (l != i && r != i) {
					ans++;
					break;
				}
				if (l == i)
					l++;
				else if (r == i)
					r--;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
