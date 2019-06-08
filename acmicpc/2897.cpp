#include <iostream>
using namespace std;
#define MAX 51

int ans[5];

int main()
{
	string s[MAX];
	int r, c;

	cin >> r >> c;
	for (int i=0; i<r; ++i)
		cin >> s[i];

	for (int i=0; i<r; ++i) {
		for (int j=0; j<c; ++j) {
			if (i < r-1 && j < c-1) {
				int cnt = 0;
				if (s[i][j] == '#' || s[i][j+1] == '#' || s[i+1][j] == '#' || s[i+1][j+1] == '#')
					continue;

				if (s[i][j] == 'X')
					cnt++;
				if (s[i+1][j] == 'X')
					cnt++;
				if (s[i][j+1] == 'X')
					cnt++;
				if (s[i+1][j+1] == 'X')
					cnt++;
				ans[cnt]++;
			}
		}
	}
	for (int i=0; i<5; ++i)
		cout << ans[i] << '\n';

	return 0;
}
