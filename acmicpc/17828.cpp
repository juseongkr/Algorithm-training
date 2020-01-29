#include <iostream>
using namespace std;

int main()
{
	string s;
	int n, x;

	cin >> n >> x;
	if (x < n || n * 26 < x) {
		cout << "!\n";
		return 0;
	}

	for (int i=0; i<n; ++i) {
		s += 'A';
		x--;
	}

	for (int i=n-1; i>=0; i--) {
		char t = min(25, x);
		s[i] += t;
		x -= t;
	}

	cout << s << '\n';

	return 0;
}
