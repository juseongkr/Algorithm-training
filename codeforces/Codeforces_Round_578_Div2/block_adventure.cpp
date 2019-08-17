#include <iostream>
using namespace std;
#define MAX 101

int num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n, m, k;

	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		for (int i=0; i<n; ++i)
			cin >> num[i];

		for (int i=0; i<n; ++i) {
			if (i == n-1) {
				cout << "YES\n";
				break;
			}
			if (num[i+1] - (num[i] + m) > k) {
				cout << "NO\n";
				break;
			}
			m += num[i] - (max(0, num[i+1] - k));
		}
	}

	return 0;
}
