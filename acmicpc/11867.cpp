#include <iostream>
using namespace std;
#define MAX 101

bool arr[MAX][MAX], dp[MAX][MAX];

bool solve(int a, int b)
{
	if (arr[a][b])
		return dp[a][b];

	arr[a][b] = true;
	dp[a][b] = false;

	for (int i=1; i<=a; ++i)
		if (solve(i, a-i) == false)
			dp[a][b] = true;

	for (int i=1; i<=b; ++i)
		if (solve(i, b-i) == false)
			dp[a][b] = true;


	return dp[a][b];
}

int main()
{
	int n, m;
	arr[1][1] = true;
	dp[1][1] = false;
	cin >> n >> m;
	if (solve(n, m))
		cout << "A\n";
	else
		cout << "B\n";

	return 0;
}
