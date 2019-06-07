#include <iostream>
#include <vector>
using namespace std;
#define MAX 41

int dp[MAX][MAX];

int main()
{
	vector<char> ans;
	string a, b;

	cin >> a >> b;
	for (int i=1; i<=a.length(); ++i) {
		for (int j=1; j<=b.length(); ++j) {
			if (a[i-1] == b[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	int i = a.length();
	int j = b.length();
	while (i && j) {
		if (dp[i][j] == dp[i-1][j]) {
			i--;
		} else if (dp[i][j] == dp[i][j-1]) {
			j--;
		} else {
			ans.push_back(a[i-1]);
			i--;
			j--;
		}
	}
	for (int i=ans.size()-1; i>=0; i--)
		cout << ans[i];

	return 0;
}
