#include <iostream>
using namespace std;

int main()
{
	int t, a, b;

	cin >> t;
	while (t--) {
		cin >> a >> b;
		int k = abs(b-a);
		int ans = 0;
		ans += k/5;
		k %= 5;
		ans += k/2;
		cout << ans + k%2 << '\n';
	}

	return 0;
}
