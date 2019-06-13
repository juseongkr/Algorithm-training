#include <iostream>
#include <climits>
using namespace std;
#define MAX 6

int go(int a, int b, char o)
{
	if (o == '+')
		return a + b;
	else if (o == '-')
		return a - b;
	else
		return a * b;
}

int main()
{
	int Max[MAX][MAX], Min[MAX][MAX];
	char map[MAX][MAX];
	int n;

	cin >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> map[i][j];
			Max[i][j] = INT_MIN;
			Min[i][j] = INT_MAX;
		}
	}

	Min[0][0] = Max[0][0] = map[0][0]-'0';
	for (int i=0; i<n; ++i) {
		for (int j=i%2; j<n; j+=2) {
			if (i >= 2) {
				int x = go(Max[i-2][j], map[i][j]-'0', map[i-1][j]);
				int y = go(Min[i-2][j], map[i][j]-'0', map[i-1][j]);
				Max[i][j] = max(Max[i][j], x);
				Min[i][j] = min(Min[i][j], y);
			}
			if (j >= 2) {
				int x = go(Max[i][j-2], map[i][j]-'0', map[i][j-1]);
				int y = go(Min[i][j-2], map[i][j]-'0', map[i][j-1]);
				Max[i][j] = max(Max[i][j], x);
				Min[i][j] = min(Min[i][j], y);
			}
			if (i >= 1 && j >= 1) {
				int x = go(Max[i-1][j-1], map[i][j]-'0', map[i-1][j]);
				int y = go(Max[i-1][j-1], map[i][j]-'0', map[i][j-1]);
				int z = go(Min[i-1][j-1], map[i][j]-'0', map[i-1][j]);
				int r = go(Min[i-1][j-1], map[i][j]-'0', map[i][j-1]);
				Max[i][j] = max(Max[i][j], max(x, y));
				Min[i][j] = min(Min[i][j], min(z, r));
			}
		}
	}
	cout << Max[n-1][n-1] << " " << Min[n-1][n-1] << '\n';

	return 0;
}
