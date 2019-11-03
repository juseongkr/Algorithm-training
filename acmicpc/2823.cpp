#include <iostream>
using namespace std;
#define MAX 11
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m;
char map[MAX][MAX];

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	bool check = false;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (map[i][j] == 'X')
				continue;

			int cnt = 0;
			for (int k=0; k<4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue;

				if (map[nx][ny] == '.')
					cnt++;
			}

			if (cnt <= 1) {
				cout << "1\n";
				return 0;
			}
		}
	}
	cout << "0\n";

	return 0;
}
