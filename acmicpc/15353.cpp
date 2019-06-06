#include <iostream>
using namespace std;

int main()
{
	char x;
	string a, b, t;

	cin >> a >> b;
	t = a[a.length()-1]-'0' + b[b.length()-1]-'0';
	x = t[0]/10;
	t[0] = (t[0] % 10)+'0';
	a.pop_back();
	b.pop_back();

	while (a.length() > 0 || b.length() > 0) {
		char y = 0;
		if (a.length()) {
			y = a[a.length()-1]-'0';
			a.pop_back();
		}
		if (b.length()) {
			y += b[b.length()-1]-'0';
			b.pop_back();
		}
		y += x;
		x = y/10;
		y = (y % 10)+'0';
		t = y + t;
	}
	if (x > 0) {
		x = x+'0';
		t = x + t;
	}
	cout << t << '\n';

	return 0;
}
