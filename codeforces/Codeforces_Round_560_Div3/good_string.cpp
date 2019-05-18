#include <iostream>
using namespace std;

int main()
{
	int n, len;
	char s[200001];

	cin >> n;
	len = n;
	for (int i=1; i<=n; i++) {
		cin >> s[i];
		if (i % 2 == 0 && s[i] == s[i-1]) {
			n--;
			i--;
		}
	}
	if (n % 2 != 0)
		n--;

	cout << len - n  << '\n';
	for (int i=1; i<=n; ++i)
		cout << s[i];
	cout <<'\n';

	return 0;
}
