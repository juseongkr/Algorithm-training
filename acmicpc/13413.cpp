#include <iostream>
using namespace std;

int T, n;
string a, b;

int main()
{
	cin >> T;
	while (T--) {
		int x = 0, y = 0;
		cin >> n >> a >> b;
		for (int i=0; i<n; ++i) {
			if (a[i] == 'W' && b[i] == 'B')
				x++;
			else if (a[i] == 'B' && b[i] == 'W')
				y++;
		}
		cout << max(x, y) << '\n';
	}

	return 0;
}
