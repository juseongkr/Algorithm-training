#include <iostream>
using namespace std;

int main()
{
	int num[101];
	int n, m, ans = 0;

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			for (int k=0; k<n; ++k) {
				if (i == j || j == k || k ==i)
					continue;
				int sum = num[i] + num[j] + num[k];
				if (ans < sum && sum <= m)
					ans = sum;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
