#include <iostream>
using namespace std;

int main()
{
	int n, k;
	string s;

	cin >> n >> k >> s;
	if (n == 1 && k == 1) {
		cout << "0\n";
		return 0;
	}
	if (n == 1 && k != 1) {
		cout << s;
		return 0;
	}

	for (int i=0; i<n; ++i) {
		if (k == 0)
			break;
		if (i == 0) {
			if (s[i]-'0' > 1) {
				s[i] = '1';
				k--;
			}
		} else {
			if (s[i]-'0' > 0) {
				s[i] = '0';
				k--;
			}
		}
	}
	cout << s << '\n';

	return 0;
}
