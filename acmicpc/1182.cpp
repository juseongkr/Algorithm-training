#include <iostream>
using namespace std;

int num[21];
int n, s, cnt = 0;

void solve(int pos, int val)
{
	if (val + num[pos] == s)
		cnt++;

	if (pos + 1 == n)
		return;

	solve(pos + 1, val);
	solve(pos + 1, val + num[pos]);
}

int main()
{
	cin >> n >> s;

	for (int i=0; i<n; ++i)
		cin >> num[i];

	solve(0, 0);

	cout << cnt << '\n';

	return 0;
}
