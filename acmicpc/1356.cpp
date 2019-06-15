#include <iostream>
using namespace std;

int main()
{
	string s;
	int a, b, mid = 0;

	cin >> s;
	for (int i=0; i<s.length()-1; ++i) {
		mid++;
		a = b = 1;
		for (int j=0; j<mid; ++j)
			a *= s[j]-'0';

		for (int j=mid; j<s.length(); ++j)
			b *= s[j]-'0';

		if (a == b) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";

	return 0;
}
