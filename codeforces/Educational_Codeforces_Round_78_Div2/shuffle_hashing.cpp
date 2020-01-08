#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int t;

	cin >> t;
	while (t--) {
		string a, b;

		cin >> a >> b;
		int n = a.length();
		int m = b.length();
		if (n > m) {
			cout << "NO\n";
			continue;
		}

		sort(a.begin(), a.end());

		bool flag = false;
		for (int i=0; i<=m-n; ++i) {
			string p = b.substr(i, n);
			sort(p.begin(), p.end());
			if (a == p) {
				flag = true;
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
