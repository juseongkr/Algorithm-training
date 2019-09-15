#include <iostream>
using namespace std;
#define MAX 100001

bool flag;
int n, cnt;
long long a[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	long long ans = 0;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		if (a[i] < 0) {
			ans += abs(a[i]+1);
			cnt++;
		} else if (a[i] > 0) {
			ans += abs(a[i]-1);
		} else {
			flag = true;
			ans++;
		}
	}

	if (flag)
		cout << ans << '\n';
	else if (cnt % 2 == 1)
		cout << ans + 2 << '\n';
	else
		cout << ans << '\n';

	return 0;
}
