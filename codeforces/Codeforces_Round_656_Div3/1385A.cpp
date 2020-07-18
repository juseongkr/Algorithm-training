#include <iostream>
#include <algorithm>
using namespace std;

int T, n;
int x[3];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		for (int i=0; i<3; ++i)
			cin >> x[i];

		sort(x, x+3);

		if (x[0] == x[1] == x[2]) {
			cout << "YES\n" << x[0] << " " << x[1] << " " << x[2] << '\n';
		} else if (x[1] == x[2]) {
			cout << "YES\n" << x[2] << " " << x[0] << " " << x[0] << '\n';

		} else {
			cout << "NO\n";
		}
	}

	return 0;
}
