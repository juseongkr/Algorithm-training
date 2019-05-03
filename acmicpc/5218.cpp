#include <iostream>
using namespace std;

int main()
{
	string s, r;
	int n;

	cin >> n;
	for (int k=0; k<n; ++k) {
		cin >> s >> r;
		cout << "Distances: ";
		for (int i=0; i<s.length(); ++i) {
			int a = s[i]-'0';
			int b = r[i]-'0';
			if (b - a >= 0)
				cout << b - a << " ";
			else
				cout << b - a + 26 << " ";
		}
		cout << '\n';
	}

	return 0;
}
