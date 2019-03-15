#include <iostream>
using namespace std;

int main()
{
	int tri[501][501], dp[501][501];
	int num, max_val = 0;

	cin >> num;

	for (int i=0; i<num; ++i)
		for (int j=0; j<=i; ++j)
			cin >> tri[i][j];
	
	dp[0][0] = tri[0][0];
	dp[1][0] = tri[0][0] + tri[1][0];
	dp[1][1] = tri[0][0] + tri[1][1];

	for (int i=2; i<num; ++i)
		for (int j=0; j<num; ++j)
			dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j];

	for (int i=0; i<num; ++i)
		max_val = max(max_val, dp[num-1][i]);

	cout << max_val << '\n';
	
	return 0;
}
