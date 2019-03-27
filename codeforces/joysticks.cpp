#include <iostream>
using namespace std;

int main()
{
	int a, b, cnt = 0;

	cin >> a >> b;

	while (a > 0 && b > 0) {
		if (a == 1 && b == 1)
			break;

		if (a == 1) {
			a++;
			b -= 2;
		} else if (b == 1) {
			b++;
			a -= 2;
		} else {
			if (a < b) {
				a++;
				b -= 2;
			} else {
				b++;
				a -= 2;
			}
		}
		cnt++;
	}
	
	cout << cnt << '\n';

	return 0;
}
