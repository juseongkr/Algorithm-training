#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int t, x, y, a, b;

	cin >> t;
	while (t--) {
		cin >> x >> y >> a >> b;
		if ((y-x) % (a+b) == 0)
			cout << (y-x) / (a+b) << '\n';
		else
			cout << "-1\n";
	}

	return 0;
}
