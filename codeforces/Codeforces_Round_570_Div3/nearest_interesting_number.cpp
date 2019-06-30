#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;

	cin >> n;
	for (int i=n; i<=2000; ++i) {
		int t = i;
		int sum = 0;
		while (t) {
			sum += t % 10;
			t /= 10;
		}
		if (sum % 4 == 0) {
			cout << i << '\n';
			break;
		}
	}

	return 0;
}
