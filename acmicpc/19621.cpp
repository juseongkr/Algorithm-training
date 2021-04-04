#include <iostream>
using namespace std;
#define MAX 26

int n, x, y, ans;
int z[MAX];

void solve(int cur, int sum)
{
	if (cur >= n) {
		ans = max(ans, sum);
		return;
	}

	solve(cur+1, sum);
	solve(cur+2, sum + z[cur]);
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> x >> y >> z[i];

	solve(0, 0);

	cout << ans << '\n';

	return 0;
}
