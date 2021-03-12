#include <iostream>
using namespace std;
#define MAX 1000001

int T, n;
int num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> num[i];

		long long mx = -1, ans = 0;
		for (int i=n-1; i>=0; i--) {
			if (mx < num[i]) {
				mx = num[i];
			} else {
				ans += mx - num[i];
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
