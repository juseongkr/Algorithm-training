#include <iostream>
using namespace std;
#define MAX 101

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int arr[MAX][MAX];
int n, m, k, x, y, ans;

int main()
{
	cin >> n >> m;
	for (int i=n*m; i>0; i--) {
		arr[x][y] = i;

		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny]) {
			k = (k + 1) % 4;
			ans++;
		}
		x += dx[k];
		y += dy[k];
	}
	cout << ans - 1 << '\n';

	return 0;
}
