#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int q, n;

	cin >> q;
	while (q--) {
		cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; ++i)
			cin >> a[i];

		bool flag = true;
		for (int i=1; i<n; ++i) {
			if (abs(a[i] - a[i-1]) != 1 && n - abs(a[i] - a[i-1]) != 1) {
				flag = false;
				break;
			}
		}

		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
