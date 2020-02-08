#include <iostream>
using namespace std;

int n, k;
int map[301][301];

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		if (i % 2) {
			for (int j=n-1; j>=0; j--)
				map[j][i] = ++k;
		} else {
			for (int j=0; j<n; ++j)
				map[j][i] = ++k;
		}
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j)
			cout << map[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}
