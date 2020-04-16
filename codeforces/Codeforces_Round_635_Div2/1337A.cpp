#include <iostream>
using namespace std;

long long T, a, b, c, d;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> a >> b >> c >> d;
		cout << b << " " << c << " " << c << '\n';
	}

	return 0;
}
