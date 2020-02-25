#include <iostream>
using namespace std;

int T, a, b;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> a >> b;
		if (a < b) {
			if ((b-a) % 2)
				cout << "1\n";
			else
				cout << "2\n";
		} else if (a > b) {
			if ((a-b) % 2)
				cout << "2\n";
			else
				cout << "1\n";
		} else {
			cout << "0\n";
		}
	}

	return 0;
}
