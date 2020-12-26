#include <iostream>
using namespace std;
#define MAX 501
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m;
string map[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> map[i];

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (map[i][j] != 'W')
				continue;

			for (int k=0; k<4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == 'W')
					continue;

				if (map[nx][ny] == 'S') {
					cout << "0\n";
					return 0;
				}

				map[nx][ny] = 'D';
			}
		}
	}

	cout << "1\n";
	for (int i=0; i<n; ++i)
		cout << map[i] << '\n';

	return 0;
}
