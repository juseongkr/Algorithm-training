#include <iostream>
#include <vector>
using namespace std;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m;
bool visit[3][3];
char map[3][3];
vector<pair<int, int>> ans;

void solve(int x, int y, int sum, int k)
{
	visit[x][y] = 1;
	ans.push_back({x, y});

	if (sum == n && k == 0) {
		cout << "1\n";
		for (auto i : ans)
			cout << i.first << " " << i.second << '\n';
		exit(0);
	}

	for (int i=0; i<4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3 || visit[nx][ny])
			continue;

		if (map[x][y] == '+')
			solve(nx, ny, sum + (map[nx][ny]-'0'), k-1);
		else if (map[x][y] == '-')
			solve(nx, ny, sum - (map[nx][ny]-'0'), k-1);
		else
			solve(nx, ny, sum, k);
	}

	ans.pop_back();
	visit[x][y] = 0;
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<3; ++i)
		for (int j=0; j<3; ++j)
			cin >> map[i][j];

	for (int i=0; i<3; ++i)
		for (int j=0; j<3; ++j)
			if ('0' <= map[i][j] && map[i][j] <= '9')
				solve(i, j, map[i][j]-'0', m-1);

	cout << "0\n";

	return 0;
}
