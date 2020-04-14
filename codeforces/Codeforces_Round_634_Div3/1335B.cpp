#include <iostream>
using namespace std;

int T, n, a, b;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> a >> b;

		string ans;
		int p = -1;
		for (int i=0; i<b; ++i)
			ans += (++p)+'a';

		for (int i=0; i<a-b; ++i)
			ans += p+'a';

		while (ans.length() < n)
			ans += ans;

		for (int i=0; i<n; ++i)
			cout << ans[i];
		cout << '\n';

	}

	return 0;
}
