#include <iostream>
using namespace std;
const int INF = 1e9+7;
#define MAX 101

int n, k, x, y;
int map[MAX][MAX];

int main()
{
	for (int i=0; i<MAX; ++i)
		for (int j=0; j<MAX; ++j)
			if (i != j)
				map[i][j] = INF;

	cin >> n >> k;
	for (int i=0; i<k; ++i) {
		cin >> x >> y;
		map[x][y] = map[y][x] = 1;
	}

	for (int k=1; k<=n; ++k)
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=n; ++j)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);

	bool flag = true;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			if (map[i][j] > 6)
				flag = false;

	if (flag)
		cout << "Small World!\n";
	else
		cout << "Big World!\n";

	return 0;
}
