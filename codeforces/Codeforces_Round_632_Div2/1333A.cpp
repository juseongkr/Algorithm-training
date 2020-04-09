#include <iostream>
using namespace std;

int T, n, m;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
		
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				if (i+j == 0)
					cout << 'W';
				else
					cout << 'B';
			}
			cout << '\n';
		}
	}

	return 0;
}
