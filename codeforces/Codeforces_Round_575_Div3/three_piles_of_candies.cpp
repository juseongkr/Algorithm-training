#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int q;

	cin >> q;
	while (q--) {
		long long a, b, c;
		cin >> a >> b >> c;
		cout << (a + b + c) / 2 << '\n';
	}

	return 0;
}
