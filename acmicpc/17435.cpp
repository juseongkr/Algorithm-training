#include <iostream>
using namespace std;
#define MAX 500001

int table[MAX][19];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int m, q, n, x;

	cin >> m;
	for (int i=1; i<=m; ++i)
		cin >> table[i][0];

	for (int j=1; j<19; ++j)
		for (int i=1; i<=m; ++i)
			table[i][j] = table[table[i][j-1]][j-1];

	cin >> q;
	while (q--) {
		cin >> n >> x;
		for (int i=0; n; ++i) {
			if (n % 2 == 1)
				x = table[x][i];
			n /= 2;
		}
		cout << x << '\n';
	}

	return 0;
}
