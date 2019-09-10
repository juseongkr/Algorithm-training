#include <iostream>
using namespace std;

int m[27];

int main()
{
	string s;
	int n;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> s;
		m[s[0]-'A']++;
	}

	for (int i=0; i<27; ++i) {
		if (!m[i]) {
			cout << i << '\n';
			break;
		}
	}

	return 0;
}
