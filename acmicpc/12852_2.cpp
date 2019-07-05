#include <iostream>
using namespace std;
#define MAX 1000001

int dp[MAX], p[MAX];

int main()
{
	int n;

	cin >> n;
	for (int i=2; i<=n; ++i) {
		dp[i] = dp[i-1]+1;
		p[i] = i-1;
		if (i % 2 == 0) {
			if (dp[i] > dp[i/2] + 1) {
				dp[i] = dp[i/2] + 1;
				p[i] = i/2;
			}
		}
		if (i % 3 == 0) {
			if (dp[i] > dp[i/3] + 1) {
				dp[i] = dp[i/3] + 1;
				p[i] = i/3;
			}
		}
	}

	cout << dp[n] << '\n';
	for (int i=n; i!=0; i=p[i])
		cout << i << " ";
	cout << '\n';

	return 0;
}
