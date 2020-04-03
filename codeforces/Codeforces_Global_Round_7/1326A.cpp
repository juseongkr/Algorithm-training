#include <iostream>
#include <algorithm>
using namespace std;

int T, n;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		if (n == 1) {
			cout << "-1\n";
			continue;
		}

		string s = "2";
		for (int i=1; i<n; ++i)
			s += '3';
		cout << s << '\n';
	}

	return 0;
}
