#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 101

int n, m;
char map[MAX][MAX], visit[MAX][MAX];
bool flag;

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> map[i][j];

	vector<tuple<int, int, int>> ans;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (map[i][j] == '*') {
				int len = 0;
				for (int k=1; ; ++k) {
					if (i+k >= n || i-k < 0 || j+k >= m || j-k < 0)
						break;

					if (map[i+k][j] == '*' && map[i-k][j] == '*' && map[i][j-k] == '*' && map[i][j+k] == '*')
						len = k;
					else
						break;
				}
				if (len) {
					ans.push_back({i+1, j+1, len});
					for (int k=1; k<=len; ++k)
						visit[i][j] = visit[i+k][j] = visit[i-k][j] = visit[i][j-k] = visit[i][j+k] = 1;
				}
			}
		}
	}
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (map[i][j] == '*' && !visit[i][j])
				flag = true;

	if (flag) {
		cout << "-1\n";
	} else {
		cout << ans.size() << '\n';
		for (int i=0; i<ans.size(); ++i)
			cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << '\n';
	}

	return 0;
}
