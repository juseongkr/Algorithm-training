#include <iostream>
#include <vector>
using namespace std;
#define MAX 40001
#define MOD 123456789

int n;
vector<int> prime;
bool check[MAX];
int dp[MAX];

int main()
{
	fill(check+2, check+MAX, true);
	for (int i=2; i<=MAX; ++i) {
		if (check[i])
			prime.push_back(i);
		for (int j=i; j<=MAX; j+=i)
			check[j] = false;
	}

	cin >> n;
	dp[0] = 1;
	for (int i=0; i<prime.size(); ++i)
		for (int j=prime[i]; j<=n; ++j)
			dp[j] = (dp[j] + dp[j-prime[i]]) % MOD;
	cout << dp[n] << '\n';

	return 0;
}
