#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string s;
int T, n, m;

inline int charToNum(string s)
{
	if (s.length() == 1)
		return s[0]-'A';
	else if (s.length() == 2)
		return (s[0]-'A') * 26 + s[1]-'A' + 26;
	return ((s[0]-'A') * 26 + s[1]-'A') * 26 + s[2]-'A' + 27 * 26;
}

pair<int, int> conv(string s)
{
	for (int i=0; i<s.length(); ++i)
		if ('1' <= s[i] && s[i] <= '9')
			return {stoi(s.substr(i))-1, charToNum(s.substr(0, i))};
	return {0, 0};
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> m >> n;
		vector<vector<int>> in(n, vector<int>(m, 0));
		vector<vector<int>> sheet(n, vector<int>(m, 0));
		vector<vector<vector<pair<int, int>>>> graph(n, vector<vector<pair<int, int>>>(m));

		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				cin >> s;
				if (s[0] == '=') {
					s += '+';
					int l = 1;
					for (int r=1; r<s.length(); ++r) {
						if (s[r] == '+') {
							auto [u, v] = conv(s.substr(l, r-l));
							graph[u][v].push_back({i, j});
							in[i][j]++;
							l = r+1;
						}
					}
				} else {
					sheet[i][j] = stoi(s);
				}
			}
		}

		queue<pair<int, int>> que;
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				if (!in[i][j])
					que.push({i, j});

		while (!que.empty()) {
			auto [x, y] = que.front();
			que.pop();

			for (int i=0; i<graph[x][y].size(); ++i) {
				auto [nx, ny] = graph[x][y][i];
				sheet[nx][ny] += sheet[x][y];
				if (--in[nx][ny] == 0)
					que.push({nx, ny});
			}
		}

		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j)
				cout << sheet[i][j] << " ";
			cout << '\n';
		}
	}

	return 0;
}
