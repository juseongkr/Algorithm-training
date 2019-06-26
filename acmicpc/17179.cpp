#include <iostream>
using namespace std;
#define MAX 1001

int n, m, l, q;
int num[MAX];

bool check(int k)
{
	int cnt = 0, prev = 0;
	for (int i=0; i<=m; ++i) {
		if (num[i] - prev >= k) {
			prev = num[i];
			cnt++;
		}
	}

	if (cnt > q)
		return true;
	return false;
}

int main()
{
	cin >> n >> m >> l;
	for (int i=0; i<m; ++i)
		cin >> num[i];
	num[m] = l;

	for (int i=0; i<n; ++i) {
		cin >> q;
		int ans = 0;
		int left = 0, right = l;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (check(mid)) {
				left = mid + 1;
				ans = max(ans, mid);
			} else {
				right = mid - 1;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
