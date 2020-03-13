#include <iostream>
using namespace std;
#define MAX 10001

int n, m, l, r, sum, ans;
int num[MAX];

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	while (l <= r && r <= n) {
		if (sum >= m) {
			if (sum == m)
				ans++;
			sum -= num[l++];
		}  else {
			sum += num[r++];
		}
	}
	cout << ans << '\n';

	return 0;
}
