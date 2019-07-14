#include <iostream>
using namespace std;
#define MAX 1005

int a[MAX], t[MAX], l[MAX], r[MAX];

int main()
{
	int n, m;

	cin >> n >> m;
	for (int i=1; i<=m; ++i) {
		cin >> t[i] >> l[i] >> r[i];
		if (t[i] == 1) {
			for (int j=l[i]; j<r[i]; ++j)
				a[j] = 1;
		}
	}

	for (int i=1; i<=m; ++i) {
		if (t[i] == 0) {
			bool flag = true;
			for (int j=l[i]; j<r[i]; ++j)
				if (!a[j])
					flag = false;
			if (flag) {
				cout << "NO\n";
				return 0;
			}
		}
	}

	int k = n;
	cout << "YES\n" << n << " ";
	for (int i=1; i<n; ++i) {
		if (a[i])
			cout << k << " ";
		else
			cout << --k << " ";
	}

	return 0;
}
