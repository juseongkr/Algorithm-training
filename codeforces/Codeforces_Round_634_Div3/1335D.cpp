#include <iostream>
using namespace std;

int T, n;
string map[10];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		for (int i=0; i<9; ++i) {
			cin >> map[i];
			for (int j=0; j<9; ++j) {
				if (map[i][j] == '1')
					map[i][j] = '2';
				cout << map[i][j];
			}
			cout << '\n';
		}
	}

	return 0;
}
