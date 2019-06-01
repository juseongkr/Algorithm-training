#include <iostream>
using namespace std;

int main()
{
	int n, a, x, b, y;

	cin >> n >> a >> x >> b >> y;
	while (1) {
		if (a == n)
			a = 1;
		else
			a++;
		if (b == 1)
			b = n;
		else
			b--;
		if (a == b) {
			cout << "YES\n";
			break;
		}
		if (a == x || b == y) {
			cout << "NO\n";
			break;
		}
	}

	return 0;
}
