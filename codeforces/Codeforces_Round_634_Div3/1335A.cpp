#include <iostream>
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
		if (n % 2)
			cout << n/2 << '\n';
		else
			cout << n/2-1 << '\n';
	}

	return 0;
}
