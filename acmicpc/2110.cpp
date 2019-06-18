#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 200001

int num[MAX];
int n, c, ans;

bool check(int k)
{
	int cnt = 1;
	int prev = num[0];
	for (int i=1; i<n; ++i) {
		if (num[i] - prev >= k) {
			prev = num[i];
			cnt++;
		}
	}

	if (cnt >= c)
		return true;
	else
		return false;
}

int main()
{
	cin >> n >> c;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	sort(num, num+n);

	int l = 1, r = num[n-1] - num[0];
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid)) {
			ans = max(ans, mid);
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << '\n';

	return 0;
}
