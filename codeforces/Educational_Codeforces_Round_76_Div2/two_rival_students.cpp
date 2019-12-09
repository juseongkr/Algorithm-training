#include <iostream>
using namespace std;

int main()
{
	int t, n, x, a, b;

	cin >> t;
	while (t--) {
		cin >> n >> x >> a >> b;
		if (a > b)
			swap(a, b);
		cout << min(n-1, b-a+x) << '\n';
	}

	return 0;
}
