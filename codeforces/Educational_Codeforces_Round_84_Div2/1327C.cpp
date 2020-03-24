#include <iostream>
using namespace std;

int n, m, k, x, y;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0; i<k; ++i)
		cin >> x >> y;

	for (int i=0; i<k; ++i)
		cin >> x >> y;

	string ans;
	for (int i=0; i<n-1; ++i)
		ans += "U";

	for (int i=0; i<m-1; ++i)
		ans += "L";

	for (int i=0; i<n; ++i) {
		if (i%2)
			for (int j=0; j<m-1; ++j)
				ans += "L";
		else
			for (int j=0; j<m-1; ++j)
				ans += "R";
		ans += "D";
	}
	cout << ans.length() << '\n' << ans << '\n';

	return 0;
}
