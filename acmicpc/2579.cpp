#include <iostream>
using namespace std;
int step[301], dp[301];

int main()
{
	int num;
	cin >> num;

	for (int i=1; i<=num; ++i)
		cin >> step[i];
	
	dp[1] = step[1];

	if (num >= 2)
		dp[2] = dp[1] + step[2];

	for (int i=3; i<=num; ++i) {
		dp[i] = max(dp[i-2] + step[i], dp[i-3] + step[i-1] + step[i]);
	}

	cout << dp[num] << '\n'; 
	
	return 0;
}
