#include <iostream>
#include <cstring>
using namespace std;
#define MAX 21

int dp[MAX][MAX][MAX];
int a, b, c;

int w(int a, int b, int c)
{
	if (a <= 0 or b <= 0 or c <= 0)
		return 1;

	if (a >= MAX or b >= MAX or c >= MAX)
		return w(20, 20, 20);

	if (dp[a][b][c] != -1)
		return dp[a][b][c];

	if (a < b and b < c)
		return dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
	else
		return dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main()
{
	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;

		memset(dp, -1, sizeof(dp));
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
	}

	return 0;
}
