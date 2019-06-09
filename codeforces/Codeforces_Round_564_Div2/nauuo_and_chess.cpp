#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x = 1, y = 1;

	cin >> n;
	cout << n/2+1 << '\n';
	for (int i=0; i<n; ++i) {
		cout << x << " " << y << '\n';
		if (x >= y)
			y++;
		else
			x++;
	}

	return 0;
}
