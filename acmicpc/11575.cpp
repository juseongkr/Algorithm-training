#include <iostream>
using namespace std;

int main()
{
	string s;
	int t, a, b;

	cin >> t;
	while (t--) {
		cin >> a >> b >> s;
		for (int i=0; i<s.length(); ++i)
			cout << char((((a * s[i]-65) + b) % 26)+65);
		cout << '\n';
	}

	return 0;
}
