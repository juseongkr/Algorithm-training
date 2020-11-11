#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 1001
typedef pair<int, int> pi;
typedef tuple<int, int, int> tp;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, p;
int player[10], ans[10];
string map[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> p;
	for (int i=1; i<=p; ++i)
		cin >> player[i];

	queue<tp> ques[10];
	for (int i=0; i<n; ++i) {
		cin >> map[i];
		for (int j=0; j<m; ++j) {
			int c = map[i][j]-'0';
			if (1 <= c && c <= 9)
				ques[c].push({i, j, player[c]});
		}
	}

	while (1) {
		bool flag = false;
		for (int i=1; i<=p; ++i) {
			auto que = ques[i];
			while (!que.empty()) {
				auto [x, y, s] = que.front();
				que.pop();

				if (s == player[i])
					ques[i].pop();

				for (int j=0; j<4; ++j) {
					int nx = x + dx[j];
					int ny = y + dy[j];

					if (s == 0)
						break;

					if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] != '.')
						continue;

					map[nx][ny] = i+'0';
					ques[i].push({nx, ny, player[i]});
					que.push({nx, ny, s-1});
					flag = true;
				}
			}
		}

		if (!flag)
			break;
	}

	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if ('1' <= map[i][j] && map[i][j] <= '9')
				ans[map[i][j]-'0']++;

	for (int i=1; i<=p; ++i)
		cout << ans[i] << '\n';

	return 0;
}
