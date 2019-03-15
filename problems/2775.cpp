#include <iostream>
using namespace std;

long long a[15][15];

int main()
{
	int x, y, n;

	cin >> n;

	for (int k=0; k<n; ++k) {
		cin >> x >> y;

		for (int i=1; i<15; ++i)
			a[0][i] = i;

		for (int i=1; i<15; ++i)
			for (int j=1; j<15; ++j)
				a[i][j] = a[i-1][j] + a[i][j-1];

		cout << a[x][y] << '\n';
	}

	return 0;
}
