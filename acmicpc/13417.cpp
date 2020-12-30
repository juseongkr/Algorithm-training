#include <iostream>
using namespace std;
#define MAX 1001

int T, n;
string s[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> s[i];

		string ans = s[0], l = s[0];
		for (int i=1; i<n; ++i) {
			if (l >= s[i]) {
				ans = s[i] + ans;
				l = s[i];
			} else {
				ans += s[i];
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
