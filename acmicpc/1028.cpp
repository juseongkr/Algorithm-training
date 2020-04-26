#include <iostream>
using namespace std;
#define MAX 751

int r, c;
string s[MAX];
int RD[MAX][MAX], LD[MAX][MAX];

int main()
{
	cin >> r >> c;
	for (int i=0; i<r; ++i)
		cin >> s[i];

	for (int i=1; i<=r; ++i)
		for (int j=1; j<=c; ++j)
			RD[i][j] = LD[i][j] = s[i-1][j-1]-'0';

	for (int i=r-1; i>=1; i--) {
		for (int j=1; j<=c; ++j) {
			RD[i][j] *= RD[i+1][j+1] + 1;
			LD[i][j] *= LD[i+1][j-1] + 1;
		}
	}

	int ans = 0;
	for (int i=1; i<=r; ++i)
		for (int j=1; j<=c; ++j)
			for (int k=LD[i][j]-1; k>=ans; k--)
				if (RD[i][j] >= k+1 && RD[i+k][j-k] >= k+1 && LD[i+k][j+k] >= k+1)
					ans = k+1;

	cout << ans << '\n';

	return 0;
}
