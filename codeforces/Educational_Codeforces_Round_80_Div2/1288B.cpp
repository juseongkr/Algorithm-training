#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long t, a, b;

	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << a * (long long)log10(b+1) << '\n';
	}

	return 0;
}
