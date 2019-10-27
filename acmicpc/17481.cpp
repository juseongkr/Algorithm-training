#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int MAX = 10001;

int n, m, k;
vector<int> graph[MAX];
int A[MAX], B[MAX], visit[MAX];
map<string, int> mp;
string s;

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
	for (int i=0; i<=n; ++i) {
		fill(visit, visit+MAX, 0);
		if (dfs(i))
			ret++;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> s;
		mp[s] = i;
	}

	for (int i=0; i<n; ++i) {
		cin >> k;
		for (int j=0; j<k; ++j) {
			cin >> s;
			graph[i].push_back(mp[s]);
		}
	}

	int ans = match();
	if (ans == n) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
		cout << ans << '\n';
	}

	return 0;
}
