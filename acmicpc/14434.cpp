#include <iostream>
using namespace std;
#define MAX 501
const int INF = 1e9+7;

int map[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, m, u, v, w;

	cin >> n >> m;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			if (i != j)
				map[i][j] = INF;

	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			cin >> map[i][j];

	for (int k=1; k<=n; ++k)
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=n; ++j)
				map[i][j] = min(map[i][k] + map[k][j], map[i][j]);

	while (m--) {
		cin >> u >> v >> w;
		if (map[u][v] <= w)
			cout << "Enjoy other party\n";
		else
			cout << "Stay here\n";
	}

	return 0;
}
