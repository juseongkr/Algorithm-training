#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;
#define MAX 101
const int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int n, m, label;
string s[MAX];
int sky[MAX][MAX];
unordered_map<int, bool> dup;
unordered_map<int, char> output;
unordered_map<int, double> shape;
vector<pair<int, int>> vec[MAX*6];

void dfs(int x, int y)
{
	sky[x][y] = label;
	vec[label].push_back({x, y});

	for (int i=0; i<8; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] == '0' || sky[nx][ny])
			continue;

		dfs(nx, ny);
	}
}

inline double dist(pair<int, int> a, pair<int, int> b)
{
	return sqrt((double)(a.first - b.first)*(a.first - b.first) + \
		(double)(a.second - b.second)*(a.second - b.second));
}

void mark(int k)
{
	double ret = 0;
	for (int i=0; i<vec[k].size(); ++i)
		for (int j=i+1; j<vec[k].size(); ++j)
			ret += dist(vec[k][i], vec[k][j]);

	int tag = -1;
	for (int i=1; i<=k; ++i) {
		double err = abs(ret - shape[i]);
		if (err <= 1e-6) {
			tag = i;
			break;
		}
	}

	shape[k] = ret;
	if (tag != -1) {
		for (int i=0; i<vec[k].size(); ++i) {
			auto [u, v] = vec[k][i];
			sky[u][v] = tag;
		}
	}
}

int main()
{
	cin >> m >> n;
	for (int i=0; i<n; ++i)
		cin >> s[i];

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (s[i][j] == '1' && !sky[i][j]) {
				label++;
				dfs(i, j);
			}
		}
	}

	for (int i=1; i<=label; ++i)
		mark(i);

	int letter = 0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (s[i][j] == '1') {
				int tag = sky[i][j];
				if (!dup[tag]) {
					dup[tag] = 1;
					output[tag] = (letter++)+'a';
				}
				cout << output[tag];
			} else {
				cout << '0';
			}
		}
		cout << '\n';
	}

	return 0;
}
