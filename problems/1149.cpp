#include <iostream>
using namespace std;

int main()
{	
	int color[1005][3], dp[1005][3];
	int num;
	
	cin >> num;

	for (int i=0; i<num; ++i)
		for (int j=0; j<3; ++j)
			cin >> color[i][j];
	
	dp[0][0] = color[0][0];
	dp[0][1] = color[0][1];
	dp[0][2] = color[0][2];

	for (int i=1; i<num; ++i) {
		dp[i][0] = color[i][0] + min(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = color[i][1] + min(dp[i-1][0], dp[i-1][2]);
		dp[i][2] = color[i][2] + min(dp[i-1][0], dp[i-1][1]);
	}

	cout << min(min(dp[num-1][0], dp[num-1][1]), dp[num-1][2]) << '\n';

	return 0;
}
