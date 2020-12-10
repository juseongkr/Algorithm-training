#include <iostream>
using namespace std;
#define MAX (1 << 11)

int k, idx;
int num[MAX], ans[MAX];

void solve(int cur, int dep)
{
	if (dep == k) {
		ans[cur] = num[idx++];
		return;
	}

	solve(cur*2, dep+1);
	ans[cur] = num[idx++];
	solve(cur*2+1, dep+1);
}

int main()
{
	cin >> k;
	for (int i=0; i<(1 << k)-1; ++i)
		cin >> num[i];

	solve(1, 1);
	idx = 1;
	for (int i=0; i<k; ++i) {
		for (int j=0; j<(1 << i); ++j)
			cout << ans[idx++] << ' ';
		cout << '\n';
	}

	return 0;
}
