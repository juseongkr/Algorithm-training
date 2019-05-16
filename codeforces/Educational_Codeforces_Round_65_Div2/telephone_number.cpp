#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n, flag;
	string s;

	cin >> t;
	while (t--) {
		cin >> n >> s;
		flag = 0;
		for (int i=0; i<n; ++i) {
			if (s[i] == '8' && n-i >= 11) {
				flag = 1;
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
