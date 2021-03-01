#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000001

int n, k, m, mx;
long long sum;
int s[MAX];

bool check(int mid)
{
	int cnt = 0;
	for (int i=0; i<n; ++i)
		cnt += s[i]/mid;

	return cnt >= m;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> k >> m;
	for (int i=0; i<n; ++i) {
		cin >> s[i];
		if (s[i] <= k)
			s[i] = 0;
		else if (s[i] < 2*k)
			s[i] -= k;
		else
			s[i] -= 2*k;

		sum += s[i];
		mx = max(mx, s[i]);
	}

	if (sum < m) {
		cout << "-1\n";
		return 0;
	}

	int l = 1, r = mx;
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid))
			l = mid+1;
		else
			r = mid-1;
	}
	cout << r << '\n';

	return 0;
}
