#include <iostream>
using namespace std;

int dp[41];

int fibonacci(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;

	if (dp[n] == 0) {
		dp[n] = fibonacci(n-1) + fibonacci(n-2);
		return dp[n];
	} else {
		return dp[n];
	}
}

int main()
{
	int num, n;
	dp[0] = 0;
	dp[1] = 1;

	cin >> num;
	for (int i=0; i<num; ++i) {
		cin >> n;
	
		if (n >= 2)
			fibonacci(n);
		
		if (n == 0)
			cout << "1 0\n";
		else		
			cout << dp[n-1] << " " << dp[n] << '\n';
	}

	return 0;
}
