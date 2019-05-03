#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0;
	string s;

	cin >> s;
	for (int i=0; i<s.length()-2; ++i) {
		if (s[i] == 'J' && s[i+1] == 'O' && s[i+2] == 'I')
			a++;
		if (s[i] == 'I' && s[i+1] == 'O' && s[i+2] == 'I')
			b++;
	}
	cout << a << '\n' << b << '\n';

	return 0;
}
