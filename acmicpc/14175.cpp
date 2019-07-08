#include <iostream>
using namespace std;

int main()
{
	string s[10];
	int m, n, k;

	cin >> m >> n >> k;
	for (int i=0; i<m; ++i)
		cin >> s[i];

	for (int i=0; i<m*k; ++i) {
		for (int j=0; j<n*k; ++j)
			cout << s[i/k][j/k];
		cout << '\n';
	}

	return 0;
}
