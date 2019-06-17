#include <iostream>
using namespace std;
#define MAX 101

int num[MAX][MAX];

int main()
{
	int x1, y1, x2, y2, ans = 0;

	for (int k=0; k<4; ++k) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i=x1; i<x2; ++i)
			for (int j=y1; j<y2; ++j)
				num[i][j]++;
	}

	for (int i=0; i<MAX; ++i)
		for (int j=0; j<MAX; ++j)
			if (num[i][j])
				ans++;

	cout << ans << '\n';

	return 0;
}
