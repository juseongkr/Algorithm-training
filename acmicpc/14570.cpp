#include <iostream>
using namespace std;
#define MAX 200001

int n, x, y;
long long k;
int L[MAX], R[MAX];

void dfs(int cur, long long cnt)
{
	if (L[cur] == -1 && R[cur] == -1) {
		cout << cur << '\n';
		exit(0);
	}

	if (L[cur] == -1) {
		dfs(R[cur], cnt);
	} else if (R[cur] == -1) {
		dfs(L[cur], cnt);
	} else {
		if (cnt % 2)
			dfs(R[cur], cnt/2);
		else
			dfs(L[cur], cnt/2);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	fill(L, L+MAX, -1);
	fill(R, R+MAX, -1);
	for (int i=1; i<=n; ++i) {
		cin >> x >> y;
		if (x != -1)
			L[i] = x;
		if (y != -1)
			R[i] = y;
	}

	cin >> k;
	dfs(1, k-1);

	return 0;
}
