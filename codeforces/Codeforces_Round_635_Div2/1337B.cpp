#include <iostream>
using namespace std;

int T, x, n, m;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> x >> n >> m;
		for (int i=0; i<n; ++i) {
			if (x <= 20)
				break;
			x = x/2+10;
		}
		if (x - m * 10 > 0)
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}
