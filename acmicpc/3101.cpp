#include <iostream>
using namespace std;
#define MAX 300001

int n, k;
long long num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	int y = 1, x = 1;
	long long ans = 1;

	cin >> n >> k >> s;
	for (int i=1; i<n*2; ++i) {
		if (i > n)
			num[i] = num[i-1] + n - (i % n);
		else
			num[i] = num[i-1] + i;
	}

	for (int i=0; i<k; ++i) {
		if (s[i] == 'U') {
			if (y > n)
				x++;
			y--;
		} else if (s[i] == 'D') {
			if (y >= n)
				x--;
			y++;
		} else if (s[i] == 'L') {
			if (y <= n)
				x--;
			y--;
		} else {
			if (y < n)
				x++;
			y++;
		}
		if (y % 2 == 0)
			ans += num[y] - x + 1;
		else
			ans += num[y-1] + x;
	}
	cout << ans << '\n';

	return 0;
}
