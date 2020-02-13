#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int t;
	string a, b, c;

	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		bool flag = true;
		for (int i=0; i<a.length(); ++i) {
			if (!(a[i] == c[i] || b[i] == c[i])) {
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
