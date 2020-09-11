#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001
const int INF = 2e9+7;

int n, m;
int num[MAX];

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	sort(num, num+n);

	int ans = INF;
	int l = 0, r = 0;
	while (l < n && r < n) {
		int sub = abs(num[r] - num[l]);
		if (m <= sub) {
			ans = min(ans, sub);
			l++;
		} else {
			r++;
		}
	}
	cout << ans << '\n';

	return 0;
}
