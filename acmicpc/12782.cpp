#include <iostream>
using namespace std;

int T;
string a, b;

int main()
{
	cin >> T;
	while (T--) {
		int x = 0, y = 0;
		cin >> a >> b;
		for (int i=0; i<a.length(); ++i) {
			if (a[i] == '1' && b[i] == '0')
				x++;
			else if (a[i] == '0' && b[i] == '1')
				y++;
		}
		cout << max(x, y) << '\n';
	}

	return 0;
}
