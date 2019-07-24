#include <iostream>
using namespace std;

int main()
{
	string s;
	int n, a, b;

	cin >> s >> n;
	for (int i=0; i<n; ++i) {
		cin >> a >> b;
		swap(s[a], s[b]);
	}
	cout << s << '\n';

	return 0;
}
