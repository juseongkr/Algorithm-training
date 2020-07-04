#include <iostream>
#include <cstring>
using namespace std;
#define MAX 25
const int INF = 1e9+7;

int n, m;
char s[MAX][MAX];
int dp[MAX*10][1<<10];
string map[MAX];

int solve(int pos, int bit)
{
	if (pos >= n*m)
		return 0;

	int &ret = dp[pos][bit];
	if (ret != -1)
		return ret;

	int x = pos / m;
	int y = pos % m;

	if (map[x][y] == '1') {
		ret = solve(pos+1, (bit >> 1)) + 1;
	} else {
		ret = solve(pos+1, (bit >> 1));
		if (!(bit & 1))
			ret = max(ret, solve(pos+1, (bit >> 1)) + 1);

		if (x != n-1 && y != m-1 && !(bit & 1) && !(bit & 2))
			if (map[x][y+1] == '.' && map[x+1][y] == '.' && map[x+1][y+1] == '.')
				ret = max(ret, solve(pos+2, (bit >> 2) | (1 << (m-1)) | (1 << (m-2))) + 16);
	}

	return ret;
}

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> s[i];
	
	for (int j=0; j<m; ++j)
		for (int i=0; i<n; ++i)
			map[j] += s[i][j];

	swap(n, m);
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';

	return 0;
}
