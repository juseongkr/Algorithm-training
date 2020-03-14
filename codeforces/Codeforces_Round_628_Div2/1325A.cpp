#include <iostream>
using namespace std;

int T, x;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> x;
		cout << "1 " << x-1 << '\n';
	}

	return 0;
}
