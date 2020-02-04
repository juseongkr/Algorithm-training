#include <iostream>
#include <vector>
using namespace std;
#define MAX 2001

int n, m, k, x, y;
bool map[MAX][MAX], visit[MAX], dst[MAX];
vector<int> vec;

int main()
{
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		x--;
		y--;
		map[x][y] = map[y][x] = 1;
	}

	cin >> k;
	for (int i=0; i<k; ++i) {
		cin >> x;
		x--;
		dst[x] = 1;
	}

	for (int i=0; i<n; ++i) {
		if (!dst[i])
			continue;

		bool flag = true;
		for (int j=0; j<n; ++j) {
			if (map[i][j] && !dst[j]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			vec.push_back(i);
			visit[i] = 1;
			for (int j=0; j<n; ++j)
				if (map[i][j])
					visit[j] = 1;
		}
	}

	for (int i=0; i<n; ++i) {
		if (dst[i] && !visit[i]) {
			cout  << "-1\n";
			return 0;
		}
	}

	cout << vec.size() << '\n';
	for (int i=0; i<vec.size(); ++i)
		cout << vec[i]+1 << " ";

	return 0;
}
