#include <iostream>
using namespace std;

int T;
long long n, m;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> m;
		if (n == 1) {
			cout << "0\n";
		} else if (n == 2) {
			cout << m << '\n';
		} else {
			cout << m*2 << '\n';
		}
	}

	return 0;
}
