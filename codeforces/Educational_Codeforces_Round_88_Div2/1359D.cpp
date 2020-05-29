#include <iostream>
using namespace std;
#define MAX 100001

int n, num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	int ans = 0;
	for (int mx=1; mx<=30; ++mx) {
		int sum = 0;
		for (int j=0; j<n; ++j) {
			if (sum < 0)
				sum = 0;

			sum += num[j];
			if (mx < num[j])
				sum = 0;

			ans = max(ans, sum - mx);
		}
	}
	cout << ans << '\n';

	return 0;
}
