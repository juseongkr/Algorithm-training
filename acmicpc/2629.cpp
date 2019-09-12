#include <iostream>
using namespace std;

int n, m;
int wei[31], ball[8];
bool dp[31][501*31];

void solve(int c, int w)
{
	if (c > n || dp[c][w])
		return;

	dp[c][w] = 1;
	solve(c+1, w);
	solve(c+1, w + wei[c]);
	solve(c+1, abs(w - wei[c]));
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> wei[i];

	cin >> m;
	for (int i=0; i<m; ++i)
		cin >> ball[i];

	solve(0, 0);
	for (int i=0; i<m; ++i) {
		if (dp[n][ball[i]])
			cout << "Y ";
		else
			cout << "N ";
	}

	return 0;
}
