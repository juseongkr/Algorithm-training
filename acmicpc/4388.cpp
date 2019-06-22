#include <iostream>
using namespace std;

int main()
{
	int a, b, cnt;

	while (cin >> a >> b) {
		if (a == 0 && b == 0)
			break;
		cnt = 0;
		while (a > 0 && b > 0) {
			int carry = 0;
			int n = (a % 10 + b % 10) / 10;
			if (n > 0) {
				cnt++;
				carry = n;
			}
			a /= 10;
			b /= 10;
			if (a > b)
				b += carry;
			else
				a += carry;
		}
		cout << cnt << '\n';
	}

	return 0;
}
