#include <iostream>
using namespace std;
#define MAX 100001

int n, m, sum;
int num[MAX];

bool check(int k)
{
	int sum = 0, cnt = 1;
	for (int i=0; i<n; ++i) {
		if (num[i] > k)
			return false;

		if (sum + num[i] <= k) {
			sum += num[i];
		} else {
			sum = num[i];
			cnt++;
		}
	}

	if (cnt <= m)
		return true;
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> num[i];
		sum += num[i];
	}

	int l = 0, r = sum;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans << '\n';

	return 0;
}
