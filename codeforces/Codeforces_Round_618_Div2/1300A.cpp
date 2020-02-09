#include <iostream>
using namespace std;

int t, n;
int num[101];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		int ans = 0, sum = 0;
		for (int i=0; i<n; ++i) {
			cin >> num[i];
			sum += num[i];
			if (num[i] == 0) {
				ans++;
				sum++;
			}
		}

		if (sum == 0)
			cout << ans+1 << '\n';
		else
			cout << ans << '\n';
	}

	return 0;
}
