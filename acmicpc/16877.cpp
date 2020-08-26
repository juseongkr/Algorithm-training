#include <iostream>
#include <vector>
using namespace std;
#define MAX 3000001

int n, p, ans;
int dp[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	vector<int> fibo = {1, 1};
	for (int i=2; ; ++i) {
		int f = fibo[i-2] + fibo[i-1];
		if (f > MAX)
			break;
		fibo.push_back(f);
	}

	for (int i=1; i<MAX; ++i) {
		vector<int> check(51);
		for (int j=0; j<fibo.size(); ++j) {
			int f = fibo[j];
			if (i < f)
				break;
			check[dp[i-f]] = 1;
		}

		for (int j=0; ; ++j) {
			if (check[j] == 0) {
				dp[i] = j;
				break;
			}
		}
	}

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> p;
		ans ^= dp[p];
	}

	if (ans)
		cout << "koosaga\n";
	else
		cout << "cubelover\n";

	return 0;
}
