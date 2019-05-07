#include <iostream>
using namespace std;

int main()
{
	string str[101];
	int n, k;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> str[i];
	cin >> k;
	if (k == 1) {
		for (int i=0; i<n; ++i)
			cout << str[i] << '\n';
	} else if (k == 2) {
		for (int i=0; i<n; ++i) {
			for (int j=n-1; j>=0; j--)
				cout << str[i][j];
			cout << '\n';
		}
	} else {
		for (int i=n-1; i>=0; i--)
			cout << str[i] << '\n';
	}
	return 0;
}
