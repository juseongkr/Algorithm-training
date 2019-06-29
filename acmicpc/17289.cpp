#include <iostream>
using namespace std;

int main()
{
	string s;

	cin >> s;
	for (int i=0; i<s.length(); ++i) {
		int c = s[i]-'A';
		cout << char(((c+i+12) % 26)+'A');
	}

	return 0;
}
