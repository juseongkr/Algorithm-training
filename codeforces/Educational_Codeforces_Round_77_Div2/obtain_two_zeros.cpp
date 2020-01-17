#include <iostream>
using namespace std;

int n, a, b;

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a >> b;
		if (a > b)
			swap(a, b);

		if (2*a >= b && (a+b) % 3 == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
