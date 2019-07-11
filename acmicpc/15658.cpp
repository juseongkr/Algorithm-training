#include <iostream>
using namespace std;

int n;
int num[12], op[4];
int max_val = -1000000001, min_val = 1000000001;

void dfs(int plus, int minus, int mul, int div, int cnt, int sum)
{
	if (cnt == n) {
		max_val = max(max_val, sum);
		min_val = min(min_val, sum);
		return;
	}

	if (plus > 0)
		dfs(plus-1, minus, mul, div, cnt+1, sum + num[cnt]);
	if (minus > 0)
		dfs(plus, minus-1, mul, div, cnt+1, sum - num[cnt]);
	if (mul > 0)
		dfs(plus, minus, mul-1, div, cnt+1, sum * num[cnt]);
	if (div > 0)
		dfs(plus, minus, mul, div-1, cnt+1, sum / num[cnt]);
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	for (int i=0; i<4; ++i)
		cin >> op[i];

	dfs(op[0], op[1], op[2], op[3], 1, num[0]);

	cout << max_val << '\n' << min_val << '\n';

	return 0;
}
