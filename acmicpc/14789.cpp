#include <iostream>
using namespace std;

int t, k;
string s;

int main()
{
	cin >> t;
	for (int T=1; T<=t; ++T) {
		cin >> s >> k;

		int cnt = 0;
		int n = s.length();
		for (int i=0; i<=n-k; ++i) {
			if (s[i] == '-') {
				cnt++;
				for (int j=i; j<i+k; ++j)
					s[j] = s[j] == '+' ? '-' : '+';
			}
		}

		bool flag = true;
		for (int i=0; i<n; ++i) {
			if (s[i] == '-') {
				flag = false;
				break;
			}
		}

		if (flag)
			cout << "Case #" << T << ": " << cnt << '\n';
		else
			cout << "Case #" << T << ": IMPOSSIBLE\n";
	}

	return 0;
}
