#include <iostream>
using namespace std;
#define MAX 11
const int INF = 1e9+7;

int n, m, k, t, cnt, ans = INF;
int solve[MAX];
bool arr[MAX][MAX];
bool flag;

bool check()
{
	for (int i=0; i<n; ++i)
		if (solve[i] == 0)
			return false;
	return true;
}

void dfs(int x)
{
	cnt++;
	for (int i=0; i<n; ++i)
		if (arr[x][i])
			solve[i]++;

	if (check()) {
		ans = min(ans, cnt);
	} else {
		for (int i=x+1; i<m; ++i)
			dfs(i);
	}

	cnt--;
	for (int i=0; i<n; ++i)
		if (arr[x][i])
			solve[i]--;
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> k;
		for (int j=0; j<k; ++j) {
			cin >> t;
			arr[i][t-1] = 1;
		}
	}

	flag = false;
	for (int i=0; i<n; ++i) {
		cnt = 0;
		dfs(i);
	}

	if (ans != INF)
		cout << ans << '\n';
	else
		cout << "-1\n";

	return 0;
}
