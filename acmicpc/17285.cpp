#include <iostream>
using namespace std;

int main()
{
	string s;

	cin >> s;
	for (int i=0; i<s.length(); ++i)
		cout << char(((s[i]-'0') ^ 54)+'0');

	return 0;
}
