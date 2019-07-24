#include <iostream>
using namespace std;
#define MAX 1001

int n, ans;
int check[MAX];
int num[4] = {1, 5, 10, 50};

void solve(int cur, int low, int val)
{
	if (cur == n) {
		if (!check[val]) {
			check[val] = 1;
			ans++;
		}
	} else {
		for (int i=low; i<4; ++i)
			solve(cur+1, i, val + num[i]);
	}
}

int main()
{
	cin >> n;

	solve(0, 0, 0);

	cout << ans << '\n';

	return 0;
}
