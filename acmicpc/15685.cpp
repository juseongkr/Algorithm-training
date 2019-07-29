#include <iostream>
#include <vector>
using namespace std;
#define MAX 101

const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};
int map[MAX][MAX];
int ans;

int main()
{
	vector<int> w;
	int n, x, y, d, g;

	cin >> n;
	for (int k=0; k<n; ++k) {
		cin >> x >> y >> d >> g;
		map[y][x] = 1;
		w.push_back(d);

		for (int i=0; i<g; ++i) {
			for (int j=w.size()-1; j>=0; j--) {
				int next = (w[j] + 1) % 4;
				w.push_back(next);
			}
		}

		for (int i=0; i<w.size(); ++i) {
			y += dy[w[i]];
			x += dx[w[i]];
			map[y][x] = 1;
		}
		w.clear();
	}

	for (int i=0; i<MAX; ++i)
		for (int j=0; j<MAX; ++j)
			if (map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1])
				ans++;
	cout << ans << '\n';

	return 0;
}
