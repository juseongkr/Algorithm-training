#include <iostream>
using namespace std;

int n, k, ans;
string s;

int main()
{
	cin >> n >> k >> s;
	for (int i=0; i<n; ++i) {
		if (s[i] == 'P') {
			for (int j=max(0, i-k); j<=min(i+k, n-1); ++j) {
				if (s[j] == 'H') {
					s[j] = '*';
					ans++;
					break;
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
