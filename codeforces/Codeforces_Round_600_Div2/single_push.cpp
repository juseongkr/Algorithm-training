#include <iostream>
using namespace std;
#define MAX 100001

int a[MAX], b[MAX];

int main()
{
	int t, n, k;

	cin >> t;
	while (t--) {
		cin >> n;
		bool flag = false;
		for (int i=0; i<n; ++i)
			cin >> a[i];

		for (int i=0; i<n; ++i)
			cin >> b[i];

		int l = -1, r = -1;
		for (int i=0; i<n; ++i) {
			if (a[i] != b[i]) {
				if (l == -1)
					l = i;
				r = i;
			}
		}

		if (l == -1) {
			cout << "YES\n";
			continue;
		}

		if (a[l] >= b[l]) {
			cout << "NO\n";
			continue;
		}

		for (int i=l; i<=r; ++i) {
			if (a[i] - b[i] != a[l] - b[l]) {
				cout << "NO\n";
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << "YES\n";
	}

	return 0;
}
