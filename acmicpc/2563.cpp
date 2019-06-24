#include <iostream>
using namespace std;
#define MAX 101

int num[MAX][MAX], ans;

int main()
{
	int t, x, y;

	cin >> t;
	while (t--) {
		cin >> x >> y;
		for (int i=y+1; i<=y+10; ++i)
			for (int j=x+1; j<=x+10; ++j)
				num[i][j] = 1;
	}

	for (int i=1; i<MAX; ++i)
		for (int j=1; j<MAX; ++j)
			if (num[i][j])
				ans++;

	cout << ans << '\n';

	return 0;
}
