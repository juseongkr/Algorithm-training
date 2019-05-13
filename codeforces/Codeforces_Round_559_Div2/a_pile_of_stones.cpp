#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	int n, ans = 0;

	cin >> n >> s;

	for (int i=0; i<n; ++i) {
		if (s[i] == '-') {
			if (ans > 0)
				ans--;
		}
		else
			ans++;
	}

	cout << ans;

	return 0;
}
