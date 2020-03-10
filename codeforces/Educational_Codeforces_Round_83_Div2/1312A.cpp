#include <iostream>
using namespace std;

int T, n, m;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> m;
		if (n % m == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
