#include <iostream>
using namespace std;
 
int main()
{
	int t, n;

	cin >> t;
	while (t--) {
		cin >> n;

		bool flag = false;
		int a = 0, b = 0, c = 0;
		for (int i=2; i*i*i<=n; ++i) {
			if (n % i)
				continue;
			for (int j=i+1; j*j<=n/i; ++j) {
				if (n % (i * j) == 0) {
					int k = n / (i * j);
					if (i != k && j != k) {
						flag = true;
						a = i;
						b = j;
						c = k;
					}
				}
			}
		}
		if (flag)
			cout << "YES\n" << a << " " << b << " " << c << '\n';
		else
			cout << "NO\n";
	}

	return 0;
}
