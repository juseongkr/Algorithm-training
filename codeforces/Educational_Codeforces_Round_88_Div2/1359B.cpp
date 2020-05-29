#include <iostream>
using namespace std;
#define MAX 101

string map[MAX];
int T, n, m, x, y;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n >> m >> x >> y;
		for (int i=0; i<n; ++i)
			cin >> map[i];

		if (2 * x > y) {
			int one = 0, two = 0;
			for (int i=0; i<n; ++i) {
				for (int j=0; j<m; ++j) {
					if (map[i][j] == '.' && j+1 < m && map[i][j+1] == '.') {
						two++;
						j++;
					} else if (map[i][j] == '.') {
						one++;
					}
				}
			}
			cout << y * two + x * one << '\n';
		} else {
			int one = 0;
			for (int i=0; i<n; ++i) {
				for (int j=0; j<m; ++j) {
					if (map[i][j] == '.')
						one++;
				}
			}
			cout << x * one << '\n';
		}
	}

	return 0;
}
