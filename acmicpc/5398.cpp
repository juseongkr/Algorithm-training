#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 501

int n, m;
vector<int> graph[MAX];
int A[MAX], B[MAX], visit[MAX];

bool dfs(int a)
{
	visit[a] = 1;
	for (int i=0; i<graph[a].size(); ++i) {
		int b = graph[a][i];
		if (B[b] == -1 || (!visit[B[b]] && dfs(B[b]))) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int match()
{
	int ret = 0;
	fill(A, A+MAX, -1);
	fill(B, B+MAX, -1);
	for (int i=0; i<n; ++i) {
		fill(visit, visit+MAX, 0);
		if (dfs(i))
			ret++;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, x, y;
	string s;
	
	cin >> t;
	while (t--) {
		cin >> n >> m;
		int word[2001][2001];
		char map[2001][2001] = {0};
		for (int i=0; i<n; ++i) {
			cin >> x >> y >> s;
			for (int j=0; j<s.length(); ++j) {
				map[y][x+j] = s[j];
				word[y][x+j] = i;
			}
		}

		for (int i=0; i<m; ++i) {
			cin >> x >> y >> s;
			for (int j=0; j<s.length(); ++j) {
				if (map[y+j][x] && map[y+j][x] != s[j])
					graph[word[y+j][x]].push_back(i);
			}
		}
		cout << n + m - match() << '\n';

		for (int i=0; i<MAX; ++i)
			graph[i].clear();
	}
	return 0;
}
