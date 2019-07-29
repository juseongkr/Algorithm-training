#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 11

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m, k, x, y, z;
int map[MAX][MAX], nou[MAX][MAX], new_tree[MAX][MAX];
bool visit[MAX][MAX];
vector<int> tree[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> map[i][j];
			nou[i][j] = 5;
		}
	}

	for (int i=0; i<m; ++i) {
		cin >> x >> y >> z;
		tree[x-1][y-1].push_back(z);
	}

	while (k--) {
		memset(new_tree, 0, sizeof(new_tree));
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				sort(tree[i][j].begin(), tree[i][j].end());
				vector<int> t;
				int dead = 0;
				for (int s=0; s<tree[i][j].size(); ++s) {
					int cur = tree[i][j][s];
					if (cur <= nou[i][j]) {
						t.push_back(cur+1);
						nou[i][j] -= cur;
						if ((cur+1) % 5 != 0)
							continue;

						for (int p=0; p<8; ++p) {
							int nx = i + dx[p];
							int ny = j + dy[p];

							if (nx < 0 || ny < 0 || nx >= n || ny >= n)
								continue;

							new_tree[nx][ny] += 1;
						}
					} else {
						dead += cur/2;
					}
				}
				nou[i][j] += (dead + map[i][j]);
				tree[i][j] = t;
			}
		}
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				for (int k=0; k<new_tree[i][j]; ++k)
					tree[i][j].push_back(1);
	}

	int ans = 0;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			ans += tree[i][j].size();

	cout << ans << '\n';

	return 0;
}
