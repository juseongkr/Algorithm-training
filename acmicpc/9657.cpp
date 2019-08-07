#include <iostream>
using namespace std;
#define MAX 1001

bool dp[MAX];

int main()
{
	int n;

	cin >> n;
	for (int i=1; i<=n; ++i) {
		if (!dp[i-1])
			dp[i] = true;

		if (i-3 >= 0 && !dp[i-3])
			dp[i] = true;

		if (i-4 >= 0 && !dp[i-4])
			dp[i] = true;
	}

	if (dp[n])
		cout << "SK\n";
	else
		cout << "CY\n";

	return 0;
}
