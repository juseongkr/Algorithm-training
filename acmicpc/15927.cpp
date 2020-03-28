#include <iostream>
using namespace std;

string s;

int main()
{
	cin >> s;
	bool flag = false;
	int n = s.length();
	for (int i=0; i<n/2; ++i) {
		if (s[i] != s[n-i-1]) {
			cout << n << '\n';
			return 0;
		} else if (s[i] != s[i+1]) {
			flag = true;
		}
	}
	if (flag)
		cout << n-1 << '\n';
	else
		cout <<  "-1\n";

	return 0;
}
