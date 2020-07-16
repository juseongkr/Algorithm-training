#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001

int T, n, x;
int num[MAX];

int main()
{
	cin >> T;
	while (T--) {
		cin >> n >> x;
		for (int i=0; i<n; ++i)
			cin >> num[i];

		sort(num, num+n);

		int ans = 0, cnt = 0;
		for (int i=n-1; i>=0; i--) {
			if (++cnt * num[i] >= x) {
				ans++;
				cnt = 0;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
