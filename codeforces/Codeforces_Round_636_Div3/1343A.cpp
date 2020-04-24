#include <iostream>
using namespace std;

long long T, n;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=2; i<30; ++i) {
			int bit = (1 << i)-1;
			if (n % bit == 0) {
				cout << n / bit << '\n';
				break;
			}
		}
	}

	return 0;
}
