#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string v = "aeiou";
	int n, x = 0, y = 0;

	cin >> n;
	for (int i=5; i*i<=n; ++i) {
		if (n % i == 0) {
			x = i;
			y = n/i;
		}
	}
	if (x) {
		for (int i=0; i<x; ++i)
			for (int j=0; j<y; ++j)
				cout << v[(i+j) % 5];
	} else {
		cout << "-1\n";
	}

	return 0;
}
