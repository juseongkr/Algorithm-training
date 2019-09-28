#include <iostream>
using namespace std;

int num[5];
int ret, win, ans;

void solve(int idx, int cnt, int sum)
{
	if (cnt == 3) {
		ret = max(ret, sum % 10);
		return;
	}
	if (idx == 5)
		return;

	solve(idx+1, cnt+1, sum + num[idx]);
	solve(idx+1, cnt, sum);
}

int main()
{
	int n;

	cin >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<5; ++j)
			cin >> num[j];

		ret = 0;
		solve(0, 0, 0);
		if (ans <= ret) {
			ans = ret;
			win = i+1;
		}
	}
	cout << win << '\n';

	return 0;
}
