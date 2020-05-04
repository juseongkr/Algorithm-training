#include <iostream>
using namespace std;
#define MAX 51

int n, m, k;
int pos[MAX];

bool check(int mid)
{
	int cnt = 0, cur = 0;
	for (int i=0; i<k; ++i) {
		if (cur <= pos[i]) {
			cur = pos[i] + mid;
			cnt++;
		}
	}
	return cnt >= m;
}

int main()
{
	cin >> n >> m >> k;
	for (int i=0; i<k; ++i)
		cin >> pos[i];

	int l = 0, r = pos[k-1];
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid))
			l = mid+1;
		else
			r = mid-1;
	}

	string ans;
	int cur = 0;
	for (int i=0; i<k; ++i) {
		if (cur <= pos[i] && m > 0) {
			cur = pos[i] + r;
			ans += '1';
			m--;
		} else {
			ans += '0';
		}
	}
	cout << ans << '\n';

	return 0;
}
