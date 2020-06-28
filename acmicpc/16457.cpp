#include <iostream>
using namespace std;

int n, m, k;
int key[101][11];
bool visit[21];

bool check(int i)
{
	for (int j=0; j<k; ++j)
		if (!visit[key[i][j]])
			return false;
	return true;
}

int solve(int cur, int cnt)
{
	if (n-cnt > 2*n-cur)
		return 0;

	int ret = 0;
	if (cur == n*2) {
		for (int i=0; i<m; ++i)
			if (check(i))
				ret++;
		return ret;
	}

	ret = solve(cur+1, cnt);
	if (cnt < n) {
		visit[cur] = 1;
		ret = max(ret, solve(cur+1, cnt+1));
		visit[cur] = 0;
	}

	return ret;
}

int main()
{
	cin >> n >> m >> k;
	for (int i=0; i<m; ++i) {
		for (int j=0; j<k; ++j) {
			cin >> key[i][j];
			key[i][j]--;
		}
	}

	cout << solve(0, 0) << '\n';

	return 0;
}
