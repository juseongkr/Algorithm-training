#include <iostream>
using namespace std;
#define MAX 999

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
pair<int, int> ans;
int arr[MAX][MAX];
int n, m, k, x, y;

int main()
{
	cin >> n >> m;
	for (int i=n*n; i>0; i--) {
		arr[x][y] = i;
		if (i == m)
			ans = {x, y};

		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[nx][ny])
			k = (k + 1) % 4;

		x += dx[k];
		y += dy[k];
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j)
			cout << arr[i][j] << " ";
		cout << '\n';
	}
	cout << ans.first + 1 << " " << ans.second + 1 << '\n';

	return 0;
}
