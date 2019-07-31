#include <iostream>
using namespace std;
#define MAX 51

char arr[MAX][5][7];

int main()
{
	pair<int, int> ans;
	int n;

	cin >> n;
	for (int k=0; k<n; ++k)
		for (int i=0; i<5; ++i)
			for (int j=0; j<7; ++j)
				cin >> arr[k][i][j];

	int mi = 1e9+7;
	for (int i=0; i<n; ++i) {
		for (int j=i+1; j<n; ++j) {
			int cnt = 0;
			for (int y=0; y<5; ++y) {
				for (int x=0; x<7; ++x) {
					if (arr[i][y][x] != arr[j][y][x])
						cnt++;
				}
			}
			if (mi > cnt) {
				mi = cnt;
				ans = {i+1, j+1};
			}
		}
	}
	cout << ans.first << " " << ans.second << '\n';

	return 0;
}
